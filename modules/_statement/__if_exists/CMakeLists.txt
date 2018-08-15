project(__if_exists)

set(VERSION_FILE_DESC "${PROJECT_NAME}")
set(VERSION_PRODUCT_NAME "${PROJECT_NAME}")
set(VERSION_INTERNAL_NAME "${VERSION_PRODUCT_NAME}")
set(VERSION_ORIGINAL_FILENAME "${VERSION_PRODUCT_NAME}.exe")

configure_file(src/res/Version.h.cmake Version.h @ONLY)
if (MSVC)
	configure_file(src/res/Version.rc.cmake Version.rc @ONLY)
	configure_file(src/res/NullConsole.rc.cmake NullConsole.rc @ONLY)
endif()

set(PROJECT_HEADERS
	${CMAKE_CURRENT_BINARY_DIR}/Version.h
	)
if (MSVC)
	set(PROJECT_HEADERS
		${PROJECT_HEADERS}
		include/targetver.h
		include/Resource.h
	)
endif()

set(PROJECT_RESOURCES
	)
if (MSVC)
	set(PROJECT_RESOURCES
		${PROJECT_RESOURCES}
		src/res/NullConsole.ico
		${CMAKE_CURRENT_BINARY_DIR}/Version.rc
		${CMAKE_CURRENT_BINARY_DIR}/NullConsole.rc
		)
endif()

set(PROJECT_SOURCES
	src/main.cpp
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)

add_executable(${PROJECT_NAME}
	${PROJECT_HEADERS}
	${PROJECT_RESOURCES}
	${PROJECT_SOURCES}
	${MISC}
	)

set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/Version.h
		PROPERTIES
			GENERATED 1
			)
if (MSVC)
	set_source_files_properties(
		${CMAKE_CURRENT_BINARY_DIR}/Version.rc
		${CMAKE_CURRENT_BINARY_DIR}/NullConsole.rc 
		PROPERTIES
			GENERATED 1
			)
endif()

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Resource Files" FILES ${PROJECT_RESOURCES})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

include_directories(
	include
	${CMAKE_CURRENT_BINARY_DIR}
	)
#target_link_libraries(${PROJECT_NAME}
#	)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)
if (MSVC)
	add_definitions(
		-DWIN32_LEAN_AND_MEAN
		)
endif()

add_precompiled_headers(${PROJECT_NAME} "src/")
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "_statement")
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)