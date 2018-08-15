project(mediator)

set(PROJECT_SOURCES
	src/main.cpp
	src/DirectorImpl.cpp
	src/WidgetImpl1.cpp
	src/WidgetImpl2.cpp
	)
set(PROJECT_HEADERS
	include/WidgetImpl1.h
	include/WidgetImpl2.h
	include/IDirector.h
	include/DirectorImpl.h
	include/IWidget.h
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
	
add_precompiled_headers(${PROJECT_NAME} "src/")

include_directories(include
	)
	
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)