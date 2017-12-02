project(0001)

cmake_minimum_required(VERSION 3.1)

set(OF_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../of/" CACHE PATH "The root directory of ofnode/of project.")
include(${OF_ROOT}/openFrameworks.cmake)


#ofxaddon()

set(SOURCES
    src/main.cpp
    src/ofApp.cpp
)

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
