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

#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

#include <tracefct/tracefct.h>
#include <tracefct/exiterrvals.h>

#include "main.h"

extern char *optarg;
extern int optind, opterr, optopt;

Options
goption( int argc, char *argv[], Options options )
{
  int ii;
  int c;

  tf_enter( "goption" );

  while ( 1 )
  {
    c = getopt( argc, argv, "bc:hsvV" );
    
    /* Detect the end of the options. */
    if ( c == -1 )
      break;
    
    switch ( c )
    {
    case 'b':
      if ( optind == argc || ! isdigit( argv[optind][0] ) )
        tf_exit( ExitERR_illegalArg, "option -b requires a numeric argument" );

      options.buffer_size = atoi( argv[optind++] );
      break;

    case 'h':
      options.help = 1;      
      break;

    case 's':
      options.commands = realloc( options.commands, 
			      (options.noutput+1)*sizeof(PipeCommand) );
      tf_assert( NULL != options.commands );

      pc_set_stdout( &options.commands[(options.noutput++)] );
      break;
      
    case 'v':
      options.verbose = 1;
      break;

    case 'V':
      options.version = 1;
      break;

    case '?':
      tf_exit( ExitERR_illegalArg, "unknown option `-%c'", optopt );
      
    default:
      tf_exit( ExitERR_misc, "unforeseen error" );
    }
  }

  for (ii = optind ; ii < argc ; ii++ )
  {
      options.commands = realloc( options.commands, 
			      (options.noutput+1)*sizeof(PipeCommand) );
      tf_assert( NULL != options.commands );

      pc_set_command( &options.commands[(options.noutput++)], argv[ii] );
  }

  if ( ! ( options.help || options.version ) && 0 == options.noutput )
    tf_exit( ExitERR_illegalArg, "no `-c' output commands specified" );

  tf_leave( );

  return options;
}
