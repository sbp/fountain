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

#include <libgen.h>
#include <tracefct/tracefct.h>

#include "main.h"

#include "config.h"

int main( int argc, char **argv )
{
  Options options;
  argv[0] = basename( argv[0] );
  tf_init( argv[0], 0, 0 );

  /* set default options */
  options.noutput     = 0;
  options.buffer_size = 8192;
  options.commands    = NULL;
  options.help        = 0;
  options.verbose     = 0;
  options.version     = 0;

  options = goption( argc, argv, options );
  
  if ( options.version )
    printf( "%s %s\n", argv[0], VERSION );

  else if ( options.help )
    usage( );

  else
    process( options );

  return EXIT_SUCCESS;
}
