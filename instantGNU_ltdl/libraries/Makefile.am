# make libShared.so as shared library ,and install to lib direcotry
# '*.la' is name convention for libtool command
lib_LTLIBRARIES = libShared.la

# sources of libShared.la
libShared_la_SOURCES = libShared.c

# LDFLAGS for libShared.la
libShared_la_LDFLAGS = -module -shared
libShared_la_LDFLAGS += -avoid-version
libShared_la_LDFLAGS += -no-undefined
