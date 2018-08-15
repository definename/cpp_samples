project(atomic)

set(PROJECT_SOURCES
	src/main.cpp
	)
set(PROJECT_HEADERS
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)

source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("" FILES ${MISC})

add_executable(${PROJECT_NAME}
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
	${MISC}
	)
include_directories(
	include
	)
#target_link_libraries(${PROJECT_NAME}
#	)
add_definitions(
	-DUNICODE
	-D_UNICODE
	-D_CRT_SECURE_NO_WARNINGS
	)
#add_dependencies(${PROJECT_NAME}
#	)

add_precompiled_headers(${PROJECT_NAME} "src/")

#set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "_asio")
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)