cmake_minimum_required(VERSION 3.12)
project(mine-sweeper)

#set(OpenGL_GL_PREFERENCE GLVND)

file(GLOB SRC_FILES src/*.cpp)

set(exe-name ${PROJECT_NAME})

add_executable(${exe-name} ${SRC_FILES})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

find_package(OpenGL REQUIRED)
find_package(GLFW 2.1)
message(STATUS "FIND GLFW_INCLUDE_DIRS " ${GLFW_INCLUDE_DIRS})

find_package(GLEW 2.1)
include_directories(
        include
        ${GLFW_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
)

set(ALL_LIBS
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
)

target_link_libraries(${exe-name} ${ALL_LIBS})

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

install(TARGETS mine-sweeper RUNTIME DESTINATION bin)
