## Process this file with automake to produce Makefile.in

# This segment added by Arthur Norman in a messy attempt to reduce
# trouble with autoconf and friend.

# The standard arrangment used by automake arranges to re-run aclocal,
# autoconf and automake if any of the files they generate are out of date.
# However proper behaviour there not only relies on autoconf being installed
# but sometimes on the correct version being installed. The replacement
# logic here deals with that by running my own script "autogen.sh"
# when anything needs updating. That will reconfigure using whatever
# version of autoconf is available locally, and if none is it will
# just use "touch" to reset time-stamps on files so that the ordering
# appears reasonable.

# The rules here are arranged to chain so that configure is only
# considered after aclocal.m4 has been dealt with and Makefile.in only after
# that. This is trying to follow the guidance given re "Multiple Outputs"
# in the automake manual so that even when a parallel make is used
# autogen.sh will only end up called once. However I found that (for
# reasons I do not understand so far) there was a tendancy for autogen.sh
# to get called twice. I have put what I think ought to be redundant extra
# code that  means that whena recipe is called it does a further check
# to see if it is actually needed, and that sorts things out. It may be that
# the issues I observed are to do with the very special treatment that
# make gives to the re-creation of Makefile and the files that it is
# derived from.

$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	@if test $(ACLOCAL_M4) -ot $(top_srcdir)/configure.ac; \
	then \
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake $(ACLOCAL_M4) ; \
	fi

$(top_srcdir)/configure:  $(am__configure_deps) $(ACLOCAL_M4)
	@if test $(top_srcdir)/configure -ot $(top_srcdir)/configure.ac || \
	   test $(top_srcdir)/configure -ot $(ACLOCAL_M4) ; \
	then \
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake configure ; \
        fi

$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps) \
		$(top_srcdir)/configure
	@if test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure.ac || \
	   test $(srcdir)/Makefile.in -ot $(ACLOCAL_M4) || \
	   test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure || \
	   test $(srcdir)/Makefile.in -ot $(srcdir)/Makefile.am ; \
	then \
	  $(top_srcdir)/../../autogen.sh ; \
	else echo Redundant attempt to remake Makefile.in ; \
	fi



noinst_PROGRAMS	= \
	expression \
	dctest \
	codecs \
	dialog \
	ControlPanel \
	groupbox \
	scribble \
	wizard \
	layout \
	rex \
	table \
	memmap \
	minheritance \
	bitmapviewer \
	imageviewer \
	button \
	datatarget \
	dirlist \
	foursplit \
	header \
	hello \
	hello2 \
	iconlist \
	image \
	mditest \
	shutter \
	splitter \
	switcher \
	tabbook \
	ratio

expression_SOURCES      = expression.cpp
wizard_SOURCES	        = wizard.cpp
rex_SOURCES	        = rex.cpp
layout_SOURCES	        = layout.cpp
minheritance_SOURCES	= minheritance.cpp
memmap_SOURCES	        = memmap.cpp
mditest_SOURCES		= mditest.cpp
table_SOURCES		= table.cpp
groupbox_SOURCES	= groupbox.cpp
foursplit_SOURCES	= foursplit.cpp
datatarget_SOURCES	= datatarget.cpp
bitmapviewer_SOURCES	= bitmapviewer.cpp
imageviewer_SOURCES	= imageviewer.cpp
scribble_SOURCES	= scribble.cpp
splitter_SOURCES	= splitter.cpp
shutter_SOURCES		= shutter.cpp
image_SOURCES		= image.cpp
header_SOURCES		= header.cpp
hello_SOURCES		= hello.cpp
hello2_SOURCES		= hello2.cpp
switcher_SOURCES	= switcher.cpp
iconlist_SOURCES	= iconlist.cpp
tabbook_SOURCES		= tabbook.cpp
ratio_SOURCES		= ratio.cpp
dialog_SOURCES		= dialog.cpp
dirlist_SOURCES		= dirlist.cpp
button_SOURCES		= button.cpp
codecs_SOURCES		= codecs.cpp
dctest_SOURCES		= dctest.cpp dippy.h
ControlPanel_SOURCES    = ControlPanel.cpp controlpanelicon.h

# end of Makefile.am


