cmake_minimum_required(VERSION 3.16)
project(practise VERSION 1.0.0 LANGUAGES C CXX) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
  include
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Sources
set(SOURCES 
  src/main.cpp
  src/screen.cpp
)

add_executable(practise ${SOURCES})

# target_link_libraries()
# target_include_directories()

# Graphics libraries
add_subdirectory(external/glfw)
include_directories(external/glad/GL/include)
include_directories(external/glm)

file(GLOB GLAD_SOURCES external/glad/GL/src/gl.c)
target_sources(practise PRIVATE ${GLAD_SOURCES})
find_package(OpenGL REQUIRED)
target_link_libraries(practise 
  glfw
  OpenGL::GL
)
