#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <Objects/Shader.h>
#include "Object.h"

using namespace glm;

static const int COLUMNS = 100;
static const int SIZEOFGRID = COLUMNS * COLUMNS;
static const int SIZEOFARRAY = (COLUMNS + COLUMNS + 2) * 4; //Total # of vertices -> (number of columns + rows + 2 to close grid) * 2 (two points for a line) * 2 to add color
static const float AXISLENGTH = static_cast<float>(10) / static_cast <float>(COLUMNS); // 5 * normalise -> normalise = 2 / Columns

class Grid {
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
};

