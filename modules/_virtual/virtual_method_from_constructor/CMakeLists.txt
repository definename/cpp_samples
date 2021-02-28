project(virtual_method_from_constructor)

set(PROJECT_SOURCES
	src/main.cpp
	)
add_executable(${PROJECT_NAME} src/main.cpp)
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)
