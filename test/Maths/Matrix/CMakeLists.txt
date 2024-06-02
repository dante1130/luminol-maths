add_executable(LuminolMaths.MathsTests.Matrix
    "MatrixTest.cpp"
)

target_compile_features(LuminolMaths.MathsTests.Matrix INTERFACE cxx_std_20)

set_target_properties(LuminolMaths.MathsTests.Matrix PROPERTIES 
    CXX_EXTENSIONS OFF
)

target_compile_options(LuminolMaths.MathsTests.Matrix INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /wd4458>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic -Werror>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -pedantic -Werror>
)

target_link_libraries(LuminolMaths.MathsTests.Matrix
    GTest::gtest
    LuminolMaths.TestUtils
)

target_include_directories(LuminolMaths.MathsTests.Matrix PRIVATE
    ${TEST_DIR}
)

include(GoogleTest)
gtest_discover_tests(LuminolMaths.MathsTests.Matrix)

