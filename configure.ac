# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([main], [1.0], [joaqimpla@gmail.com])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

m4_include([m4/m4_ax_cxx_compile_stdcxx.m4])
#m4_include([m4/m4_ax_cxx_compile_stdcxx_11.m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

AX_CXX_COMPILE_STDCXX(14, [noext], [mandatory])


if test x$ac_success = xno; then
	if test x$CXX = xg++; then
		GCC_VERSION_MAJOR=$(g++ -dumpversion | cut -d'.' -f1)
		GCC_VERSION_MINOR=$(g++ -dumpversion | cut -d'.' -f2)

		if test "$GCC_VERSION_MAJOR" -ge 7; then
			if test "$GCC_VERSION_MINOR" -ge 0; then
				ac_success=yes
				CXXFLAGS="-std=c++0x"
				HAVE_CXX11=1
			fi
		fi
	fi
fi

# Conditionals
AC_ARG_ENABLE(debug,
	      AS_HELP_STRING([--enable-debug], [enable debugging, default: yes]),
	      [case "${enableval}" in
	       yes) debug=true ;;
	       no)  debug=false ;;
	       *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
       esac],
       [debug=false])

AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")
#AC_DEFINE_UNQUOTED([DEBUG], ["$debug"])

# Checks for libraries.
AM_PROG_AR
LT_INIT
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL(libtool)

# Checks for header files.

AC_CHECK_HEADERS([fcntl.h limits.h stdint.h string.h sys/time.h termios.h unistd.h])
#AC_CHECK_HEADERS([argtable2.h], [], AC_MSG_ERROR([Could not find argtable2.h. Try $ ./configure CXXFLAGS='-Iyour-argtable2-include-path]))


# Finds Dependencies
#PKG_CHECK_MODULES([DEPS], [glib-2.0 >= 2.24.1] [opencv] [lept] [tesseract] )

#CPPFLAGS += x_cxxflags x_includes x_ldflags x_libs
#-lglfw3 -pthread -ldl -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11
#PKG_CHECK_MODULES([DEPS], [opencv-3.4.1-2 >= 3])
#PKG_CHECK_MODULES([DEPS], [glew-2.1.0])
#PKG_CHECK_MODULES([DEPS], [glut-3.0.0])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Output Makefile files.
AC_CONFIG_FILES([Makefile 
		 src/Makefile
		 ])
#doc/Makefile
#examples/Makefile
#man/Makefile
#scripts/Makefile
#tests/Makefile 

# third_party/repos/imgui/Makefile \
	AC_OUTPUT
