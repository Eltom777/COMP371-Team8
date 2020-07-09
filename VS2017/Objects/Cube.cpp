#include "Cube.h"
#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
//using glm::mat4;
using std::vector;

const glm::vec3 Cube::vertices[] = {

	// front face
	glm::vec3(-0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f,  0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),

	// back face
	glm::vec3(-0.5f, -0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f, -0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f, -0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),

	// left face
	glm::vec3(-0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f,  0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f, -0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),

	// right face
	glm::vec3(0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f, -0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),

	// bottom face
	glm::vec3(-0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f, -0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f, -0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f, -0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f, -0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),

	// top face
	glm::vec3(-0.5f,  0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f,  0.5f,  0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f),
	glm::vec3(-0.5f,  0.5f, -0.5f),
	glm::vec3(1.0f,  1.0f, 1.0f)
};

Cube::Cube()
{
	this->index = 0;
	this->parent = nullptr;
	this->children = vector<Cube*>();
}

Cube::Cube(const Cube& cube, int i) {
	this->index = i;
	this->parent = nullptr;
	this->children = vector<Cube*>(cube.children.size());
	for (int i = 0; i < children.size(); i++)
	{
		Cube* child = new Cube(*cube.children[i]);
		child->parent = this;
		children[i] = child;
	}
}

Cube::~Cube() {
	for (Cube* child : children)
	{
		delete child;
	}
	children.clear();
	parent = nullptr;
}

int Cube::createCubeVAO() {
	// Create a vertex array
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	// Upload Vertex Buffer to the GPU, keep a reference to it (vertexBufferObject)
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

	glVertexAttribPointer(1,                  // attribute 1 matches aColor in Vertex Shader
		3,
		GL_FLOAT,
		GL_FALSE,
		2 * sizeof(glm::vec3),
		(void*)sizeof(glm::vec3)    // color is offseted a vec3 (comes after position)
	);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return vao;
}

//void Cube::render(glm::mat4 model, int vao) const {
//
//	//Render all children
//	for (Cube* child : children)
//	{
//		child->render(/*model,*/ vao);
//	}
//
//}

//glm::mat4 Cube::calculateModelMatrix(glm::mat4 translation, glm::mat4 rotation, glm::mat4 scale) const {
//
//	return translation * rotation * scale;
//
//}


