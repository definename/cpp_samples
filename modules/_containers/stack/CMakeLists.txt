project(stack)

set(PROJECT_HEADERS
	)
set(MINFORCONSTTIME_HEADERS
	include/min-for-const-time/Stack.h
	include/min-for-const-time/Queue.h
	include/min-for-const-time/Printer.h
	)
set(PROJECT_RESOURCES
	)
set(PROJECT_SOURCES
	src/main.cpp
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Header Files\\Min-for-const-time" FILES ${MINFORCONSTTIME_HEADERS})
source_group("Resource Files" FILES ${PROJECT_RESOURCES})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_executable(${PROJECT_NAME}
	${MINFORCONSTTIME_HEADERS}
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
	${MISC}
	)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		include
		include/min-for-const-time
	)
target_link_libraries(${PROJECT_NAME}
	PRIVATE
		${Logger_Libraries}
		)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

add_precompiled_headers(${PROJECT_NAME} "src/")
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)