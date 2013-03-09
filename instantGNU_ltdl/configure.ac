dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([instantGNU_ltdl], [1.11], [berryzplus@gmail.com])

AC_CONFIG_HEADERS([include/config.h])
AC_CONFIG_SRCDIR([main/main.c])
AC_CONFIG_MACRO_DIR([libltdl/m4])
AC_CONFIG_AUX_DIR([libltdl/config])

LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([dlopen win32-dll])
LTDL_INIT([convenience installable])

AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CONFIG_FILES([Makefile main/Makefile libraries/Makefile])
AC_OUTPUT
