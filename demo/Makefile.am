## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS = -I libltdl/m4
SUBDIRS = libltdl

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool

# Build a libtool library, libhello.la for installation in libdir.
lib_LTLIBRARIES = libhello.la
libhello_la_SOURCES = hello.c foo.c
libhello_la_LIBADD = $(LIBM)
libhello_la_LDFLAGS = -module -version-info 3:12:1 -shared
libhello_la_LDFLAGS += -no-undefined


include_HEADERS = foo.h

bin_PROGRAMS = hell hell_static helldl

# Build hell from main.c and libhello.la
hell_SOURCES = main.c
hell_LDADD = libhello.la $(LIBLTDL)

# Create a statically linked version of hell.
hell_static_SOURCES = main.c
hell_static_LDADD = libhello.la
hell_static_LDFLAGS = -static

# Create a version of hell that does a preloaded dlopen.
helldl_SOURCES = dlmain.c
helldl_LDADD = $(LIBLTDL)
#helldl_LDFLAGS = -dlpreopen
#helldl_LDFLAGS = -export-dynamic -dlpreopen libhello.la
helldl_LDFLAGS = -export-dynamic -dlpreopen libhello.la
helldl_DEPENDENCIES = libhello.la
