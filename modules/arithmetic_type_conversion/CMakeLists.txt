project(arithmetic_type_conversion)

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

include_directories(include
	)

add_definitions(
	-DUNICODE
	-D_UNICODE
	)

#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

