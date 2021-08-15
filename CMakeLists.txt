cmake_minimum_required(VERSION 3.5)
project(glTutorial)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-DGLEW_STATIC)
add_subdirectory(external/glew EXCLUDE_FROM_ALL)
add_subdirectory(external/glfw EXCLUDE_FROM_ALL)

set(LIBS libglew_static glfw)

set(PROGS 01 02 02_single_file)

foreach(PROG ${PROGS})
	file(GLOB_RECURSE ${PROG}_SRC
		${PROG}/src/*.c)

	file(GLOB_RECURSE ${PROG}_HDR
		${PROG}/include/*.h)

	add_executable(tutorial_${PROG}
		${${PROG}_SRC}
		${${PROG}_HDR})

	target_include_directories(tutorial_${PROG} PUBLIC ${PROG}/include)

	target_link_libraries(tutorial_${PROG} PRIVATE ${LIBS})
endforeach()
