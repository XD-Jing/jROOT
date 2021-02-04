cmake_minimum_required(VERSION 3.5)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(jROOT)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -w")
endif()

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS RIO Net TMVA)
include(${ROOT_USE_FILE})

add_subdirectory(LowMassHinv)
add_subdirectory(VBSZZ)

#set (source "${CMAKE_SOURCE_DIR}/scripts")
#set (destination "${CMAKE_SOURCE_DIR}/build")

#configure_file( ${CMAKE_SOURCE_DIR}/config ${CMAKE_CURRENT_BINARY_DIR}/config COPYONLY)

#file ( COPY ${CMAKE_SOURCE_DIR}/config DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
