project(array-size)

set(PROJECT_HEADERS
	)
set(PROJECT_SOURCES
	src/main.cpp
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)


source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_executable(${PROJECT_NAME}
	${PROJECT_HEADERS}
	${PROJECT_SOURCES}
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

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "_template")
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)