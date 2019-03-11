cmake_minimum_required(VERSION 3.13.1)

project(cpp_samples)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

option(BUILD_WITH_BOOST "Build project with boost libraries" ON)
option(WITH_LOGGER "Build project with logger support" ON)

include(PCHSupport)
include(CRTLinkage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
# Where to put all the ARCHIVE targets when built.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Where to put all the RUNTIME target files when built.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Use folder in project
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# External directory.
set(EXTERNAL_DIRECTORY ${CMAKE_SOURCE_DIR}/external)

###########################################################
# Version #################################################

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_BUILD "0")
set(REVISION_COUNT "0")

find_package(Git)
if(GIT_FOUND)
	execute_process(
		COMMAND ${GIT_EXECUTABLE} rev-list HEAD --count
		OUTPUT_VARIABLE DESCRIBE_BUILD
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		OUTPUT_STRIP_TRAILING_WHITESPACE)
	string(REGEX MATCH "[0-9]+" REVISION_COUNT ${DESCRIBE_BUILD})
endif()

set(VERSION_REVISION "${REVISION_COUNT}")
set(VERSION_FILE_REVISION "${REVISION_COUNT}")
set(VERSION_COMPANY_NAME "Carrot Farm")
set(VERSION_COPYRIGHT "Copyright (C) 2018 ${VERSION_COMPANY_NAME}")

###########################################################
# Boost ###################################################

if(BUILD_WITH_BOOST)
	set(Boost_USE_STATIC_LIBS ON)
	set(Boost_USE_MULTITHREADED ON)
	set(Boost_USE_STATIC_RUNTIME ON)
	find_package(Boost REQUIRED COMPONENTS
		filesystem
		date_time
		thread
		)
endif()

###########################################################
# spdlog ##################################################

set(SPDLOG_INCLUDE_DIRS ${EXTERNAL_DIRECTORY}/spdlog/include)

###########################################################
# logger ##################################################

if(WITH_LOGGER)
	set(Logger_Libraries logger)
	add_subdirectory(modules/logger)
endif()

# add_subdirectory(modules/_algorithms)
# add_subdirectory(modules/_bits)
# add_subdirectory(modules/_binders)
add_subdirectory(modules/_base_conversion)
# add_subdirectory(modules/_deitel_tasks)
# add_subdirectory(modules/_idioms)
# add_subdirectory(modules/_memory)
# add_subdirectory(modules/_design-patterns)
# add_subdirectory(modules/_tasks)
# add_subdirectory(modules/_functional)
# add_subdirectory(modules/_template)
# add_subdirectory(modules/_file_io)
# add_subdirectory(modules/_polymorphism)
# add_subdirectory(modules/_virtual_inheritance)
# add_subdirectory(modules/_containers)
# add_subdirectory(modules/_lambda)
# add_subdirectory(modules/_move-semantic)
# add_subdirectory(modules/_type-traits)
# add_subdirectory(modules/_static)
# add_subdirectory(modules/_condition_var)
# add_subdirectory(modules/_exception)
# add_subdirectory(modules/_stl_re-implementation)

# add_subdirectory(modules/dynamic_cast)
# add_subdirectory(modules/atexit)
# add_subdirectory(modules/assert)
# add_subdirectory(modules/atomic)
# add_subdirectory(modules/auto-type)
# add_subdirectory(modules/arithmetic_type_conversion)
# add_subdirectory(modules/brute_force)
# add_subdirectory(modules/constexpr)
# add_subdirectory(modules/chrono)
# add_subdirectory(modules/class-definitions)
# add_subdirectory(modules/calculator)
# add_subdirectory(modules/enum)
# add_subdirectory(modules/union)
# add_subdirectory(modules/function_pointer)
# add_subdirectory(modules/friend_function)
# add_subdirectory(modules/goto)
# add_subdirectory(modules/himself_reference)
# add_subdirectory(modules/iterator)
# add_subdirectory(modules/operator_overloading)
# add_subdirectory(modules/optional)
# add_subdirectory(modules/override)
# add_subdirectory(modules/replace)
# add_subdirectory(modules/rotate)
# add_subdirectory(modules/random)
# add_subdirectory(modules/regex)
# add_subdirectory(modules/reference-wrapper)
# add_subdirectory(modules/ref-qualifier)
# add_subdirectory(modules/safe_string_functions)
# add_subdirectory(modules/str_hex_to_int)
# add_subdirectory(modules/simple_nearest)
# add_subdirectory(modules/simple_number)
# add_subdirectory(modules/struct_bindings)
# add_subdirectory(modules/tuple)
# add_subdirectory(modules/unnamed_arguments)
# add_subdirectory(modules/xy_line_coordinate)