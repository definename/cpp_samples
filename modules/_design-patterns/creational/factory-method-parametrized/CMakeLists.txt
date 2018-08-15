project(factory-method-parametrized)

set(PROJECT_HEADERS
	include/ArchersImpl.h
	include/CavalryImpl.h
	include/InfantryImpl.h
	include/Types.h
	include/Warrior.h
	)

set(PROJECT_SOURCES
	src/main.cpp
	src/ArchersImpl.cpp
	src/CavalryImpl.cpp
	src/InfantryImpl.cpp
	src/Warrior.cpp
	)
	
set(MISC
	src/pch.h
	src/pch.cpp
	)
	
add_executable(${PROJECT_NAME}
	${PROJECT_HEADERS}
	${PROJECT_SOURCES}
	${MISC}
	)
	
add_precompiled_headers(${PROJECT_NAME} "src/")

include_directories(
	include
	)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)