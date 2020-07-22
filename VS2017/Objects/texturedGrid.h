#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>

using namespace glm;

class texturedGrid 
{
	
	const int COLUMNS = 100;
	const float AXISLENGTH = static_cast<float>(10) / static_cast <float>(COLUMNS);
	const char* filename = "../Assets/Textures/brick.jpg";

	struct TexturedColoredVertex
	{
		TexturedColoredVertex(vec3 _position, vec3 _color, vec2 _uv)
			: position(_position), color(_color), uv(_uv) {}

		vec3 position;
		vec3 color;
		vec2 uv;
	};

private:
	static const TexturedColoredVertex textureGrid[];
	static const int indices[];
	GLuint gridVAO;
	GLuint textureID;
public:
	const int gridToPrint = 6;
	texturedGrid();
	~texturedGrid();
	int createtextureGridVAO();
	GLuint loadTexture();
};

