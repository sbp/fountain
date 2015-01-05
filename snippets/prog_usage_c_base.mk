#============================================================================
# prog_usage_c_base.mk

# the caller must set POD_SRC to the name of the pod source file
# e.g.:

#  POD_SRC = $(top_srcdir)/docs/$(PACKAGE_NAME).pod 
#  POD_SRC = $(srcdir)/bin.pod 

usage.c : $(POD_SRC)
	pod2text < $(POD_SRC) | text2usage -pfx usage -inc > $@

MAINTAINERCLEANFILES	+= usage.c usage.h
EXTRA_DIST		+= usage.c usage.h
BUILT_SOURCES		+= usage.c
