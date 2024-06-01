add_executable(LuminolMathsDemo)

target_compile_features(LuminolMathsDemo PRIVATE cxx_std_20)
set_target_properties(LuminolMathsDemo PROPERTIES 
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_compile_options(LuminolMathsDemo PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /wd4458>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic -Werror>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -pedantic -Werror>
)

target_sources(LuminolMathsDemo PRIVATE
    main.cpp
)

target_link_libraries(LuminolMathsDemo PRIVATE
    LuminolMaths
)
