## Process this file with automake to produce Makefile.in

SUBDIRS = libltdl

ACLOCAL_AMFLAGS = -I libltdl/m4

# Build a executable for installation in bindir.
bin_PROGRAMS = hell hell_static helldl

# List headers for installation in includedir.
include_HEADERS = foo.h

# Build a libtool library, libhello.la for installation in libdir.
lib_LTLIBRARIES = libhello.la


# Build a libtool library libhello.la
libhello_la_SOURCES = hello.c foo.c
libhello_la_LDFLAGS = -module -shared
libhello_la_LDFLAGS += -version-info 3:12:1
libhello_la_LDFLAGS += -no-undefined
libhello_la_LIBADD = $(LIBM)

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
helldl_LDFLAGS = -export-dynamic -dlpreopen libhello.la
helldl_DEPENDENCIES = libhello.la

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool
