cmake_minimum_required(VERSION 3.22)

project(
	AlchemyEffectConverter
	VERSION 3.1.3.1
	LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
	message(FATAL_ERROR "in-source builds are not allowed")
endif()

macro(set_from_environment VARIABLE)
	if(NOT DEFINED ${VARIABLE} AND DEFINED ENV{${VARIABLE}})
		set(${VARIABLE} $ENV{${VARIABLE}})
	endif()
endmacro()



option(COPY_OUTPUT "copy the output of build operations to the game directory" OFF)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_subdirectory(src)
include(cmake/packaging.cmake)
