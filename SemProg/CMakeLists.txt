cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
# 1. Project Name
set(PROJECT_NAME SemProg)
# 2. Project
project(
    ${PROJECT_NAME}
    DESCRIPTION "SemProg - "
    VERSION 1.0.0
)
# 3. Includes
include_directories(${SemProg_SOURCE_DIR}/inc)
include_directories(${SemProg_SOURCE_DIR}/src)
# 4. Set source files
set(SOURCE_DATA
    ./src/main.c
    ./src/core.c
    ./src/log.c
)
# 5. Set compiler
set(CMAKE_C_COMPILER gcc)
# 6. Set result folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# 7. Executable
add_executable(${PROJECT_NAME} ${SOURCE_DATA})