#include "Sphere.h"
#include <vector>
#include <cmath>
#include <iostream>
#include "../Source/OBJloaderV2.h"  //For loading .obj files using a polygon list format

using namespace std;

Sphere::Sphere() {
	modelMatrix = mat4(1.0f);
	rotationMatrix = mat4(1.0f);
	translationMatrix = mat4(1.0f);
	scalingMatrix = mat4(1.0f);
	setup();
}

Sphere::~Sphere() {
	
}

void Sphere::setup() {

	scaleModel(glm::scale(mat4(1.0), glm::vec3(0.2f, 0.2f, 0.2f)));
	translateModel(glm::translate(mat4(1.0), glm::vec3(0.0f, 0.5f, 0.0f)));

	//const float PI = acos(-1);

	//glm::vec3 white = glm::vec3(1.0f, 0.0f, 0.0f);

	//float x, y, z, xy;

	//float colStep = 2 * PI / COLS;
	//float rowStep = PI / ROWS;
	//float colAngle, rowAngle;

	//int pos = 0;

	//for (int i = 0; i <= ROWS; ++i) {
	//	
	//	// calculate data for the current row
	//	rowAngle = PI / 2 - i * rowStep;
	//	xy = RADIUS * cosf(rowAngle);
	//	z = RADIUS * sinf(rowAngle);

	//	for (int j = 0; j <= COLS; ++j) {
	//		
	//		colAngle = j * colStep;

	//		// vertex positions
	//		x = xy * cosf(colAngle);
	//		y = xy * sinf(colAngle);

	//		verticesVec.push_back(glm::vec3(x, y, z));
	//		verticesVec.push_back(white);

	//		vertices[pos] = glm::vec3(x, y, z);
	//		pos += 1;
	//		vertices[pos] = white;
	//		pos += 1;
	//	}
	//}
}

void Sphere::updateModelMatrix() {
	modelMatrix = translationMatrix * rotationMatrix * scalingMatrix * glm::scale(mat4(1.0f), vec3(scalingFactor, scalingFactor, scalingFactor));
}

void Sphere::translateModel(mat4 t) {
	modelMatrix = t * modelMatrix;
	//updateModelMatrix();
}

void Sphere::scaleModel(mat4 s) {
	modelMatrix = s * modelMatrix;
	//updateModelMatrix();
}

void Sphere::rotateModel(mat4 r) {
	modelMatrix = r * modelMatrix;
	//updateModelMatrix();
}

mat4 Sphere::getModelMatrix() {
	return modelMatrix;
}

void Sphere::draw(GLuint worldMatrixLocation, int sphereVAO, int sphereVertices) {
	glBindVertexArray(sphereVAO);
	glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereVertices, GL_UNSIGNED_INT, 0);
}

//Sets up a model using an Element Buffer Object to refer to vertex data
GLuint Sphere::createSphereVAO(std::string path, int& vertexCount)
{
	vector<int> vertexIndices; //The contiguous sets of three indices of vertices, normals and UVs, used to make a triangle
	vector<glm::vec3> vertices;
	vector<glm::vec3> normals;
	vector<glm::vec2> UVs;

	//read the vertices from the cube.obj file
	//We won't be needing the normals or UVs for this program
	loadOBJ2(path.c_str(), vertexIndices, vertices, normals, UVs);

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO); //Becomes active VAO
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).

	//Vertex VBO setup
	GLuint vertices_VBO;
	glGenBuffers(1, &vertices_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertices_VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//Normals VBO setup
	GLuint normals_VBO;
	glGenBuffers(1, &normals_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, normals_VBO);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);

	//UVs VBO setup
	GLuint uvs_VBO;
	glGenBuffers(1, &uvs_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, uvs_VBO);
	glBufferData(GL_ARRAY_BUFFER, UVs.size() * sizeof(glm::vec2), &UVs.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(2);

	//EBO setup
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexIndices.size() * sizeof(int), &vertexIndices.front(), GL_STATIC_DRAW);

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO
	vertexCount = vertexIndices.size();
	return VAO;
}