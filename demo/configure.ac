dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.50])
AC_INIT([demo], [1.0], [bug-libtool@gnu.org])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([hello.c])
AC_CONFIG_MACRO_DIR([libltdl/m4])
AC_CONFIG_AUX_DIR([libltdl/config])

LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([dlopen win32-dll])
LTDL_INIT([convenience installable])

AM_INIT_AUTOMAKE([foreign])

## --------------------------- ##
## Libraries required by demo. ##
## --------------------------- ##
AC_CHECK_LIBM
AC_SUBST([LIBM])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
