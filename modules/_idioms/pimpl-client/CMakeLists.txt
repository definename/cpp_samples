project(pimpl-client)

set(PROJECT_HEADERS
	)
set(PROJECT_SOURCES
	src/main.cpp
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)

add_executable(${PROJECT_NAME}
	${PROJECT_HEADERS}
	${PROJECT_SOURCES}
	${MISC}
	)

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_precompiled_headers(${PROJECT_NAME} "src/")

include_directories(
	include
	../pimpl-lib/include
	)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

target_link_libraries(${PROJECT_NAME}
	pimpl-lib
	)
add_dependencies(${PROJECT_NAME}
	pimpl-lib
	)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "_idioms")
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)