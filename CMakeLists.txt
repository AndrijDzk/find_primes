cmake_minimum_required(VERSION 3.9)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(INC Includes)

set(NAME1 find_primes)

set(SDIR Srcs)

set(SOURCES1
		Srcs/find_primes_in_range.cpp
		Srcs/is_prime.cpp
		Srcs/myMap.class.cpp
		Srcs/LexicalTreeNode.class.cpp
		Srcs/LowTagLTN.class.cpp
		Srcs/Parser.class.openFile.cpp
		Srcs/Parser.class.readIntervals.cpp
		Srcs/init_static.cpp
		Srcs/main.cpp
		Srcs/Parser.class.cpp Srcs/TagLTNFactory.class.cpp Srcs/Parser.class.strIntoLTNType.cpp)

set(CMAKE_CXX_FLAGS "-std=c++11")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

add_executable(${NAME1} ${SOURCES1})
target_include_directories(${NAME1} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${INC}/)

add_subdirectory("Tests")
