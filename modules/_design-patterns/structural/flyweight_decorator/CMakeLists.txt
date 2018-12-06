project(flyweight_decorator)

set(PROJECT_HEADERS
	include/City.h
	include/Roads.h
	include/TrafficLightsFactory.h
	include/TrafficLight.h
	include/VehicleDecorator.h
	include/Vehicle.h
	)
set(PROJECT_SOURCES
	src/City.cpp
	src/main.cpp
	src/Roads.cpp
	src/TrafficLightsFactory.cpp
	src/TrafficLight.cpp
	src/Vehicle.cpp
	src/VehicleDecorator.cpp
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

source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("" FILES ${MISC})

include_directories(
	include
	)
# target_link_libraries(${PROJECT_NAME}
	# )
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

add_precompiled_headers(${PROJECT_NAME} "src/")
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROPERTY_FOLDER})
# set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)