cmake_minimum_required(VERSION 3.0)

set(NAME unittests)

set(SOURCES
		"../Srcs/find_primes_in_range.cpp"
		"test_find_primes_in_range.cpp"
		"../Srcs/is_prime.cpp"
		"test_is_prime.cpp"
		"../Srcs/myMap.class.cpp"
		"test_MyMap.class.operator==.cpp"
		"../Srcs/Parser.class.checkForErrors.cpp"
		"test_Parser.class.checkForMissingOpeningTag.cpp"
		"test_Parser.class.checkForMissingClosingTag.cpp"
		"../Srcs/LexicalTreeNode.class.cpp"
		"../Srcs/LowTagLTN.class.cpp"
		"../Srcs/init_static.cpp"
		"test_TagLTN.class.cpp")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

add_executable(${NAME} ${SOURCES})
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Includes)


add_subdirectory("googletest")
target_link_libraries(${NAME} gtest_main)
