#ifndef PCH_H

#include <gl/GL.h>
#include <gl/GLU.h>

#endif

class COpenGLFunc {
public:
	static void DrawTriangle(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3);
	static void DrawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat density, GLenum drawMode);
	static void DrawSphere(GLfloat cx, GLfloat cy, GLfloat cz, GLfloat radius, GLfloat densityYaw, GLfloat densityRoll);
};