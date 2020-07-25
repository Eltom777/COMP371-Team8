#include "Grid.h"

const vec3 Grid::axis[] = {
	// position					        // color 
	//x-axis
	glm::vec3(0.0f,  0.0f, 0.0f),       glm::vec3(1.0f,  0.0f, 0.0f),
	glm::vec3(AXISLENGTH, 0.0f, 0.0f),  glm::vec3(1.0f,  0.0f, 0.0f),

	//y-axis
	glm::vec3(0.0f,  0.0f, 0.0f),       glm::vec3(0.0f,  1.0f, 0.0f),
	glm::vec3(0.0f, AXISLENGTH, 0.0f),  glm::vec3(0.0f,  1.0f, 0.0f),

	//z-axis
	glm::vec3(0.0f,  0.0f, 0.0f),       glm::vec3(0.0f,  0.0f, 1.0f),
	glm::vec3(0.0f, 0.0f, AXISLENGTH),  glm::vec3(0.0f,  0.0f, 1.0f),
};

Grid::Grid() {
	generateGrid();
}

void Grid::generateGrid() {

	int numOfColumns = (COLUMNS + 1) * 4;
	float offset = static_cast<float>(2) / static_cast <float>(COLUMNS); // normalise squares in grid -> normalise = 2 / Columns
	float counter = 0;
	//generate columns
	for (int i = 0; i < numOfColumns; i = i + 4) {
		grid[i] = glm::vec3(-1.0f + counter, 0.0f, 1.0f);
		grid[i + 1] = glm::vec3(1.0f, 1.0f, 1.0f);
		grid[i + 2] = glm::vec3(-1.0 + counter, 0.0f, -1.0f);
		grid[i + 3] = glm::vec3(1.0f, 1.0f, 1.0f);
		counter += offset;
	}

	counter = 0;
	//generate rows
	for (int i = numOfColumns; i < SIZEOFARRAY; i = i + 4) {
		grid[i] = glm::vec3(-1.0f, 0.0f, 1.0f - counter);
		grid[i + 1] = glm::vec3(1.0f, 1.0f, 1.0f);
		grid[i + 2] = glm::vec3(1.0, 0.0f, 1.0f - counter );
		grid[i + 3] = glm::vec3(1.0f, 1.0f, 1.0f);
		counter += offset;
	}
}

int Grid::createGridVAO() {
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	// Upload Vertex Buffer to the GPU, keep a reference to it (vbo)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(grid), grid, GL_STATIC_DRAW);


	glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
		3,                   // size
		GL_FLOAT,            // type
		GL_FALSE,            // normalized?
		2 * sizeof(glm::vec3), // stride - each vertex contain 2 vec3 (position, color)
		(void*)0             // array buffer offset
	);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
		3,
		GL_FLOAT,
		GL_FALSE,
		2 * sizeof(glm::vec3),
		(void*)sizeof(glm::vec3)      // color is offseted a vec3 (comes after position)
	);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // VAO already stored the state we just defined, safe to unbind buffer
	glBindVertexArray(0); // Unbind to not modify the VAO

	return vao;
}

int Grid::getNumberOfColumns()
{
	return COLUMNS;
}

int Grid::createAxisVAO() {
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	// Upload Vertex Buffer to the GPU, keep a reference to it (vbo)
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(axis), axis, GL_STATIC_DRAW);


	glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
		3,                   // size
		GL_FLOAT,            // type
		GL_FALSE,            // normalized?
		2 * sizeof(vec3), // stride - each vertex contain 2 vec3 (position, color)
		(void*)0             // array buffer offset
	);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
		3,
		GL_FLOAT,
		GL_FALSE,
		2 * sizeof(vec3),
		(void*)sizeof(glm::vec3)      // color is offseted a vec3 (comes after position)
	);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // VAO already stored the state we just defined, safe to unbind buffer
	glBindVertexArray(0); // Unbind to not modify the VAO

	return vao;
}

Grid::~Grid() {

}