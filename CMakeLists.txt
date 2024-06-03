cmake_minimum_required(VERSION 3.25.1)

project(LuminolMaths)

option(LUMINOL_MATHS_EXPORT_COMPILE_COMMANDS "Export compile commands" ON)
option(LUMINOL_MATHS_BUILD_DEMO "Build LuminolMaths demo" ON)
option(LUMINOL_MATHS_BUILD_TESTS "Build LuminolMaths tests" ON)

if (LUMINOL_MATHS_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

    add_custom_target(
        copy-compile-commands ALL
        ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_LIST_DIR}
    )
endif()

set(LUMINOL_MATHS_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(LUMINOL_MATHS_RES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)
set(LUMINOL_MATHS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LUMINOL_MATHS_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_subdirectory(${LUMINOL_MATHS_SRC_DIR})

if (LUMINOL_MATHS_BUILD_TESTS)
    enable_testing()
    add_subdirectory(${LUMINOL_MATHS_LIB_DIR})
    add_subdirectory(${LUMINOL_MATHS_TEST_DIR})
endif()

