project(binary_tree)

include(PCHSupport)
include(CRTLinkage)

set(PROJECT_SOURCES
	src/TreeNode.cpp
	src/Tree.cpp
	src/main.cpp
	)
	
set(PROJECT_HEADES
	include/TreeNode.h
	include/Tree.h
	)
	
set(MISC
	src/pch.h
	src/pch.cpp
	)

add_executable(${PROJECT_NAME}
	${PROJECT_SOURCES}
	${PROJECT_HEADES}
	${MISC}
	)
	
add_precompiled_headers(${PROJECT_NAME} "src/")

include_directories(include
	)
	
SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER "_algorithms")
#set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

