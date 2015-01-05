#ifndef MAIN_H
#define MAIN_H

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

typedef struct 
{
  char *command;
  FILE *stream;
  int  fd;
  int  position;
} PipeCommand;

typedef struct
{
  PipeCommand *commands;
  int         noutput;
  size_t      buffer_size;
  int         help;
  int         verbose;
  int         version;
} Options;


Options goption( int argc, char *argv[], Options options );
void process( Options options );

void pc_free( PipeCommand *pc );
void pc_set_command( PipeCommand *pc, const char *cmd );
void pc_set_stdout( PipeCommand *pc );


#endif /* !MAIN_H */
