cmake_minimum_required(VERSION 3.5)
project(glTutorial)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-DGLEW_STATIC)
add_subdirectory(external/glew EXCLUDE_FROM_ALL)
add_subdirectory(external/glfw EXCLUDE_FROM_ALL)

set(LIBS libglew_static glfw)

# 01
file(GLOB_RECURSE 01_SRC
	01/src/*.c)

file(GLOB_RECURSE 01_HDR
	01/include/*.h)

add_executable(tutorial_01
	${01_SRC}
	${01_HDR})

target_include_directories(tutorial_01 PUBLIC 01/include)

target_link_libraries(tutorial_01 PRIVATE ${LIBS})
