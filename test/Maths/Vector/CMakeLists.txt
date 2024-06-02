add_executable(LuminolMaths.MathsTests.Vector
    "VectorLengthTests.cpp"
    "VectorNormalizedTests.cpp"
    "VectorDotProductTests.cpp"
    "VectorCrossProductTests.cpp"
)

target_compile_features(LuminolMaths.MathsTests.Vector INTERFACE cxx_std_20)

set_target_properties(LuminolMaths.MathsTests.Vector PROPERTIES 
    CXX_EXTENSIONS OFF
)

target_compile_options(LuminolMaths.MathsTests.Vector INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /wd4458>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic -Werror>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -pedantic -Werror>
)

target_link_libraries(LuminolMaths.MathsTests.Vector
    GTest::gtest_main
    LuminolMaths.TestUtils
)

target_include_directories(LuminolMaths.MathsTests.Vector PRIVATE
    ${TEST_DIR}
)

include(GoogleTest)
gtest_discover_tests(LuminolMaths.MathsTests.Vector)

