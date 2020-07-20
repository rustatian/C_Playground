cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(fundamentals LANGUAGES CXX)
include(ExternalProject)
set(CMAKE_CXX_STANDARD 20)


#FetchContent_MakeAvailable(gtkmm glibmm)
#
#if (NOT gtkmm_POPULATED)
#    FetchContent_Populate(gtkmm)
#    add_subdirectory(${gtkmm_SOURCE_DIR} ${gtkmm_BINARY_DIR})
#endif()
#
#if (NOT glibmm_POPULATED)
#    FetchContent_Populate(glibmm)
#    add_subdirectory(${glibmm_SOURCE_DIR} ${glibmm_BINARY_DIR})
#endif()

#add_dependencies(full gtkmm glibmm)

#FIND_PACKAGE(PkgConfig REQUIRED)
#PKG_CHECK_MODULES(gtkmm REQUIRED gtkmm-3.0)
#INCLUDE_DIRECTORIES(${GTK3MM_INCLUDE_DIRS})

add_executable(gtk main.cpp helloworld.cpp helloworld.h)
#target_link_libraries(gtk glibmm gtkmm)
# https://ftp.gnome.org/pub/GNOME/sources/gtkmm/3.24/gtkmm-3.24.2.tar.xz
# https://download.gnome.org/sources/glib/2.65/glib-2.65.0.tar.xz
# https://download.gnome.org/sources/gtk+/3.24/gtk+-3.24.21.tar.xz
# https://ftp.gnome.org/pub/GNOME/sources/glibmm/2.64/glibmm-2.64.2.tar.xz