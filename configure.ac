###############################################################################
# Created 2019-10-29 by Nick Stoughton <nstoughton@logitech.com>
#
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation; either version 2.1 of the License, or
# (at your option) any later version.
#
# This library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
# License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, write to the Free Software Foundation,
# Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
#
###############################################################################

AC_PREREQ([2.69])

# define an M4 macro to either get the value of some environment variable,
# or a default if the environment variable is not set / empty.
#
define([getenv_or],[m4_default(m4_esyscmd([printf "$1"]),[$2])])

m4_define([logi_major_version], [getenv_or($LOGI_MAJOR_VERSION,2)])
m4_define([logi_minor_version], [getenv_or($LOGI_MINOR_VERSION,0)])
m4_define([logi_micro_version], [getenv_or($LOGI_MICRO_VERSION,0)])
m4_define([logi_release],       [logi_major_version.logi_minor_version.logi_micro_version])


AC_INIT([libnfctag],
        [logi_release],
        [nstoughton@logitech.com])

AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AM_INIT_AUTOMAKE([-Wno-portability 1.14 foreign no-dist-gzip tar-ustar dist-xz
          subdir-objects])
AM_SILENT_RULES([yes])

# libtool -- ugh. but it works
AC_MSG_NOTICE([prepare libtool])

LT_PREREQ([2.2.6])
LT_INIT

AC_CONFIG_SRCDIR([src/SmeNfc.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# need at least C++11
AX_CXX_COMPILE_STDCXX_11

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdint.h string.h sys/ioctl.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_INT16_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_ARG_ENABLE([2k],
            [AS_HELP_STRING([--enable-2k],
                            [Chip type is 'NT3H1201' and not 'NT3H1101'])],
            AC_SUBST([NXPNCF_CHIP],[NT3H1201_DEF],[Chip type is 2k]),
            AC_SUBST([NXPNCF_CHIP],[NT3H1101_DEF],[Chip type is 1k]))

AC_ARG_WITH([i2c_bus],
            [AS_HELP_STRING([--with-i2c-bus=<bus-number>],
                            [I2C bus for chip (default 0)])],
            AC_SUBST([NXPNFC_BUS],[${with_i2c_bus}],[I2C bus to use]),
            AC_SUBST([NXPNFC_BUS],[0],[I2C bus to use]))

AC_ARG_WITH([i2c_address],
            [AS_HELP_STRING([--with-i2c-address=<addr>],
                            [I2C address for chip (default 0x55)])],
            AC_SUBST([NXPNFC_ADDRESS],[${with_i2c_address}],[I2C address]),
            AC_SUBST([NXPNFC_ADDRESS],[0x55],[I2C address]))

AC_SUBST([WARN_GENERATED],["Generated file, do not edit"])

AC_SUBST(LIB_NFCTAG_CXXFLAGS, '-I${top_srcdir}/src')
AC_SUBST(LIB_NFCTAG_LIBS, '${top_builddir}/src/libnfctag.la')

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 utils/Makefile
		 src/SmeNfcConfig.h
                 src/libnfctag.pc])
AC_OUTPUT

