project (LowMassHinvLib)

add_library(${PROJECT_NAME}
    #Root/ZZ.cxx
    Root/emuCR.cxx
    #Root/emuROOT.cxx
    )

target_link_libraries (LowMassHinvLib ${ROOT_LIBRARIES})

target_include_directories (${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    )

foreach(exec emuCR)
    add_executable(LM_${exec} utils/${exec}.cxx)
    target_link_libraries(LM_${exec} LowMassHinvLib ${ROOT_LIBRARIES})
endforeach()
