/* --8<--8<--8<--8<--
 *
 * Copyright (C) 2006 Smithsonian Astrophysical Observatory
 *
 * This file is part of fountain
 *
 * fountain is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * fountain is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the 
 *       Free Software Foundation, Inc. 
 *       51 Franklin Street, Fifth Floor
 *       Boston, MA  02110-1301, USA
 *
 * -->8-->8-->8-->8-- */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/select.h>

#include <tracefct/exiterrvals.h>
#include <tracefct/tracefct.h>

#include "main.h"

void process( Options options )
{
  char *buffer = calloc( options.buffer_size, sizeof( char ) );

  int i;
  int maxfd    = options.commands[(options.noutput)-1].fd;
  int ready    = 0;
  ssize_t nr   = 0;
  int npackets = 0;
  int neagains = 0;

  fd_set fds, writefds;
  FD_ZERO( &fds );
  for ( i = 0; i < options.noutput; i++ )
    FD_SET( options.commands[i].fd, &fds );

  tf_enter( "process" );
  tf_assert( NULL != buffer );
  
  while ( ( nr = read( STDIN_FILENO, buffer, options.buffer_size*sizeof(char) ) ) > 0 )
  {
    size_t total_written = 0;

    for ( i = 0; i < options.noutput; i++ )
      options.commands[i].position = 0;

    if ( options.verbose )
      tf_message( "packet(%d) read\n", npackets );
    

    do
    {
      writefds = fds;

      ready = select( maxfd+1, NULL, &writefds, NULL, NULL );

      if ( -1 == ready )
        tf_exit( IO_ERR, "select returned error on packet(%d)", npackets );

      for ( i = 0; i < options.noutput; i++ )
      {
        size_t pos;

        if ( FD_ISSET( options.commands[i].fd, &writefds ) &&
             ( ( pos = options.commands[i].position ) != nr ) )
	{
          ssize_t nw = 0;

          if ( ( nw = write( options.commands[i].fd, buffer+pos, (nr-pos)*sizeof(char) ) ) < 0 && errno != EAGAIN )
	  {
            tf_exit( ExitERR_write, "error writing packet(%d) to `%s'",
                     npackets, options.commands[i].command );
	  }
          else if ( nw == -1 && errno == EAGAIN )
            neagains++;
          else
	  {
            if ( options.verbose )
              tf_message( "after %d EAGAIN's, wrote %d bytes in packet(%d) to process(%d): `%s'\n", neagains, nw, npackets, i, options.commands[i].command );

            options.commands[i].position += nw;
            total_written += nw;
            neagains = 0;
	  }
	}
      }
    } while ( total_written != nr * options.noutput );

    npackets++;
  }

  /* free pipes */
  for ( i = 0; i < options.noutput; i++ )
    pc_free( options.commands+i );


  if ( nr < 0 )
    tf_exit( ExitERR_read, "error reading from stdin" );
  
  free( buffer );

  tf_leave( );
}
