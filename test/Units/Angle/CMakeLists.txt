add_executable(LuminolMaths.UnitsTests.Angle
    "AngleConversionTests.cpp"
    "AngleOperatorTests.cpp"
)

target_compile_features(LuminolMaths.UnitsTests.Angle INTERFACE cxx_std_20)

set_target_properties(LuminolMaths.UnitsTests.Angle PROPERTIES 
    CXX_EXTENSIONS OFF
)

target_compile_options(LuminolMaths.UnitsTests.Angle INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /wd4458>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic -Werror>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -pedantic -Werror>
)

target_link_libraries(LuminolMaths.UnitsTests.Angle
    GTest::gtest_main
    LuminolMaths.TestUtils
)

target_include_directories(LuminolMaths.UnitsTests.Angle PRIVATE
    ${TEST_DIR}
)

include(GoogleTest)
gtest_discover_tests(LuminolMaths.UnitsTests.Angle)

