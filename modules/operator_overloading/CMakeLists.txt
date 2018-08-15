project(operator_overloading)

include(PCHSupport)
include(CRTLinkage)

set(PROJECT_SOURCES
	src/main.cpp
	src/Overload.cpp
	)
set(PROJECT_HEADERS
	include/Overload.h
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

#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

