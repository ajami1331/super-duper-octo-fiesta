cmake_minimum_required(VERSION 3.14)
project(super-duper-octo-fiest VERSION 0.1.0 LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(facil.io QUIET)
if(NOT facil.io_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        facil.io
        GIT_REPOSITORY https://github.com/boazsegev/facil.io/
        GIT_TAG f261935c6c8fc56d582f0a95e3992bcb324a1f26
    )
    FetchContent_GetProperties(facil.io)
    if(NOT facil.io_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(facil.io)
        add_subdirectory(${facil.io_SOURCE_DIR} ${facil.io_BINARY_DIR})
    endif()
endif()

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE facil.io)