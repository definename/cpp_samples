project(list)

set(PROJECT_HEADERS
	)
set(PROJECT_RESOURCES
	)
set(PROJECT_SOURCES
	src/main.cpp
	)
set(MISC
	)

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Resource Files" FILES ${PROJECT_RESOURCES})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_executable(${PROJECT_NAME}
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
	${MISC}
	)

# target_include_directories(${PROJECT_NAME}
# 	PRIVATE
# 		include
# 	)
# target_link_libraries(${PROJECT_NAME}
# 	PRIVATE
# 		${Logger_Libraries}
# 		)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)