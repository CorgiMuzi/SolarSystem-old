#include "pch.h"
#include "OpenGLFunc.h"
#include <vector>

#define PI 3.14159265358979323846

using std::vector;
using std::pair;
using std::make_pair;

void COpenGLFunc::DrawTriangle( GLfloat x1, GLfloat y1, GLfloat z1,
								GLfloat x2, GLfloat y2, GLfloat z2,
								GLfloat x3, GLfloat y3, GLfloat z3 ) 
{
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(x1, y1, z1);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(x2, y2, z2);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x3, y3, z3);
	glEnd();
}

/// <summary>
/// Draw a circle
/// </summary>
/// <param name="x">x position of the center of the circle</param>
/// <param name="y">y position of the center of the circle</param>
/// <param name="radius">radius value of the circle</param>
/// <param name="density">how smooth the circle's edge would be</param>
/// <param name="drawMode">message to gdi how to draw the circle -> GL_TRIANGLE_FAN | GL_LINE_LOOP</param>
void COpenGLFunc::DrawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat density, GLenum drawMode) {
	float theta = 2 * PI / density;
	vector<pair<float, float>> vertices;
	vertices.push_back(make_pair(0, 0));

	for (int i = 0; i < density; ++i) {
		float vx = radius * sin(i * theta);
		float vy = radius * cos(i * theta);

		vertices.push_back(make_pair(vx, vy));
	}

	glColor3f(0.8f, 0.0f, 0.5f);
	glBegin(drawMode);
	for (vector<pair<float, float>>::size_type v_idx = 1; v_idx < vertices.size() - 1; ++v_idx) {
		glVertex2f(vertices[0].first, vertices[0].second);
		glVertex2f(vertices[v_idx].first, vertices[v_idx].second);
		glVertex2f(vertices[v_idx + 1].first, vertices[v_idx + 1].second);
	}

		glVertex2f(vertices[0].first, vertices[0].second);
		glVertex2f(vertices[vertices.size() - 1].first, vertices[vertices.size() - 1].second);
		glVertex2f(vertices[1].first, vertices[1].second);
	glEnd();
}

void COpenGLFunc::DrawSphere(void) {

}