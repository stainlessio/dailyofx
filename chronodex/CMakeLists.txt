project(chronodex)

cmake_minimum_required(VERSION 3.1)

set(OF_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../of/" CACHE PATH "The root directory of ofnode/of project.")
include(${OF_ROOT}/openFrameworks.cmake)


#ofxaddon()

set(SOURCES
    src/main.cpp
    src/ofApp.cpp
    src/interfaces.h src/label.cpp src/constructors.h src/connector.cpp src/section.cpp)

add_executable(
    ${PROJECT_NAME}
    MACOSX_BUNDLE
    ${SOURCES}
    ${OFXADDONS_SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${OPENFRAMEWORKS_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
)

ofSetTargetProperties()
