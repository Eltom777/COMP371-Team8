#include "Sphere.h"
#include <vector>
#include <cmath>
#include <iostream>

// referencing the tutorial & code from "http://www.songho.ca/opengl/gl_sphere.html"

Sphere::Sphere() {
	rotationMatrix = mat4(1.0f);
	translationMatrix = mat4(1.0f);
	scalingMatrix = mat4(1.0f);
	//setup();
}

Sphere::~Sphere() {
	
}

void Sphere::setup() {

	//const float PI = acos(-1);

	//glm::vec3 white = glm::vec3(1.0f, 0.0f, 0.0f);

	//float x, y, z, xy;

	//float colStep = 2 * PI / COLS;
	//float rowStep = PI / ROWS;
	//float colAngle, rowAngle;

	//int pos = 0;

	//for (int i = 0; i <= ROWS; ++i) {
	//	
	//	// calculate data for the current row
	//	rowAngle = PI / 2 - i * rowStep;
	//	xy = RADIUS * cosf(rowAngle);
	//	z = RADIUS * sinf(rowAngle);

	//	for (int j = 0; j <= COLS; ++j) {
	//		
	//		colAngle = j * colStep;

	//		// vertex positions
	//		x = xy * cosf(colAngle);
	//		y = xy * sinf(colAngle);

	//		verticesVec.push_back(glm::vec3(x, y, z));
	//		verticesVec.push_back(white);

	//		vertices[pos] = glm::vec3(x, y, z);
	//		pos += 1;
	//		vertices[pos] = white;
	//		pos += 1;
	//	}
	//}
}

void Sphere::updateModelMatrix() {
	modelMatrix = translationMatrix * rotationMatrix * scalingMatrix * glm::scale(mat4(1.0f), vec3(scalingFactor, scalingFactor, scalingFactor));
}

void Sphere::translateModel(mat4 t) {
	translationMatrix = t * translationMatrix;
	updateModelMatrix();
}

void Sphere::scaleModel(mat4 s) {
	scalingMatrix = s * scalingMatrix;
	updateModelMatrix();
}

void Sphere::rotateModel(mat4 r) {
	rotationMatrix = r * rotationMatrix;
	updateModelMatrix();
}

mat4 Sphere::getModelMatrix() {
	return modelMatrix;
}

void Sphere::draw(GLuint modelLocation) {
	glBindVertexArray(createSphereVAO());
	glDrawArrays(GL_LINES, 0, SIZEOFVERTICES >> 1);
}

int Sphere::createSphereVAO() {
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
		3,                   // size
		GL_FLOAT,            // type
		GL_FALSE,            // normalized?
		2 * sizeof(glm::vec3), // stride - each vertex contain 2 vec3 (position, color)
		(void*)0             // array buffer offset
	);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
		3,
		GL_FLOAT,
		GL_FALSE,
		2 * sizeof(glm::vec3),
		(void*)sizeof(glm::vec3)      // color is offseted a vec3 (comes after position)
	);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // VAO already stored the state we just defined, safe to unbind buffer
	glBindVertexArray(0); // Unbind to not modify the VAO

	return vao;

}