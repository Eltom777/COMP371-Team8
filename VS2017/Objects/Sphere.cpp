#include "Sphere.h"
#include "Cube.h"
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
	child = NULL;
	setup();
}

Sphere::~Sphere() {
	
}

void Sphere::setup() {
	scaleModel(glm::scale(mat4(1.0), glm::vec3(0.2f, 0.2f, 0.2f)));
	translateModel(glm::translate(mat4(1.0), glm::vec3(0.0f, 0.1f, 0.0f)));
	string spherePath = "../Assets/Models/sphere.obj";
	sphereVAO = createSphereVAO(spherePath);
}

void Sphere::updateModelMatrix() {
	modelMatrix = translationMatrix * rotationMatrix * scalingMatrix /** glm::scale(mat4(1.0f), vec3(scalingFactor, scalingFactor, scalingFactor))*/;
}

void Sphere::translateModel(mat4 t) {
	translationMatrix = t * translationMatrix;
	updateModelMatrix();
}

void Sphere::scaleModel(mat4 s) {
	scalingMatrix = s * scalingMatrix;
	updateModelMatrix();
}

void Sphere::rotateModel(mat4 r) {
	rotationMatrix = r * rotationMatrix;
	updateModelMatrix();
}

mat4 Sphere::getModelMatrix() {
	return modelMatrix;
}

void Sphere::updateChild(Cube* c)
{
	this->child = c;
}

Cube* Sphere::getChild()
{
	return this->child;
}

//void Sphere::draw(GLuint worldMatrixLocation, int sphereVertices) {
//	glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
//	glDrawElements(GL_TRIANGLES, sphereVertices, GL_UNSIGNED_INT, 0);
//	glBindVertexArray(0);
//}

void Sphere::draw(Shader* shaderProgram) {
	shaderProgram->use();

	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	// bind VAO
	glBindVertexArray(sphereVAO);

	//draw textured grid
	glDrawElements(GL_TRIANGLES, sphereVertices, GL_UNSIGNED_INT, 0);

	//Unbind VAO
	glBindVertexArray(0);
}

//Sets up a model using an Element Buffer Object to refer to vertex data
GLuint Sphere::createSphereVAO(std::string path)
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
	sphereVertices = vertexIndices.size();
	return VAO;
}