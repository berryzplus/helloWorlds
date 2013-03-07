## Process this with automake to create Makefile.in

ACLOCAL_AMFLAGS = -I libltdl/m4
SUBDIRS = libltdl main libraries

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool
