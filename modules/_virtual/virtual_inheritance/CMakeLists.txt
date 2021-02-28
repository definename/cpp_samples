project(virtual_inheritance)

set(PROJECT_HEADERS
	src/Clock.h
	src/Window.h
	src/WindowBorder.h
	src/WindowMenu.h
	)
set(PROJECT_SOURCES
	src/main.cpp
	)

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Source Files" FILES ${PROJECT_SOURCES})

add_executable(${PROJECT_NAME}
	${PROJECT_SOURCES}
	)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)
