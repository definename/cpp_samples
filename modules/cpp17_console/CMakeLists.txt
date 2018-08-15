project(cpp17_console)

set(PROJECT_HEADERS
	)
	
set(PROJECT_RESOURCES
	)
	
set(PROJECT_SOURCES
	src/main.cpp
	)
	
set(MISC
	src/pch.h
	src/pch.cpp
	)
	
source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Resource Files" FILES ${PROJECT_RESOURCES})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_executable(${PROJECT_NAME}
	${PROJECT_HEADERS}
	${PROJECT_RESOURCES}
	${PROJECT_SOURCES}
	${MISC}
	)

# target_include_directories(${PROJECT_NAME}
	# )
	
target_link_libraries(${PROJECT_NAME}
	PRIVATE
		${CPP17_Libraries}
		${LOGGER_Libraries}
		)
	
# add_dependencies(${PROJECT_NAME}
	# )
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

add_precompiled_headers(${PROJECT_NAME} "src/")
# set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
# set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)