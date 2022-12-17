cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME Server)

project(
    ${PROJECT_NAME}
    VERSION 0.0.1
    DESCRIPTION "MsgQueue Server"
)

include_directories(../global/)

set(SOURCE_FILES
    ./server.c
    ../global/global.c
)

find_package( Threads )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries( ${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} )