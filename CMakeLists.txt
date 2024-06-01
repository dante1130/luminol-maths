cmake_minimum_required(VERSION 3.25.1)

project(LuminolMaths)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LUMINOL_MATHS_RES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)
set(LUMINOL_MATHS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(${LUMINOL_MATHS_SRC_DIR})

add_custom_target(
    copy-compile-commands ALL
    ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_LIST_DIR}
)

