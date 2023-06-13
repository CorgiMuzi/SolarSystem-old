#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class CGLFunction {
public:
	void InitGL();
	void ReSizeGLScene(GLsizei width, GLsizei height);
	void DrawGLScene();
};