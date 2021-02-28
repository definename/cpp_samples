project(employee)

set(PROJECT_HEADERS
	include/Manager.h
	include/Employee.h
	)

set(PROJECT_RESOURCES
	)

set(PROJECT_SOURCES
	src/main.cpp
	src/Manager.cpp
	src/Employee.cpp
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

include_directories(
	include
	)

add_definitions(
	-DUNICODE
	-D_UNICODE
	)

add_precompiled_headers(${PROJECT_NAME} "src/")
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)