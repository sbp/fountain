include $(top_srcdir)/snippets/create_am_macros.mk

#-------------------------------------------------------------------
#

# sources that must be made prior to compilation
BUILT_SOURCES		+= 

# extra files to add to the distribution
EXTRA_DIST              +=		\
			fountain.pod	\
			fountain.pod.in

# Any files make built
CLEANFILES		+= 

# Any files configure built
DISTCLEANFILES		+=

# Any files maintainer built(with autoconf, automake, etc)
MAINTAINERCLEANFILES	+= Makefile.in

#-------------------------------------------------------------------
# Snippets go after here, unless their docs say otherwise

dist_manl_MANS = fountain.l
POD_SFX = .pod
PODS = fountain

include $(top_srcdir)/snippets/prog_pod_subst.mk

