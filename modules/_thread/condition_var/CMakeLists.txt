project(condition_var)

set(PROJECT_SOURCES
	src/main.cpp
	)
set(PROJECT_HEADERS
	)
set(MISC
	)

add_executable(${PROJECT_NAME}
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
	${MISC}
	)

source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("" FILES ${MISC})

include_directories(
	include
	)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
# set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)