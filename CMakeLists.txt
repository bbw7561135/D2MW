project(D2MW C CXX)
cmake_minimum_required(VERSION 2.8)

set( CMAKE_VERBOSE_MAKEFILE off )
set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )
set( CMAKE_C_COMPILER "gcc" )
set( CMAKE_C_FLAGS "-O2" )
set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_CXX_FLAGS "-O2 -ftree-vectorize -std=c++11" )
set( D2MW_INCLUDES )
set( D2MW_LIBRARIES )

# download data files
#message("-- Downloading data file from DRAGON2 repository ~ 10 MB")
#file(DOWNLOAD
#	https://www.dropbox.com/s/aluz8yka66uruwn/data.tar.gz?dl=0
#	${CMAKE_BINARY_DIR}/data.tar.gz
#	EXPECTED_MD5 87bbb5999a15799c4449354f5a62c73c)
#message("-- Extracting data file")
#execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${CMAKE_BINARY_DIR}/data.tar.gz WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

# include
include_directories( "${CMAKE_SOURCE_DIR}/include" )

# ymw16 (provided)
#add_subdirectory(libs/ymw16)
#list(APPEND D2XSEC_LIBRARIES YMW16) 

# GSL (external)
#find_package(GSL)
#if(GSL_FOUND)
#  set(HAVE_LIBGSL 1)
#  list(APPEND D2MW_INCLUDES ${GSL_INCLUDE_DIR})
#  list(APPEND D2MW_LIBRARIES ${GSL_LIBRARIES})
#else(GSL_FOUND)
#  message(FATAL_ERROR "Require GSL: set GSL_HOME")
#endif(GSL_FOUND)

# add source files
set( D2MW_SRCS
     src/d2mw.cpp
     src/gas_HI.cpp
     src/gas_HII.cpp
     src/gas_H2.cpp
     src/utilities.cpp
     src/models/gasFerriere2007.cpp
)

# make library
include_directories (include ${D2MW_INCLUDES})
add_library(D2MW ${D2MW_SRCS} ${D2MW_INCLUDES})

# make executables
add_executable(example_gas examples/example_gas.cpp )
target_link_libraries (example_gas D2MW ${D2MW_LIBRARIES})

# show summary
message (STATUS "CMAKE_SYSTEM .......... = ${CMAKE_SYSTEM}")
message (STATUS "BUILD_SHARED_LIBS ..... = ${BUILD_SHARED_LIBS}")
message (STATUS "CMAKE_CXX_COMPILER .... = ${CMAKE_CXX_COMPILER}")
message (STATUS "CMAKE_CXX_FLAGS ....... = ${CMAKE_CXX_FLAGS}")
message (STATUS "CMAKE_INCLUDE_PATH .... = ${CMAKE_INCLUDE_PATH}")
message (STATUS "D2MW_INCLUDES ....... = ${D2MW_INCLUDES}")
message (STATUS "D2MW_LIBRARIES ...... = ${D2MW_LIBRARIES}")
