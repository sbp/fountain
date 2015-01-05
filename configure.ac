#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.57])

#---------------------------------------------------------
AC_INIT([fountain],[1.0.2],[http://jeeves.cfa.harvard.edu/bugzilla/],)
AM_INIT_AUTOMAKE([ check-news ])
AC_CONFIG_SRCDIR([src/main.h])
AC_CONFIG_HEADERS([config.h])

#---------------------------------------------------------
# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LIBTOOL

#---------------------------------------------------------
# Checks for libraries.
PKG_CHECK_MODULES([fountain],[tracefct])

AC_SUBST([fountain_CFLAGS])
AC_SUBST([fountain_LIBS])

#---------------------------------------------------------
# Checks for library functions.
AC_CONFIG_FILES([Makefile
		 src/Makefile
		 docs/Makefile
		])

#---------------------------------------------------------

AC_OUTPUT
