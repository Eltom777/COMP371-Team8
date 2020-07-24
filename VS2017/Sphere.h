#pragma once
#include "Grid.h"
#include<vector>
#include <glm/gtc/matrix_transform.hpp>

class Sphere {

	// cols = sectors = longitude, rows = stacks = latitude
	static const int RADIUS = 1;
	static const int COLS = 72;
	static const int ROWS = 24;
	static const int SIZEOFVERTICES = 3650; 
	// got this size from making the vector then counting how many things i added to it
	// i'm stupid i don't know math

public:
	Sphere();
	~Sphere();
	void setup();
	mat4 getModelMatrix();
	void updateModelMatrix();
	void translateModel(mat4 t);
	void scaleModel(mat4 s);
	void rotateModel(mat4 r);
	int createSphereVAO();
	void draw(GLuint modelLocation);

private:

	// generated procedurally in the cpp
	std::vector<glm::vec3> verticesVec;
	
	glm::vec3 vertices[SIZEOFVERTICES];

	mat4 modelMatrix = mat4(1.0f);
	mat4 translationMatrix = mat4(1.0f);
	mat4 scalingMatrix = mat4(1.0f);
	mat4 rotationMatrix = mat4(1.0f);
	Grid gridPointer;
	float scalingFactor = 1.0f / static_cast <float>(gridPointer.getNumberOfColumns());;

};