#include "pch.h"
#include "OpenGLFunc.h"
#include <vector>

#define PI 3.14159265358979323846

using std::vector;
using std::pair;
using std::make_pair;

struct vector3f {
private:
	float _x = 0, _y = 0, _z = 0;

public:
	vector3f(float x, float y, float  z) : _x(x), _y(y), _z(z) {	}
	const float& x = _x;
	const float& y = _y;
	const float& z = _z;
};

void COpenGLFunc::DrawTriangle(GLfloat x1, GLfloat y1, GLfloat z1,
	GLfloat x2, GLfloat y2, GLfloat z2,
	GLfloat x3, GLfloat y3, GLfloat z3)
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
	float theta = 2 * (float)PI / density;
	vector<pair<float, float>> vertices;
	vertices.push_back(make_pair(0, 0));

	for (int i = 0; i < density; ++i) {
		float vx = radius * sinf(i * theta);
		float vy = radius * cosf(i * theta);

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

/// <summary>
/// Draw a sphere
/// </summary>
/// <param name="cx">x position of the center of the sphere</param>
/// <param name="cy">y position of the center of the sphere</param>
/// <param name="cz">z position of the center of the sphere</param>
/// <param name="radius">the radius of the sphere</param>
/// <param name="densityYaw">the x-side density of the sphere</param>
/// <param name="densityRoll">the y-side density of the sphere</param>
void COpenGLFunc::DrawSphere(GLfloat cx, GLfloat cy, GLfloat cz, GLfloat radius, GLfloat densityYaw, GLfloat densityRoll) {
	vector<vector<vector3f>> vertices;
	vector3f top(cx, cy + radius, cz), bottom(cx, cy - radius, cz);
	vertices.push_back(vector<vector3f>(1, top));

	float yawTheta = (float)PI / densityYaw, rollTheta = (float)PI / densityRoll;

	GLfloat vx = 0, vy = 0, vz = 0;
	for (float roll = 0; roll <= 2 * (float)PI; roll += rollTheta) {
		vx = radius * cosf(roll);
		vy = radius * sinf(roll);
		vector<vector3f> rowVertices;
		for (float yaw = 0; yaw <= 2 * (float)PI; yaw += yawTheta) {
			vz = radius * sinf(yaw);

			rowVertices.push_back(vector3f(vx, vy, vz));
		}

		vertices.push_back(rowVertices);
	}


	vertices.push_back(vector<vector3f>(1, bottom));

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	for (vector<vector3f>::size_type i = 0; i < vertices[1].size(); ++i) {
		glVertex3f(vertices[0][0].x, vertices[0][0].y, vertices[0][0].z);
		glVertex3f(vertices[1][i].x, vertices[1][i].y, vertices[1][i].z);
		if (i + 1 == vertices[1].size()) {
			glVertex3f(vertices[1][0].x, vertices[1][0].y, vertices[1][0].z);
		}
		else {
			glVertex3f(vertices[1][i + 1].x, vertices[1][i + 1].y, vertices[1][i + 1].z);
		}
	}

	for (vector<vector3f>::size_type i = 0; i < vertices[vertices.size() - 2].size(); ++i) {
		glVertex3f(vertices[vertices.size() - 2][i].x, vertices[vertices.size() - 2][i].y, vertices[vertices.size() - 2][i].z);
		glVertex3f(vertices[vertices.size() - 1][0].x, vertices[vertices.size() - 1][0].y, vertices[vertices.size() - 1][0].z);
		if (i + 1 == vertices[vertices.size() - 2].size()) {
			glVertex3f(vertices[vertices.size() - 2][0].x, vertices[vertices.size() - 2][0].y, vertices[vertices.size() - 2][0].z);
		}
		else {
			glVertex3f(vertices[vertices.size() - 2][i + 1].x, vertices[vertices.size() - 2][i + 1].y, vertices[vertices.size() - 2][i + 1].z);
		}
	}
	glEnd();
}
