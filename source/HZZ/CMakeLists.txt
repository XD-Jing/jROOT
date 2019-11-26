# The name of the package:
atlas_subdir (HZZ)

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

atlas_add_library (HZZLib
    HZZ/*.h Root/*.cxx
    PUBLIC_HEADERS HZZ
    LINK_LIBRARIES AnaAlgorithmLib
    )

foreach( exec  accept_ZZ accept_truth accept_jun emuData emuMC emuMCPerYear
        emuOther accept_Michiel_ZZ LM_Michiel_ZZ plots)
    atlas_add_executable( ${exec}
        utils/${exec}.cxx
        INCLUDE_DIRS ${ROOT_INCLUDE_DIRS}
        LINK_LIBRARIES ${ROOT_LIBRARIES}
        HZZLib)
endforeach()


# Install files from the package:
#atlas_install_joboptions( share/*_jobOptions.py )
#atlas_install_scripts( share/*_eljob.py )
