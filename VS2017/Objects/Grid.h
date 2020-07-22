#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>

using namespace glm;

static const int COLUMNS = 100;
static const int SIZEOFGRID = COLUMNS * COLUMNS;
static const int SIZEOFARRAY = (COLUMNS + COLUMNS + 2) * 4; //Total # of vertices -> (number of columns + rows + 2 to close grid) * 2 (two points for a line) * 2 to add color
static const float AXISLENGTH = static_cast<float>(10) / static_cast <float>(COLUMNS); // 5 * normalise -> normalise = 2 / Columns

class Grid {


private:
    static const vec3 axis[];
	vec3 grid[SIZEOFARRAY];
	GLuint gridVAO;
	GLuint axisVAO;
public:
	const int gridToPrint = SIZEOFARRAY >> 1;
	const int axisToPrint = 6;
	Grid();
	~Grid();
	void generateGrid();
	int createAxisVAO();
	int createGridVAO();
	int getNumberOfColumns();
};

