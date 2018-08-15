project(cpp17)

set(PROJECT_HEADERS
	include/cpp17/structured_bindings.h
	include/cpp17/optional.h
	include/cpp17/cpp17.hpp
	)
	
set(PROJECT_RESOURCES
	)
	
set(PROJECT_SOURCES
	src/structured_bindings.cpp
	src/optional.cpp
	)
	
set(MISC
	src/pch.h
	src/pch.cpp
	)
	
source_group("Header Files\\cpp17" FILES ${PROJECT_HEADERS})
source_group("Resource Files" FILES ${PROJECT_RESOURCES})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_library(${PROJECT_NAME} STATIC
	${PROJECT_HEADERS}
	${PROJECT_RESOURCES}
	${PROJECT_SOURCES}
	${MISC}
	)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		include
	)
	
target_link_libraries(${PROJECT_NAME}
	PRIVATE
		${LOGGER_Libraries}
	)

add_definitions(
	-DUNICODE
	-D_UNICODE
	)
	
# add_dependencies(${PROJECT_NAME}
	# )

add_precompiled_headers(${PROJECT_NAME} "src/")
# set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
# set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)