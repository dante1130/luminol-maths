add_subdirectory(Maths)
add_subdirectory(Units)

add_library(LuminolMaths.TestUtils INTERFACE)

target_compile_features(LuminolMaths.TestUtils INTERFACE cxx_std_20)

set_target_properties(LuminolMaths.TestUtils PROPERTIES 
    CXX_EXTENSIONS OFF
)

target_compile_options(LuminolMaths.TestUtils INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /wd4458>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic -Werror>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -pedantic -Werror>
)

target_include_directories(LuminolMaths.TestUtils INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(LuminolMaths.TestUtils INTERFACE
    GTest::gtest_main
    LuminolMaths
)
