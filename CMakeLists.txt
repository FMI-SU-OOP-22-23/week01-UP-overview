cmake_minimum_required (VERSION 3.13)

project ("OOP week 01" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library target for the sample library
add_library(solution STATIC)

target_sources(
	solution
	PRIVATE
		"src/solution.cpp"
		"src/solution.h"
)


#
# Make Catch2 available. For more information check
# https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md
#
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.1.1)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)


# Executable target for the unit tests
add_executable(testing)

# Executable target for the unit tests
add_executable(application)

target_link_libraries(
	testing
	PRIVATE
		solution
		Catch2::Catch2WithMain
)

target_include_directories(testing PRIVATE "src")

target_sources(
	testing
	PRIVATE
		"test/solution_test.cpp"
)


target_sources(
		application
		PRIVATE
		"src/application.cpp"
		"src/solution.h"
		"src/solution.cpp"
)

# Automatically register all tests
include(CTest)
include(Catch)
catch_discover_tests(testing)


