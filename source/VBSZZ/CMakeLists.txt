# The name of the package:
atlas_subdir (VBSZZ)

find_package( ROOT COMPONENTS Core RIO Hist Tree)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -w")
endif()

set (ROOT_CONFIG "root-config")
set (ROOT_ARG "--libs")
execute_process(COMMAND ${ROOT_CONFIG} ${ROOT_ARG}
    OUTPUT_VARIABLE ROOT_OUT
    OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${ROOT_OUT} -lTMVA")

atlas_add_library (VBSZZLib
    VBSZZ/*.h Root/*.cxx Root/*.c
    PUBLIC_HEADERS VBSZZ
    LINK_LIBRARIES AnaAlgorithmLib
    )

foreach( exec testrun rdata rEWK)
    atlas_add_executable( ${exec}
        utils/${exec}.cxx
        INCLUDE_DIRS ${ROOT_INCLUDE_DIRS}
        LINK_LIBRARIES ${ROOT_LIBRARIES}
        VBSZZLib)
endforeach()


# Install files from the package:
#atlas_install_joboptions( share/*_jobOptions.py )
#atlas_install_scripts( share/*_eljob.py )
