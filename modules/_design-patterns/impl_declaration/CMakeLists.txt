project(impl_declaration)

set(PROJECT_HEADERS
	include/Facade.h
	)
set(PROJECT_SOURCES
	src/main.cpp
	src/Facade.cpp
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

source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("" FILES ${MISC})

add_precompiled_headers(${PROJECT_NAME} "src/")

include_directories(
	include
	)
# target_link_libraries(${PROJECT_NAME}
	# )
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
# set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)