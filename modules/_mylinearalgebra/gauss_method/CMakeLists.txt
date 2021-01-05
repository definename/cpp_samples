cmake_minimum_required(VERSION 3.19)

project(gauss_method)

message(${CMAKE_CONFIGURATION_TYPES})

set(PROJECT_SOURCES
    src/main.cpp
    )

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    )

if (${CMAKE_CONFIGURATION_TYPES} STREQUAL "Debug")
	target_compile_options(${PROJECT_NAME} PUBLIC /MTd)
else()
	target_compile_options(${PROJECT_NAME} PUBLIC /MT)
endif()
target_compile_options(${PROJECT_NAME} PRIVATE /Qpar /Qpar-report:1 /Qvec-report:1)