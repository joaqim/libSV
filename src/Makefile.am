AUTOMAKE_OPTIONS = subdir-objects #foreign
#ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)# $(AM_CXXFLAGS)
bin_PROGRAMS = main
main_SOURCES = main.cpp

main_LDADD = $(DEPS_LIBS) libSV.la
main_DEPENDENCIES =  libSV.la

main_CPPFLAGS = $(DEPS_CFLAGS) \
		-I../third_party/repos/spherical_voronoi_core

#noinst_LTLIBRARIES = libSV.la #libSphericalVoronoi
lib_LTLIBRARIES = libSV.la

#noinst_HEADERS =
include_HEADERS = \
	../third_party/repos/spherical_voronoi_core/svMath.h \
	../third_party/repos/spherical_voronoi_core/svMath.hpp \
	../third_party/repos/spherical_voronoi_core/svData.h \
	../third_party/repos/spherical_voronoi_core/svPrefix.h \
	../third_party/repos/spherical_voronoi_core/xs_Float.h \
	../third_party/repos/spherical_voronoi_core/xs_Config.h \
	../third_party/repos/spherical_voronoi_core/svVoronoiCore.h

libSV_la_LDFLAGS = -static -finline-functions -fpermissive
libSV_la_SOURCES = \
	../third_party/repos/spherical_voronoi_core/svMath.cpp \
	../third_party/repos/spherical_voronoi_core/svVoronoiCore.cpp

#libSV_la_CPPFLAGS = $(AM_CXXFLAGS)

#../third_party/spherical_voronoi_core/svMath.hpp






