#include "texturedGrid.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


const texturedGrid::TexturedColoredVertex texturedGrid::textureGrid[] = {
	//Position											//color						//Texture
	TexturedColoredVertex(glm::vec3(-1.0f, 0.0f, -1.0f),	glm::vec3(0.0f, 1.0f,0.0f),	glm::vec2(0.0f, 0.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 0.0f, -1.0f),		glm::vec3(0.0f, 1.0f,0.0f),	glm::vec2(0.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(1.0f, 0.0f, 1.0f),		glm::vec3(0.0f, 1.0f,0.0f),	glm::vec2(1.0f, 1.0f)),
	TexturedColoredVertex(glm::vec3(-1.0f, 0.0f, 1.0f),		glm::vec3(0.0f, 1.0f,0.0f),	glm::vec2(1.0f, 0.0f)),
};

const int texturedGrid::indices[]{
	0, 1, 2,
	0, 2, 3
};

texturedGrid::texturedGrid() {

}

GLuint texturedGrid::loadTexture()
{
	// Step1 Create and bind textures
	GLuint textureId = 0;
	glGenTextures(1, &textureId);
	assert(textureId != 0);


	glBindTexture(GL_TEXTURE_2D, textureId);

	// Step2 Set filter parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEARST: associate pixel to closest color mapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //GL_LINEAR: interpolates and weight all the color close to the pixel

	//Mipmap -> adjust texture to model size in far distances
	//texture = 256 * 256, 128 * 128, ... , 2 * 2, 1 * 1
	//Model = 200 * 200
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER," ") //Only MIN Filter as Mipmap is used to generate textures of far away objects
	// GL_NEAREST_MIPMAP_LINEAR : nearst mipmap and linear filtering
	// GL_LINEAR_MIPMAP_NEAREST : linear mipmap and nearest filtering


	// Step3 Load Textures with dimension data
	int width, height, nrChannels;
	unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
	if (!data)
	{
		std::cerr << "Error::Texture could not load texture file:" << filename << std::endl;
		return 0;
	}

	// Step4 Upload the texture to the GPU
	GLenum format = 0;
	if (nrChannels == 1)
		format = GL_RED;
	else if (nrChannels == 3)
		format = GL_RGB;
	else if (nrChannels == 4)
		format = GL_RGBA;
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height,
		0, format, GL_UNSIGNED_BYTE, data);

	glGenerateMipmap(GL_TEXTURE_2D); //pass buffer to generate mipmap once texture has been loaded

	// Step5 Free resources
	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
	return textureId;
}


int texturedGrid::createtextureGridVAO() {
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	// Upload Vertex Buffer to the GPU, keep a reference to it (vbo)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureGrid), textureGrid, GL_STATIC_DRAW);

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
		3,                   // size
		GL_FLOAT,            // type
		GL_FALSE,            // normalized?
		sizeof(texturedGrid::TexturedColoredVertex), // stride - each vertex contain 2 vec3 (position, color)
		(void*)0             // array buffer offset
	);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(texturedGrid::TexturedColoredVertex),
		(void*)sizeof(vec3)      // color is offseted a vec3 (comes after position)
	);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2,                            // attribute 2 matches aColor in Vertex Shader
		2,
		GL_FLOAT,
		GL_FALSE,
		sizeof(texturedGrid::TexturedColoredVertex),
		(void*)(2 * sizeof(vec3))      // uv is offseted a vec2 (comes after position)
	);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // VAO already stored the state we just defined, safe to unbind buffer
	glBindVertexArray(0); // Unbind to not modify the VAO

	return vao;
}

texturedGrid::~texturedGrid() {

}
