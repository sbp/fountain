include $(top_srcdir)/snippets/create_am_macros.mk

bin_PROGRAMS		= fountain

AM_CPPFLAGS		= $(fountain_CFLAGS)
LDADD			= $(fountain_LIBS)

fountain_SOURCES	= goption.c main.c pipecommand.c process.c usage.c
noinst_HEADERS		= main.h

#-------------------------------------------------------------------
#

# sources that must be made prior to compilation
BUILT_SOURCES		+= 

# extra files to add to the distribution
EXTRA_DIST              +=

# Any files make built
CLEANFILES		+= -fr SunWS_cache/

# Any files configure built
DISTCLEANFILES		+= config.cache

# Any files maintainer built(with autoconf, automake, etc)
MAINTAINERCLEANFILES	+= Makefile.in

#-------------------------------------------------------------------
# Snippets go after here, unless their docs say otherwise

include $(top_srcdir)/snippets/prog_usage_c.mk
