cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
project(cx2c CXX)

file(GLOB SRC CONFIGURE_DEPENDS *.cc)
add_executable(cx2c ${SRC})

target_compile_options(
    cx2c
    PRIVATE
    -Wall -Wextra -Werror -Wdisabled-optimization
)

target_include_directories(
    cx2c
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
)

