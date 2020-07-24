#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>

using namespace glm;

const int COLUMNS = 100;
const int SIZEOFGRID = COLUMNS * COLUMNS;
const int SIZEOFARRAY = (COLUMNS + COLUMNS + 2) * 4; //Total # of vertices -> (number of columns + rows + 2 to close grid) * 2 (two points for a line) * 2 to add color
const float AXISLENGTH = static_cast<float>(10) / static_cast <float>(COLUMNS); // 5 * normalise -> normalise = 2 / Columns

class Grid {
	const char* filename = "../Assets/Textures/brick.jpg";

	const struct TexturedColoredVertex
	{
		TexturedColoredVertex(vec3 _position, vec3 _color, vec2 _uv)
			: position(_position), color(_color), uv(_uv) {}

		vec3 position;
		vec3 color;
		vec2 uv;
	};
private:
    static const vec3 axis[];
	static const TexturedColoredVertex textureGrid[];
	static const int indices[];
	vec3 grid[SIZEOFARRAY];
	GLuint gridVAO;
	GLuint axisVAO;
	GLuint textureGridVAO;
	GLuint textureID;
	mat4 modelMatrix = mat4(1.0f);
public:
	const int gridToPrint = SIZEOFARRAY >> 1;
	const int axisToPrint = 6;
	Grid();
	~Grid();
	void generateGrid();
	int createAxisVAO();
	int createGridVAO();
	int createtextureGridVAO();
	GLuint loadTexture();
	//void draw(GLuint worldMatrixLocation, bool isTexture);
};

