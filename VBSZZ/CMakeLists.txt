project (VBSZZLib)

add_library(${PROJECT_NAME}
    Root/VBS_CutFlow.cxx
    Root/VBS_3lCR.cxx
    Root/VBS_2lXR.cxx
    Root/SlimTree.cxx
    Root/readTree.cxx
    )

target_link_libraries (VBSZZLib ${ROOT_LIBRARIES})

target_include_directories (${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    )

foreach(exec CutFlow CutOneNtuple SlimTree 3lCR processTheo readTree)
    add_executable(VBS_${exec} utils/${exec}.cxx)
    target_link_libraries(VBS_${exec} VBSZZLib ${ROOT_LIBRARIES})
endforeach()
