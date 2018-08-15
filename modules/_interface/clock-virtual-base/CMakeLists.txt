project(clock-virtual-base)

set(PROJECT_HEADERS
	include/Clock.h
	include/Window.h
	include/WindowBorder.h
	include/WindowMenu.h
	)
set(PROJECT_RESOURCES
	)
set(PROJECT_SOURCES
	src/Clock.cpp
	src/main.cpp
	src/WindowBorder.cpp
	src/WindowMenu.cpp
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
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
	${MISC}
	)

add_precompiled_headers(${PROJECT_NAME} "src/")

include_directories(
	include
	)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "_interface")
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)