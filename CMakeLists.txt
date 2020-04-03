cmake_minimum_required(VERSION 3.5)

project(jROOT)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS RIO Net TMVA)
include(${ROOT_USE_FILE})

add_subdirectory(LowMassHinv)

#set (source "${CMAKE_SOURCE_DIR}/scripts")
#set (destination "${CMAKE_SOURCE_DIR}/build")

#configure_file( ${CMAKE_SOURCE_DIR}/config ${CMAKE_CURRENT_BINARY_DIR}/config COPYONLY)

#file ( COPY ${CMAKE_SOURCE_DIR}/config DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
