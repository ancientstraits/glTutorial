#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "util.h"

static GLuint create_single_shader(GLuint shader_type, const char* shader_code) {
	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &shader_code, NULL);
	glCompileShader(shader);


	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (!result) {
		int error_length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &error_length);

		char error_message[error_length + 1];
		glGetShaderInfoLog(shader, error_length, NULL, error_message);

		fprintf(stderr, "Failed to compiled %s shader:\n%s\n",
				shader_type == GL_VERTEX_SHADER ? "vertex" : "fragment",
				error_message);
		abort();
	}

	return shader;
}

GLuint create_shader_from_files(const char *vert_path, const char *frag_path) {
	GLuint vert_shader, frag_shader, full_shader;

	char* vert_code = read_file(vert_path);
	vert_shader = create_single_shader(GL_VERTEX_SHADER, vert_code);
	free(vert_code);

	char* frag_code = read_file(frag_path);
	frag_shader = create_single_shader(GL_FRAGMENT_SHADER, frag_code);
	free(frag_code);

	full_shader = glCreateProgram();
	glAttachShader(full_shader, vert_shader);
	glAttachShader(full_shader, frag_shader);
	glLinkProgram(full_shader);

	return full_shader;
}

