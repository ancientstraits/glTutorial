#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "vert.h"

static GLfloat points[9] = {
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
};

static void get_window_size(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main(int argc, char *argv[]) {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		return 1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(600, 400, "Tutorial 01", NULL, NULL);
	if (!window) {
		fprintf(stderr, "Failed to create window\n");
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, get_window_size);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return 1;
	}

	GLuint shader = create_shader_from_files("02/res/main.vert", "02/res/main.frag");
	GLuint vao = create_vertex_array(points, 3, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0, 0.3, 0.3, 0.0);

		glUseProgram(shader);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(shader);

	glfwTerminate();

	return 0;
}
