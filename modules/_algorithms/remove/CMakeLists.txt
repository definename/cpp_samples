project(remove)

set(PROJECT_SOURCES
	src/main.cpp
	)

set(PROJECT_HEADES
	)

set(MISC
	src/pch.h
	src/pch.cpp
	)

add_executable(${PROJECT_NAME}
	${PROJECT_SOURCES}
	${PROJECT_HEADES}
	${MISC}
	)

include_directories(
	include
	)

add_precompiled_headers(${PROJECT_NAME} "src/")

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)