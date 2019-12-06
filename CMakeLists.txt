cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
find_package (glfw3 REQUIRED)

add_executable(MyApp main.cpp)

target_link_libraries(MyApp glfw ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${glfw_LIBRARIES})

