project(abstract_factory)

include(PCHSupport)
include(CRTLinkage)

set(PROJECT_SOURCES
	src/main.cpp
	src/IntelFactory.cpp
	src/AMDFactory.cpp
	src/Processor.cpp
	src/VideoCard.cpp
	)
set(PROJECT_HEADERS
	include/IFactory.h
	include/IDevice.h
	include/IntelFactory.h
	include/AMDFactory.h
	include/Processor.h
	include/VideoCard.h
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