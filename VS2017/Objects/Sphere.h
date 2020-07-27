#pragma once
#include "Grid.h"
#include <vector>
#include <string>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

class Sphere {
public:
	Sphere();
	~Sphere();
	void setup();
	mat4 getModelMatrix();
	void updateModelMatrix();
	void translateModel(mat4 t);
	void scaleModel(mat4 s);
	void rotateModel(mat4 r);
	void draw(GLuint worldMatrixLocation, int sphereVertices);
	GLuint createSphereVAO(std::string path, int& vertexCount);
private:
	mat4 modelMatrix = mat4(1.0f);
	mat4 translationMatrix = mat4(1.0f);
	mat4 scalingMatrix = mat4(1.0f);
	mat4 rotationMatrix = mat4(1.0f);
	Grid gridPointer;
	float scalingFactor = 1.0f / static_cast <float>(gridPointer.getNumberOfColumns());
};