project(gauss_method)

set(PROJECT_SOURCES
    src/main.cpp
    )

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    )

if(WIN32)
    message(STATUS "CMAKE_CONFIGURATION_TYPES: ${CMAKE_CONFIGURATION_TYPES}")
    if (${CMAKE_CONFIGURATION_TYPES} STREQUAL "Debug")
        target_compile_options(${PROJECT_NAME} PUBLIC /MTd)
    else()
        target_compile_options(${PROJECT_NAME} PUBLIC /MT)
    endif()
    target_compile_options(${PROJECT_NAME} PRIVATE /Qpar /Qpar-report:1 /Qvec-report:1)
endif(WIN32)