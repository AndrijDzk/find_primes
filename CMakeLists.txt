cmake_minimum_required(VERSION 3.9)
FUNCTION(PREPEND var prefix)
	SET(listVar "")
	FOREACH(f ${ARGN})
		LIST(APPEND listVar "${prefix}/${f}")
	ENDFOREACH(f)
	SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(INC Includes)

set(NAME1 find_primes)

set(SDIR Srcs)

set(SOURCES1
		"find_primes_in_range.cpp"
		"is_prime.cpp"
		"myMap.class.cpp"
		"LexicalTreeNode.class.cpp"
		"LowTagLTN.class.cpp"
		"Parser.class.checkForErrors.cpp"
		"Parser.class.getTagPair.cpp"
		"Parser.class.openFile.cpp"
		"Parser.class.readIntervals.cpp"
		"init_static.cpp"
		"main.cpp")

PREPEND(SOURCES_REL1 ${SDIR} ${SOURCES1})

set(CMAKE_CXX_FLAGS "-std=c++11")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

add_executable(${NAME1} ${SOURCES_REL1})
target_include_directories(${NAME1} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${INC}/)

add_subdirectory("Tests")
