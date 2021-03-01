project(dynamic_cast)

set(PROJECT_SOURCES
	src/main.cpp
	)

add_executable(${PROJECT_NAME}
	${PROJECT_SOURCES}
	)

source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

# set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
# set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)