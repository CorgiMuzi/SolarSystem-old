#include "pch.h"
#include "glFunction.h"

void CGLFunction::InitGL() {
	glClearColor(0.f, 0.f, 0.f, 0.5f);
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void CGLFunction::ReSizeGLScene(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.f, (GLfloat)(width / height), 0.1f, 1000.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void CGLFunction::DrawGLScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.f, 0.f, 3.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);

	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5f, 0.f, 0.f);
	glVertex3f(0.0f, 0.5f, 0.f);
	glVertex3f(-0.5f, 0.f, 0.f);
	glEnd();
	
}