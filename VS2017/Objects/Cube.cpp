#include "Cube.h"

// All sides of cube are 1.0f

const Cube::TexturedColoredVertex Cube::vertices[] = {

	// Colored cube for testing :)
	// front face
	//Position												//color														//Texture
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, -1.0f),	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(0.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, -1.0f, -1.0f),	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(1.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, -1.0f),		glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, -1.0f),		glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, 1.0f, -1.0f),	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(0.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, -1.0f),	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(0.0f, 0.0f)),

	// back face
	//Position												//color														//Texture
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, 1.0f),	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(0.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, -1.0f, 1.0f),		glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(1.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, 1.0f, 1.0f),		glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(0.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, 1.0f),	glm::vec3(0.06666666666f, 0.61568627451f, 0.6431372549f),	glm::vec2(0.0f, 0.0f)),


	// left face
	//Position												//color														//Texture
	TexturedColoredVertex(glm::vec3(-1.0f, 1.0f, 1.0f), 	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(0.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, 1.0f, -1.0f),	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(1.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, -1.0f),	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, -1.0f),	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, 1.0f),	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(0.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, 1.0f, 1.0f),		glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(0.0f, 0.0f)),

	// right face
	//Position												//color														//Texture
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, 1.0f), 		glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(0.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, -1.0f),		glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(1.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, -1.0f, -1.0f),	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, -1.0f, -1.0f),	glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, -1.0f, 1.0f),		glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(0.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec3(0.66274509803f, 0.98431372549f, 0.76470588235f),	glm::vec2(0.0f, 0.0f)),


	// bottom face
	//Position												//color														//Texture
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, -1.0f), 	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(0.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, -1.0f, -1.0f),	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(1.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, -1.0f, 1.0f),		glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, -1.0f, 1.0f),		glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, 1.0f),	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(0.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, -1.0f, -1.0f),	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(0.0f, 0.0f)),


	// top face
	//Position												//color														//Texture
	TexturedColoredVertex(glm::vec3(-1.0f, 1.0f, -1.0f), 	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(0.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, -1.0f),		glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(1.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 1.0f, 1.0f),		glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, 1.0f, 1.0f),		glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(0.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, 1.0f, -1.0f),	glm::vec3(0.70980392156f, 0.58039215686f, 0.71372549019f),	glm::vec2(0.0f, 0.0f)),
};

Cube::Cube()
{
	modelMatrix = mat4(1.0f);
	rotationMatrix = mat4(1.0f);
	translationMatrix = mat4(1.0f);
	scalingMatrix = mat4(1.0f);
	//modelMatrix = glm::scale(mat4(1.0f), vec3(scalingFactor, scalingFactor, scalingFactor));

	cubeChild = NULL;
	//sibling = NULL;
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

void Cube::setTranslation(vec3 t)
{
	translationMatrix[3][0] = t[0];
	translationMatrix[3][1] = t[1];
	translationMatrix[3][2] = t[2];

	setModelMatrix();
}

void Cube::updateTranslation(mat4 t)
{
	translationMatrix = t * translationMatrix;
	setModelMatrix();
}

void Cube::updateChild(Cube* c)
{
	this->cubeChild = c;
}

Cube* Cube::getChild()
{
	return this->cubeChild;
}

int Cube::createCubeVAO() {
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	// Upload Vertex Buffer to the GPU, keep a reference to it (vbo)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
		3,                   // size
		GL_FLOAT,            // type
		GL_FALSE,            // normalized?
		sizeof(Cube::TexturedColoredVertex), // stride - each vertex contain 2 vec3 (position, color)
		(void*)0             // array buffer offset
	);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Cube::TexturedColoredVertex),
		(void*)sizeof(vec3)      // color is offseted a vec3 (comes after position)
	);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2,                            // attribute 2 matches aColor in Vertex Shader
		2,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Cube::TexturedColoredVertex),
		(void*)(2 * sizeof(vec3))      // uv is offseted a vec2 (comes after position)
	);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // VAO already stored the state we just defined, safe to unbind buffer
	glBindVertexArray(0); // Unbind to not modify the VAO

	return vao;
}


