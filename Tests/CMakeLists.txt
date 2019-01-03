cmake_minimum_required(VERSION 3.0)

set(NAME unittests)

cmake_policy(SET CMP0048 NEW)

add_subdirectory("googletest")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

add_executable(${NAME} is_prime_test.cpp Srcs/is_prime.cpp)
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Includes)
target_link_libraries(${NAME} gtest_main)
