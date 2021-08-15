#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "vert.h"


GLuint makeVertArray() {
    GLuint vao;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    return vao;
}

GLuint makeVertBuffer(GLfloat *vert_points, GLint vert_count, GLuint draw_state) {
	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * vert_count, vert_points, draw_state);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	return vbo;
}