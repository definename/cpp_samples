project(myforwarlist)

set(TRICKS_DIR ${CMAKE_CURRENT_LIST_DIR}/tricks)
set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)


set(FORWARD_LIST_TRICKS
    ${TRICKS_DIR}/findlistloop.cpp
    ${TRICKS_DIR}/findlistmiddle.cpp
    ${TRICKS_DIR}/forwardlistutil.cpp
    )

set(PROJECT_SOURCES
    ${SRC_DIR}/main.cpp
    ${FORWARD_LIST_TRICKS}
    )

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${TRICKS_DIR}
        ${SRC_DIR}
)
