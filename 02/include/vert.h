#ifndef VERT_H
#define VERT_H

#include <GLFW/glfw3.h>

/*
 * Makes a vertex array object.
 * You must call this function before makeVertBuffer.
 */
GLuint makeVertArray();

/*
 * Makes a vertex buffer object.
 * You must call this function after makeVertArray.
 */
GLuint makeVertBuffer(GLfloat* vert_points, GLint vert_count, GLuint draw_state);

#endif // !VERT_H
