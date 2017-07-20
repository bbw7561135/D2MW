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

# include
include_directories( "${CMAKE_SOURCE_DIR}/include" )

# Doxygen documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)
     set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/Doxyfile.in)
     set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
     configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
     message("Doxygen build started")
     add_custom_target( doc
          ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
          WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
          COMMENT "Generating API documentation with Doxygen"
          VERBATIM )
else (DOXYGEN_FOUND)
     message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

# add source files
set( D2MW_SRCS
     src/d2mw.cpp
     src/gas_HI.cpp
     src/gas_HII.cpp
     src/gas_H2.cpp
     src/xco.cpp
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
