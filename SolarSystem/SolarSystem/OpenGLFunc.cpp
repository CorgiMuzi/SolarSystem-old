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

void COpenGLFunc::DrawSphere(GLfloat cx, GLfloat cy, GLfloat cz, GLfloat radius, GLfloat densityYaw, GLfloat densityRoll) {
	// 임의의 값 넣어놓기
	radius = 0.5f;
	densityYaw = densityRoll = 6.0f;

	float thetaYaw = 2 * (float)PI / densityYaw;
	float thetaRoll = 2 * (float)PI / densityRoll;

	vector<vector3f> vertices;
	// 제일 위의 정점 추가
	//vertices.push_back(vector3f(0.0f, radius, 0.0f));

	for (int h = 0; h <= densityRoll; ++h) {
		float sphereY = cy + radius * cosf(thetaRoll * h);
		float subRadius = radius * sinf(thetaRoll * h);
		for (int c = 0; c <= densityYaw; ++c) {
			float sphereX = cx + subRadius * sinf(thetaYaw * c);
			float sphereZ = cz + subRadius * cosf(thetaYaw * c);

			vertices.push_back(vector3f(sphereX, sphereY, sphereZ));
		}
	}

	// 제일 아래의 정점 추가
	//vertices.push_back(vector3f(0.0f, -radius, 0.0f));

	
	glPointSize(5.0f);
	glColor3f(0.8f, 0.0f, 0.5f);
	glBegin(GL_POINTS);
	for (vector<int>::size_type i = 2; i <= densityYaw; ++i) {
		
	}

	for (vector<int>::size_type i = densityYaw + 1; i < vertices.size() - (1 + densityYaw); ++i) {

	}

	for (vector<int>::size_type i = vertices.size() - densityYaw; i + 2 < vertices.size(); ++i) {

	}
	glEnd();
}
