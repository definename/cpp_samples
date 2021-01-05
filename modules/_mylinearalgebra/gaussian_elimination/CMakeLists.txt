project(gaussian_elimination)

set(PROJECT_SOURCES
    src/main.cpp
    )

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    )

if (WIN32)
	target_compile_options(${PROJECT_NAME}
		PRIVATE
			/Qpar /Qpar-report:1 /Qvec-report:1
		)
endif()