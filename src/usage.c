/* for popen on Solaris */
#ifdef SunOS
#  define __EXTENSIONS__
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#include "usage.h"
   
static const char usage_string[] =
{
  78, 65, 77, 69, 10, 
  32, 32, 32, 32, 102, 111, 117, 110, 116, 97, 105, 110, 32, 45, 32, 116, 97, 107, 101, 32, 97, 32, 115, 105, 110, 103, 108, 101, 32, 105, 110, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 32, 97, 110, 100, 32, 119, 114, 105, 116, 101, 32, 105, 116, 32, 116, 111, 32, 109, 117, 108, 116, 105, 112, 108, 101, 32, 111, 117, 116, 112, 117, 116, 10, 
  32, 32, 32, 32, 115, 116, 114, 101, 97, 109, 115, 46, 10, 
  10, 
  83, 89, 78, 79, 80, 83, 73, 83, 10, 
  32, 32, 32, 32, 102, 111, 117, 110, 116, 97, 105, 110, 32, 91, 45, 98, 32, 42, 98, 117, 102, 102, 101, 114, 32, 115, 105, 122, 101, 42, 32, 45, 104, 32, 45, 118, 32, 45, 86, 93, 32, 42, 99, 111, 109, 109, 97, 110, 100, 42, 32, 91, 42, 99, 111, 109, 109, 97, 110, 100, 42, 32, 46, 46, 46, 93, 10, 
  10, 
  68, 69, 83, 67, 82, 73, 80, 84, 73, 79, 78, 10, 
  32, 32, 32, 32, 102, 111, 117, 110, 116, 97, 105, 110, 32, 114, 101, 97, 100, 115, 32, 97, 32, 115, 105, 110, 103, 108, 101, 32, 105, 110, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 44, 32, 102, 114, 111, 109, 32, 116, 104, 101, 32, 115, 116, 97, 110, 100, 97, 114, 100, 32, 105, 110, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 44, 10, 
  32, 32, 32, 32, 97, 110, 100, 32, 119, 114, 105, 116, 101, 115, 32, 105, 116, 32, 116, 111, 32, 109, 117, 108, 116, 105, 112, 108, 101, 32, 99, 111, 109, 109, 97, 110, 100, 115, 46, 32, 73, 116, 32, 109, 97, 121, 32, 97, 108, 115, 111, 32, 119, 114, 105, 116, 101, 32, 116, 104, 101, 32, 100, 97, 116, 97, 32, 100, 105, 114, 101, 99, 116, 108, 121, 10, 
  32, 32, 32, 32, 116, 111, 32, 116, 104, 101, 32, 115, 116, 97, 110, 100, 97, 114, 100, 32, 111, 117, 116, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 32, 105, 102, 32, 116, 104, 101, 32, 45, 115, 32, 111, 112, 116, 105, 111, 110, 32, 105, 115, 32, 115, 112, 101, 99, 105, 102, 105, 101, 100, 46, 10, 
  10, 
  32, 32, 32, 32, 67, 111, 109, 109, 97, 110, 100, 32, 40, 105, 110, 99, 108, 117, 100, 105, 110, 103, 32, 97, 110, 121, 32, 97, 114, 103, 117, 109, 101, 110, 116, 115, 41, 32, 97, 114, 101, 32, 115, 112, 101, 99, 105, 102, 105, 101, 100, 32, 111, 110, 32, 116, 104, 101, 32, 99, 111, 109, 109, 97, 110, 100, 32, 108, 105, 110, 101, 32, 40, 97, 110, 100, 10, 
  32, 32, 32, 32, 109, 117, 115, 116, 32, 98, 101, 32, 113, 117, 111, 116, 101, 100, 32, 102, 114, 111, 109, 32, 116, 104, 101, 32, 115, 104, 101, 108, 108, 32, 105, 102, 32, 116, 104, 101, 121, 32, 99, 111, 110, 116, 97, 105, 110, 32, 119, 104, 105, 116, 101, 115, 112, 97, 99, 101, 41, 46, 32, 69, 97, 99, 104, 32, 99, 111, 109, 109, 97, 110, 100, 10, 
  32, 32, 32, 32, 119, 104, 105, 99, 104, 32, 119, 105, 108, 108, 32, 98, 101, 32, 112, 97, 115, 115, 101, 100, 32, 116, 104, 101, 32, 105, 110, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 32, 111, 110, 32, 105, 116, 115, 32, 115, 116, 97, 110, 100, 97, 114, 100, 32, 105, 110, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 46, 10, 
  10, 
  32, 32, 32, 32, 84, 111, 32, 105, 109, 112, 114, 111, 118, 101, 32, 111, 118, 101, 114, 97, 108, 108, 32, 112, 101, 114, 102, 111, 114, 109, 97, 110, 99, 101, 44, 32, 116, 104, 101, 32, 105, 110, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 32, 105, 115, 32, 119, 114, 105, 116, 116, 101, 110, 32, 117, 115, 105, 110, 103, 10, 
  32, 32, 32, 32, 110, 111, 110, 45, 98, 108, 111, 99, 107, 105, 110, 103, 32, 73, 47, 79, 32, 116, 111, 32, 101, 97, 99, 104, 32, 99, 111, 109, 109, 97, 110, 100, 46, 32, 84, 104, 101, 32, 115, 105, 122, 101, 32, 111, 102, 32, 116, 104, 101, 32, 98, 117, 102, 102, 101, 114, 32, 117, 115, 101, 100, 32, 116, 111, 32, 115, 116, 111, 114, 101, 10, 
  32, 32, 32, 32, 116, 104, 101, 32, 105, 110, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 32, 109, 97, 121, 32, 98, 101, 32, 115, 112, 101, 99, 102, 105, 101, 100, 32, 119, 105, 116, 104, 32, 116, 104, 101, 32, 45, 98, 32, 111, 112, 116, 105, 111, 110, 46, 10, 
  10, 
  79, 80, 84, 73, 79, 78, 83, 10, 
  32, 32, 32, 32, 45, 98, 32, 42, 98, 117, 102, 102, 101, 114, 32, 115, 105, 122, 101, 42, 10, 
  32, 32, 32, 32, 32, 32, 32, 32, 84, 104, 101, 32, 115, 105, 122, 101, 32, 111, 102, 32, 116, 104, 101, 32, 98, 117, 102, 102, 101, 114, 32, 40, 105, 110, 32, 98, 121, 116, 101, 115, 41, 32, 117, 115, 101, 100, 32, 116, 111, 32, 116, 114, 97, 110, 115, 102, 101, 114, 32, 116, 104, 101, 32, 105, 110, 112, 117, 116, 32, 115, 116, 114, 101, 97, 109, 46, 10, 
  32, 32, 32, 32, 32, 32, 32, 32, 73, 116, 32, 100, 101, 102, 97, 117, 108, 116, 115, 32, 116, 111, 32, 56, 49, 57, 50, 32, 98, 121, 116, 101, 115, 46, 10, 
  10, 
  32, 32, 32, 32, 45, 104, 32, 32, 79, 117, 116, 112, 117, 116, 32, 104, 101, 108, 112, 46, 10, 
  10, 
  32, 32, 32, 32, 45, 115, 32, 32, 73, 110, 32, 97, 100, 100, 105, 116, 105, 111, 110, 32, 116, 111, 32, 119, 114, 105, 116, 105, 110, 103, 32, 116, 111, 32, 116, 104, 101, 32, 99, 111, 109, 109, 97, 110, 100, 115, 32, 103, 105, 118, 101, 110, 32, 98, 121, 32, 45, 99, 44, 32, 97, 99, 116, 32, 97, 115, 32, 97, 32, 102, 105, 108, 116, 101, 114, 44, 10, 
  32, 32, 32, 32, 32, 32, 32, 32, 99, 111, 112, 121, 105, 110, 103, 32, 102, 114, 111, 109, 32, 115, 116, 97, 110, 100, 97, 114, 100, 32, 105, 110, 112, 117, 116, 32, 116, 111, 32, 115, 116, 97, 110, 100, 97, 114, 100, 32, 111, 117, 116, 112, 117, 116, 46, 10, 
  10, 
  32, 32, 32, 32, 45, 118, 32, 32, 66, 101, 32, 97, 32, 98, 105, 116, 32, 109, 111, 114, 101, 32, 118, 101, 114, 98, 111, 115, 101, 46, 10, 
  10, 
  32, 32, 32, 32, 45, 86, 32, 32, 79, 117, 116, 112, 117, 116, 32, 118, 101, 114, 115, 105, 111, 110, 32, 105, 110, 102, 111, 114, 109, 97, 116, 105, 111, 110, 46, 10, 
  10, 
  66, 85, 71, 83, 10, 
  32, 32, 32, 32, 78, 111, 110, 45, 98, 108, 111, 99, 107, 105, 110, 103, 32, 73, 47, 79, 32, 111, 110, 108, 121, 32, 119, 111, 114, 107, 115, 32, 102, 111, 114, 32, 98, 117, 102, 102, 101, 114, 115, 32, 108, 97, 114, 103, 101, 114, 32, 116, 104, 97, 110, 32, 49, 48, 50, 52, 48, 32, 98, 121, 116, 101, 115, 32, 117, 110, 100, 101, 114, 10, 
  32, 32, 32, 32, 73, 82, 73, 88, 32, 40, 119, 104, 101, 110, 32, 108, 97, 115, 116, 32, 116, 114, 105, 101, 100, 44, 32, 119, 104, 105, 99, 104, 32, 119, 97, 115, 32, 105, 110, 32, 49, 57, 57, 57, 41, 46, 32, 73, 102, 32, 98, 117, 102, 102, 101, 114, 32, 105, 115, 32, 108, 101, 115, 115, 32, 116, 104, 97, 110, 32, 49, 48, 50, 52, 48, 44, 10, 
  32, 32, 32, 32, 115, 101, 108, 101, 99, 116, 32, 119, 105, 108, 108, 32, 114, 101, 116, 117, 114, 110, 32, 98, 101, 102, 111, 114, 101, 32, 119, 114, 105, 116, 101, 32, 105, 115, 32, 114, 101, 97, 100, 121, 46, 32, 102, 111, 117, 110, 116, 97, 105, 110, 32, 119, 105, 108, 108, 32, 115, 116, 105, 108, 108, 32, 119, 111, 114, 107, 44, 32, 105, 116, 10, 
  32, 32, 32, 32, 119, 105, 108, 108, 32, 106, 117, 115, 116, 32, 119, 97, 115, 116, 101, 32, 116, 105, 109, 101, 32, 99, 97, 108, 108, 105, 110, 103, 32, 115, 101, 108, 101, 99, 116, 32, 97, 110, 100, 32, 119, 114, 105, 116, 101, 32, 109, 117, 108, 116, 105, 112, 108, 101, 32, 116, 105, 109, 101, 115, 32, 117, 110, 116, 105, 108, 32, 119, 114, 105, 116, 101, 10, 
  32, 32, 32, 32, 105, 115, 32, 97, 99, 116, 117, 97, 108, 108, 121, 32, 114, 101, 97, 100, 121, 46, 10, 
  10, 
  67, 79, 80, 89, 82, 73, 71, 72, 84, 32, 38, 32, 76, 73, 67, 69, 78, 83, 69, 10, 
  32, 32, 32, 32, 67, 111, 112, 121, 114, 105, 103, 104, 116, 32, 50, 48, 48, 54, 32, 83, 109, 105, 116, 104, 115, 111, 110, 105, 97, 110, 32, 65, 115, 116, 114, 111, 112, 104, 121, 115, 105, 99, 97, 108, 32, 79, 98, 115, 101, 114, 118, 97, 116, 111, 114, 121, 10, 
  10, 
  32, 32, 32, 32, 84, 104, 105, 115, 32, 115, 111, 102, 116, 119, 97, 114, 101, 32, 105, 115, 32, 114, 101, 108, 101, 97, 115, 101, 100, 32, 117, 110, 100, 101, 114, 32, 116, 104, 101, 32, 71, 78, 85, 32, 71, 101, 110, 101, 114, 97, 108, 32, 80, 117, 98, 108, 105, 99, 32, 76, 105, 99, 101, 110, 115, 101, 46, 32, 89, 111, 117, 32, 109, 97, 121, 10, 
  32, 32, 32, 32, 102, 105, 110, 100, 32, 97, 32, 99, 111, 112, 121, 32, 97, 116, 10, 
  10, 
  32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 104, 116, 116, 112, 58, 47, 47, 119, 119, 119, 46, 102, 115, 102, 46, 111, 114, 103, 47, 99, 111, 112, 121, 108, 101, 102, 116, 47, 103, 112, 108, 46, 104, 116, 109, 108, 10, 
  10, 
  86, 69, 82, 83, 73, 79, 78, 10, 
  32, 32, 32, 32, 84, 104, 105, 115, 32, 100, 111, 99, 117, 109, 101, 110, 116, 115, 32, 118, 101, 114, 115, 105, 111, 110, 32, 49, 46, 48, 46, 50, 32, 111, 102, 32, 102, 111, 117, 110, 116, 97, 105, 110, 46, 10, 
  10, 
  65, 85, 84, 72, 79, 82, 10, 
  32, 32, 32, 32, 68, 46, 32, 74, 101, 114, 105, 117, 115, 10, 
  10, 
  32, 32, 32, 32, 77, 46, 32, 84, 105, 98, 98, 101, 116, 116, 115, 10, 
  10, 
 0
};
  

int
usage( void )
{
  const char *pager;
  FILE *pipe;

  if ( ! isatty( STDOUT_FILENO ) )
    fputs( usage_string, stdout );
  else
  {
    if ( NULL == ( pager = getenv( "PAGER" )) )
      pager = "more";

    if ( NULL == ( pipe = popen( pager, "w" ) ) )
      return 1;

    fputs( usage_string, pipe );
    pclose( pipe );
  }
  return 0;
}