add_library(LuminolMaths INTERFACE)

target_compile_features(LuminolMaths INTERFACE cxx_std_20)
set_target_properties(LuminolMaths PROPERTIES CXX_EXTENSIONS OFF)

target_compile_options(LuminolMaths INTERFACE 
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /wd4458>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic -Werror>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -pedantic -Werror>
)

target_include_directories(LuminolMaths INTERFACE
    ${LUMINOL_MATHS_SRC_DIR}
)
