cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME SharedMem)

project(
    ${PROJECT_NAME}
    VERSION 0.0.1
    DESCRIPTION "Shared Memory Project with server and client"
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(client)
add_subdirectory(server)