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

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <tracefct/tracefct.h>

#include "main.h"

void pc_free( PipeCommand *pc )
{
  if ( STDOUT_FILENO != pc->fd )
  {
    free( pc->command );
    pclose( pc->stream );
  }
}

void pc_set_command( PipeCommand *pc, const char *cmd )
{
  int flags;

  tf_enter( "pc_set_command" );

  pc->command = calloc( strlen(cmd) + 1, sizeof(char) );
  tf_assert( NULL != pc->command );
  
  strcpy( pc->command, cmd );

  pc->stream = popen( pc->command, "w" );  
  tf_assert( NULL != pc->stream );

  pc->fd = fileno( pc->stream );

  tf_assert( flags = fcntl( pc->fd, F_GETFL ) >= 0 );
  flags |= O_NONBLOCK;
  tf_assert( fcntl( pc->fd, F_SETFL, flags ) >= 0 );

  pc->position = 0;

  tf_leave( );
}


void pc_set_stdout( PipeCommand *pc )
{
  int flags;

  pc->command = NULL;
  
  pc->fd = STDOUT_FILENO;

  tf_assert( flags = fcntl( pc->fd, F_GETFL ) >= 0 );
  flags |= O_NONBLOCK;
  tf_assert( fcntl( pc->fd, F_SETFL, flags ) >= 0 );

  pc->position = 0;
}
