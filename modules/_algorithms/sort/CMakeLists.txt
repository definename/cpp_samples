project(sort)

set(PROJECT_SOURCES
	src/main.cpp
	src/Sorter.cpp
	)
set(PROJECT_HEADERS
	include/Sorter.h
	)
	
set(MISC
	src/pch.h
	src/pch.cpp
	)
	
add_executable(${PROJECT_NAME}
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
	${MISC}
	)

include_directories(
	include
	)
	
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

add_precompiled_headers(${PROJECT_NAME} "src/")

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)