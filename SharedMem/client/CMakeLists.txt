cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME Client)

project(
    ${PROJECT_NAME}
    VERSION 0.0.1
    DESCRIPTION "Shared Memory Client"
)

include_directories(../global/)

set(SOURCE_FILES
    ./client.c
    ../global/core.c
    ../global/global.c
    ../global/log.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})