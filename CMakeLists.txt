cmake_minimum_required(VERSION 3.25.1)
project(PoCmon VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)

file(GLOB SOURCES "src/*.c")

include_directories(include)

include(CTest)
enable_testing()

add_executable(PoCmon ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
