#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.58])
AC_INIT([helloWorlds], [1.0], [berryzplus@gmail.com])
AM_INIT_AUTOMAKE()

# Checks for programs.

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_ARG_WITH([hello],
  AS_HELP_STRING([--with-hello], [use hello (default is YES)]),
  [ac_cv_with_hello=$withval], [ac_cv_with_hello=yes])
if test $ac_cv_with_hello = yes; then
  AC_CONFIG_SUBDIRS([hello])
fi

AC_ARG_WITH([echo],
  AS_HELP_STRING([--with-echo], [use echo (default is YES)]),
  [ac_cv_with_echo=$withval], [ac_cv_with_echo=yes])
if test $ac_cv_with_echo = yes; then
  AC_CONFIG_SUBDIRS([echo])
fi

AC_ARG_WITH([hello++],
  AS_HELP_STRING([--with-hello++], [use hello++ (default is YES)]),
  [ac_cv_with_hello__=$withval], [ac_cv_with_hello__=yes])
if test $ac_cv_with_hello__ = yes; then
  AC_CONFIG_SUBDIRS([hello++])
fi

AC_ARG_WITH([echo++],
  AS_HELP_STRING([--with-echo++], [use echo++ (default is YES)]),
  [ac_cv_with_echo__=$withval], [ac_cv_with_echo__=yes])
if test $ac_cv_with_echo__ = yes; then
  AC_CONFIG_SUBDIRS([echo++])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
