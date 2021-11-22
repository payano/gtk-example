# Set project
cmake_minimum_required(VERSION 3.10)
project(gtk-test CXX)

set(CMAKE_BUILD_TYPE Debug)
set(THREADS_PREFER_PTHREAD_FLAG ON)

#set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -pedantic -O2 -Werror -Wextra -fexceptions")
set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -pedantic -O0 -Werror -Wextra -fexceptions")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtkmm-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

add_executable(hello main.cpp)
TARGET_LINK_LIBRARIES(hello ${GTK_LIBRARIES})