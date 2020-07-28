#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "Grid.h"

class Cube {
public:
	const struct TexturedColoredVertex
	{
		TexturedColoredVertex(vec3 _position, vec3 _color, vec2 _uv)
			: position(_position), color(_color), uv(_uv) {}

		vec3 position;
		vec3 color;
		vec2 uv;
	};
	Cube();
	~Cube();
	mat4 getModelMatrix();
	void setModelMatrix();
	int createCubeVAO();
	void updateScale(mat4 s);
	void updateRotation(mat4 r);
	void setTranslation(vec3 t);
	void updateTranslation(mat4 t);

	//void updateChild(Cube* c, Sphere* s);
	void updateChild(Cube* c);
	//void getChild();
	Cube* getChild();
	//Sphere* getSphereChild();
	Cube* cubeChild;
	//Sphere* sphereChild;
	//Cube* sibling;
private:
	static const TexturedColoredVertex vertices[];
	mat4 modelMatrix;
	mat4 rotationMatrix;
	mat4 translationMatrix;
	mat4 scalingMatrix;
	Grid gridPointer;
	float scalingFactor = 1.0f / static_cast <float>(gridPointer.getNumberOfColumns());
};

