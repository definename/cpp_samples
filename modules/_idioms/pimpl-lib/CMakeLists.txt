project(pimpl-lib)

set(PROJECT_HEADERS
	include/Widget.h
	include/Gadget.h
	include/Impl.h
	)
set(PROJECT_SOURCES
	src/Widget.cpp
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)

add_library(${PROJECT_NAME} STATIC
	${PROJECT_HEADERS}
	${PROJECT_SOURCES}
	${MISC}
	)

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_precompiled_headers(${PROJECT_NAME} "src/")

include_directories(
	include
	)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "_idioms")
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)