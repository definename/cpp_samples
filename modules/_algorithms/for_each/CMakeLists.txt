project(for_each)

set(PROJECT_HEADERS
	include/Types.h
	)
set(PROJECT_SOURCES
	src/main.cpp
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)
set(PROJECT_RESOURCES
	)

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Resource Files" FILES ${PROJECT_RESOURCES})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_executable(${PROJECT_NAME}
	${PROJECT_HEADERS}
	${PROJECT_SOURCES}
	${PROJECT_RESOURCES}
	${MISC}
	)

include_directories(
	include
	)

add_precompiled_headers(${PROJECT_NAME} "src/")

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)