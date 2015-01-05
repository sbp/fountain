#============================================================================
# prog_pod_subst.mk - generate program documentation from POD.in input

# this snippet orchestrates the creation of PostScript,
# HTML, and UNIX section l man pages from POD input.
# see prog_pod_base.mk for more information.

# this snippet creates POD files from POD.in files by implementing
# the standard substitutions

# Prerequisites:
#	create_am_macros.mk

include $(top_srcdir)/snippets/substitute_config_variables.mk

%.pod : $(srcdir)/%.pod.in
	rm -f $@
	f=`basename $@` && $(do_subst) $(srcdir)/$$f.in > $@.tmp
	mv $@.tmp $@

# necessary for VPATH to get things right
POD_DIR = 

include $(top_srcdir)/snippets/prog_pod_base.mk

# make sure the generated file is distributed
EXTRA_DIST 		+= $(PODS:%=%$(POD_SFX))
