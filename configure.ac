#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([itc-benchmarks], [1.0], [https://github.com/regehr/itc-benchmarks/issues])
AC_CONFIG_SRCDIR([01.w_Defects/memory_leak.c])
AM_INIT_AUTOMAKE
AC_CONFIG_FILES([
Makefile
01.w_Defects/Makefile
02.wo_Defects/Makefile
04.wo_Defects_Cpp/Makefile
03.w_Defects_Cpp/Makefile
])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([netinet/in.h stdlib.h string.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([floor memset pow socket])

AC_OUTPUT
