cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME Server)

project(
    ${PROJECT_NAME}
    VERSION 0.0.1
    DESCRIPTION "Shared Memory Server"
)

include_directories(../global/)

set(SOURCE_FILES
    ./server.c
    ../global/core.c
    ../global/global.c
    ../global/log.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})