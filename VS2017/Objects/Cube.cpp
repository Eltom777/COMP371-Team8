#include "Cube.h"

// All sides of cube are 1.0f

const glm::vec3 Cube::vertices[] = {

	// Colored cube for testing :)
	// front face
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(1.0f, -1.0f, -1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(1.0f, 1.0f, -1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(1.0f, 1.0f, -1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(-1.0f, 1.0f, -1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),

	// back face
	glm::vec3(-1.0f, -1.0f, 1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(1.0f, -1.0f, 1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(-1.0f, 1.0f, 1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),
	glm::vec3(-1.0f, -1.0f, 1.0f),
	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),

	// left face
	glm::vec3(-1.0f, 1.0f, 1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(-1.0f, 1.0f, -1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(-1.0f, -1.0f, 1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(-1.0f, 1.0f, 1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),

	// right face
	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(1.0f, 1.0f, -1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(1.0f, -1.0f, -1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(1.0f, -1.0f, -1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(1.0f, -1.0f, 1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),
	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),

	// bottom face
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(1.0f, -1.0f, -1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(1.0f, -1.0f, 1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(1.0f, -1.0f, 1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(-1.0f, -1.0f, 1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),

	// top face
	glm::vec3(-1.0f, 1.0f, -1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(1.0f, 1.0f, -1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(-1.0f, 1.0f, 1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),
	glm::vec3(-1.0f, 1.0f, -1.0f),
	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),

};

Cube::Cube()
{
	rotationMatrix = mat4(1.0f);
	translationMatrix = mat4(1.0f);
	scalingMatrix = mat4(1.0f);
	//modelMatrix = glm::scale(mat4(1.0f), vec3(scalingFactor, scalingFactor, scalingFactor));
}

Cube::~Cube() {

}

mat4 Cube::getModelMatrix() {
	return modelMatrix;
}

void Cube::setModelMatrix()
{
	modelMatrix = translationMatrix * rotationMatrix * scalingMatrix * glm::scale(mat4(1.0f), vec3(scalingFactor, scalingFactor, scalingFactor));
}

void Cube::updateScale(mat4 s)
{
	scalingMatrix = s * scalingMatrix;
	setModelMatrix();
}

void Cube::updateRotation(mat4 r)
{
	rotationMatrix = r * rotationMatrix;
	setModelMatrix();
}

void Cube::updateTranslation(mat4 t)
{
	translationMatrix = t * translationMatrix;
	setModelMatrix();
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


