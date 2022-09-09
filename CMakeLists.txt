cmake_minimum_required(VERSION 3.0.0)
project(union_find VERSION 0.1.0)
find_package(Doxygen)

add_library(union_find src/main.c)
add_library(union_find_static STATIC src/main.c)

set_target_properties(union_find PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED True C_EXTENSIONS Off)

target_compile_options(union_find PRIVATE $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:GNU>>:-Werror -Wall -pedantic-errors -Wextra -Wconversion -Wsign-conversion>$<$<C_COMPILER_ID:MSVC>:/W4>)

OPTION(BUILD_WITH_DOCS "Generate Docs" ON)

target_include_directories(union_find PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(DOXYGEN_FOUND)
    if(BUILD_WITH_DOCS)
        doxygen_add_docs(union_find_doc "include/" ALL COMMENT "Generate documents")
    endif()
endif()