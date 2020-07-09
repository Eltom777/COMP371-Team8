#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <vector>
#include "Grid.h"
using namespace glm;


class Cube
{
public:
	Cube();
	Cube(const Cube& cube, int i);
	void setWorldMatrix(mat4 matrix);
	void concatWorldMatrix(mat4 tmatrix);
	mat4 getWorldMatrix();
	~Cube();

	int getIndex() const {
		return index; 
	}
	bool isRoot() const {
		return parent == nullptr;
	}
	Cube* getParent() const {
		return parent;
	}
	std::vector<Cube*> getChildren() const {
		return children;
	}

	int createCubeVAO();
	//void Cube::render(glm::mat4 model, int vao) const;
	//glm::mat4 calculateModelMatrix(glm::mat4 translation, glm::mat4 rotation, glm::mat4 scale) const;

private:
	static const glm::vec3 vertices[];
	int index;
	//GLuint cubeVAO;
	Cube* parent;
	std::vector<Cube*> children;
	mat4 worldMatrix;
	Grid scaleFactor;
};

