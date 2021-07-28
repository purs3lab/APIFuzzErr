include_directories(include/)

# add dynamic link library
add_library(APIFuzzErrHeuristicPass MODULE src/ModuleLevelAnalysisPass.cpp)

# add statically linked library
add_library(APIFuzzErrHeuristicPassStatic STATIC src/ModuleLevelAnalysisPass.cpp)

set_target_properties(APIFuzzErrHeuristicPass PROPERTIES
        COMPILE_FLAGS "-g"
        )

set_target_properties(APIFuzzErrHeuristicPassStatic PROPERTIES
        COMPILE_FLAGS "-g"
        )

target_compile_features(APIFuzzErrHeuristicPass PRIVATE cxx_range_for cxx_auto_type)

target_compile_features(APIFuzzErrHeuristicPassStatic PRIVATE cxx_range_for cxx_auto_type)