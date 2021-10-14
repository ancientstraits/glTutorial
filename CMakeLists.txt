cmake_minimum_required(VERSION 3.5)
project(glTutorial)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-DGLEW_STATIC)
add_subdirectory(external/glew EXCLUDE_FROM_ALL)
add_subdirectory(external/glfw EXCLUDE_FROM_ALL)

set(LIBS libglew_static glfw)
set(TUTORIALS 01 02)

foreach(TUTORIAL ${TUTORIALS})
	file(GLOB_RECURSE ${TUTORIAL}_SRC
		${TUTORIAL}/src/*.c)

	file(GLOB_RECURSE ${TUTORIAL}_HDR
		${TUTORIAL}/include/*.h)

	add_executable(tutorial_${TUTORIAL}
		${${TUTORIAL}_SRC}
		${${TUTORIAL}_HDR})

	target_include_directories(tutorial_${TUTORIAL} PUBLIC ${TUTORIAL}/include)

	target_link_libraries(tutorial_${TUTORIAL} PRIVATE ${LIBS})
endforeach()
