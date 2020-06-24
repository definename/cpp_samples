project(myforwarlist)

set(PROJECT_SOURCES
    src/main.cpp
    src/myforwarlistutil.cpp
    )

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    )
