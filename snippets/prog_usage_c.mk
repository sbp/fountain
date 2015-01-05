#============================================================================
# prog_usage_c.mk

# let VPATH take care of whether it's in $(top_srcdir)/docs
# or $(top_builddir)/docs
POD_SRC = ../docs/$(PACKAGE_NAME).pod 

include $(top_srcdir)/snippets/prog_usage_c_base.mk
