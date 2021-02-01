project (LowMassHinvLib)

add_library(${PROJECT_NAME}
    #Root/ZZ.cxx
    Root/HinvComb.cxx
    Root/emuCR.cxx
    Root/emuMC.cxx
    Root/readMC.cxx
    Root/readTree.cxx
    #Root/emuROOT.cxx
    )

target_link_libraries (LowMassHinvLib ${ROOT_LIBRARIES})

target_include_directories (${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    )

foreach(exec emuCR emuMC emuMCROOT readMC HinvComb emuMCROOT115 compare_version compare_data processTheo)
    add_executable(LM_${exec} utils/${exec}.cxx)
    target_link_libraries(LM_${exec} LowMassHinvLib ${ROOT_LIBRARIES})
endforeach()
