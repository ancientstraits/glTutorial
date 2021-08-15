#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glext.h>

#include "util.h"
#include "shader.h"

static GLuint compileSingleShader(GLuint shader_state, const char* shader_code) {
	GLuint shader = glCreateShader(shader_state);
	glShaderSource(shader, 1, &shader_code, NULL);
	glCompileShader(shader);

	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (!result) {
		int log_length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);

		char log_err[log_length + 1];
		glGetShaderInfoLog(shader, log_length, NULL, log_err);
		printf("Failed to compile %s shader:\n%s\n",
				shader_state == GL_VERTEX_SHADER ? "vertex" : "fragment",
				log_err);
	}

	return shader;
}

GLuint createShaderFromFiles(const char *vert_path, const char *frag_path) {
	GLuint vert_shader, frag_shader, full_shader;

	char* vert_code = readFile(vert_path);
	vert_shader = compileSingleShader(GL_VERTEX_SHADER, vert_code);
	free(vert_code);

	char* frag_code = readFile(frag_path);
	frag_shader = compileSingleShader(GL_FRAGMENT_SHADER, frag_code);
	free(frag_code);

	full_shader = glCreateProgram();

	glAttachShader(full_shader, vert_shader);
	glAttachShader(full_shader, frag_shader);
	glLinkProgram(full_shader);

	return full_shader;
}
