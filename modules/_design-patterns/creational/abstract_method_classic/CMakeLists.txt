project(abstract-method-classic)

set(PROJECT_HEADERS
	include/IWarrior.h
	include/ICreator.h
	include/ArchersCreator.h
	include/ArchersImpl.h
	include/CavalryCreator.h
	include/CavalryImpl.h
	include/InfantryCreator.h
	include/InfantryImpl.h
	)

set(PROJECT_SOURCES
	src/main.cpp
	src/ArchersCreator.cpp
	src/ArchersImpl.cpp
	src/CavalryCreator.cpp
	src/CavalryImpl.cpp
	src/InfantryCreator.cpp
	src/InfantryImpl.cpp
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