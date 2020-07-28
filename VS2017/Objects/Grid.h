#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <Shader.h>
#include "Objects.h"

using namespace glm;

static const int COLUMNS = 100;
static const int SIZEOFGRID = COLUMNS * COLUMNS;
static const int SIZEOFARRAY = (COLUMNS + COLUMNS + 2) * 4; //Total # of vertices -> (number of columns + rows + 2 to close grid) * 2 (two points for a line) * 2 to add color
static const float AXISLENGTH = static_cast<float>(10) / static_cast <float>(COLUMNS); // 5 * normalise -> normalise = 2 / Columns

class Grid : public Object {

	const char* filename = "../Assets/Textures/brick.jpg";

	const struct TexturedColoredVertex
	{
		TexturedColoredVertex(vec3 _position, vec3 _color, vec2 _uv)
			: position(_position), color(_color), uv(_uv) {}

		vec3 position;
		vec3 color;
		vec2 uv;
	};

public:
	const int gridToPrint = SIZEOFARRAY >> 1;
	const int axisToPrint = 6;
	Grid();
	~Grid();
	void setup();
	void generateGrid();
	int createAxisVAO();
	int createGridVAO();
	int getNumberOfColumns();
	int createtextureGridVAO();
	void drawGrid(Shader* shaderProgram, bool isTexture);
	void drawAxis(Shader shaderProgram);
private:
	static const vec3 axis[];
	vec3 grid[SIZEOFARRAY];
	GLuint gridVAO;
	GLuint axisVAO;
	GLuint textureGridVAO;
	GLuint textureId;
	mat4 modelMatrix = mat4(1.0f);
	static const TexturedColoredVertex textureGrid[];
	static const int indices[];
};

