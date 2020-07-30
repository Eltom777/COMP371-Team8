#include "AlphaNumeric.h"
#include <iostream>
#include "Shader.h"
#include "Object.h"
#include <GLFW/glfw3.h>

mat4 AlphaNumeric::getModelMatrix() {
	return modelMatrix;
}

AlphaNumeric::AlphaNumeric(int numOfBotCubes, int numOfTopCubes, bool isLetter) {
	//numberOfCubes = numOfCubes;
	//components = new Cube[numberOfCubes];
	numberOfTopCubes = numOfTopCubes;
	numberOfBotCubes = numOfBotCubes;
	topComponents = new Cube[numberOfTopCubes + 2]; // +2 to allow space ??? I'm not sure why it does not work without it
	bottomComponents = new Cube[numberOfBotCubes + 2];
	base = NULL;
	baseTop = NULL;
	this->isLetter = isLetter;
	if (isLetter) {
		filename = "../Assets/Textures/Wood.jpg";
	}
	else {
		filename = "../Assets/Textures/Metal.jpg";
	}
}

void AlphaNumeric::updateBase(Cube* b)
{
	this->base = b;
}

Cube* AlphaNumeric::getBase()
{
	return this->base;
}

void AlphaNumeric::updateBaseTop(Cube * b)
{
	this->baseTop = b;
}

Cube * AlphaNumeric::getBaseTop()
{
	return this->baseTop;
}

void AlphaNumeric::traverse(mat4 mat, int transformation)
{
	traverse(mat, getBase(), transformation);
}

void AlphaNumeric::traverse(mat4 mat, Cube* current, int transformation)
{
	if (current == NULL)
	{
		std::cout << "returning";
		return;
	}

	// do whatever you wanna do here before moving on to next child
	if (transformation == 0)
	{
		current->updateTranslation(mat);
	}
	if (transformation == 1)
	{
		current->updateRotation(mat);
	}
	if (transformation == 2)
	{
		current->updateScale(mat);
	}

	// move to next child
	if (current->getChild())
	{
		traverse(mat, current->getChild(), transformation);
	}
}

void AlphaNumeric::scaleModel(mat4 s)
{
	//Place back to origin
	vec3 translationComponent = vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
	mat4 tempworldMatrix = translate(mat4(1.0), translationComponent * -1.0f); //place back to origin
	translateModel(tempworldMatrix);

	modelMatrix = s * modelMatrix;
	translateModel(s);

	//Place back to original spot
	tempworldMatrix = translate(mat4(1.0), translationComponent);
	translateModel(tempworldMatrix);
}

void AlphaNumeric::rotateModel(mat4 r, GLuint worldMatrixLocation)
{
	////Place back to origin
	vec3 translationComponent = vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]);
	mat4 tempworldMatrix = translate(mat4(1.0), translationComponent * -1.0f); //place back to origin
	translateModel(tempworldMatrix);

	//modelMatrix = r * modelMatrix;
	//translateModel(r);

	//Place back to original spot
	tempworldMatrix = translate(mat4(1.0), translationComponent);
	translateModel(tempworldMatrix);
}

void AlphaNumeric::translateModel(mat4 t)
{
	modelMatrix = t * modelMatrix;
	
	for (int i = 0; i < numberOfTopCubes; i++) {
		topComponents[i].updateTranslation(t);
	}
	for (int i = 0; i < numberOfBotCubes; i++) {
		bottomComponents[i].updateTranslation(t);
	}
}

void AlphaNumeric::translateModelTop(mat4 t)
{
	modelMatrix = t * modelMatrix;

	for (int i = 0; i < numberOfTopCubes; i++) {
		topComponents[i].updateTranslation(t);
	}
}

//void AlphaNumeric::

void AlphaNumeric::updateModelMatrix() {
	modelMatrix = translationMatrix * scalingMatrix * rotationMatrix * modelMatrix;
}
void AlphaNumeric::draw(Shader* shaderProgram, Shader* shadowShader, const bool isTexture, const bool isShadow, Shadow* shadowPtr, GLFWwindow* window) {

	shaderProgram->use();
	shaderProgram->setBool("isShadow", true);
	
	if (isLetter) {
		shaderProgram->setInt("textureType", 0);
	}
	else {
		shaderProgram->setInt("textureType", 2);
	}
	
	if (isTexture) {
		
		shaderProgram->setBool("isTexture", isTexture);

		if (isLetter) {
			glActiveTexture(GL_TEXTURE2);
		}
		else {
			glActiveTexture(GL_TEXTURE3);
		}
		//bind texture
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureId);
		//glUniform1i(shaderProgram->getLocation("textureSampler"), 0);
	}

	if(isShadow){
	//// Render shadow in 2 passes: 1- Render depth map, 2- Render scene
    //// 1- Render shadow map:
    //// a- use program for shadows
    //// b- resize window coordinates to fix depth map output size
    //// c- bind depth map framebuffer to output the depth values
    //{
    // Use proper shader
     //glUseProgram(shadowshader);
		shadowShader->use();		
      // Use proper image output size
      glViewport(0, 0, shadowPtr->DEPTH_MAP_TEXTURE_SIZE, shadowPtr->DEPTH_MAP_TEXTURE_SIZE);
     // Bind depth map texture as output framebuffer
      glBindFramebuffer(GL_FRAMEBUFFER, shadowPtr->depth_map_fbo);
      // Clear depth data on the framebuffer
      glClear(GL_DEPTH_BUFFER_BIT);
      // Bind geometry
      glBindVertexArray(cubeVAO);
      // Draw geometry
      //glDrawElements(GL_TRIANGLES, activeVertices, GL_UNSIGNED_INT, 0);
      glDrawArrays(GL_TRIANGLES, 0, 36);
      // Unbind geometry
      glBindVertexArray(0);
    //}

    //// 2- Render scene: a- bind the default framebuffer and b- just render like
    //// what we do normally
    //{
    //  // Use proper shader
    	shaderProgram->use();
    //  // Use proper image output size
    //  // Side note: we get the size from the framebuffer instead of using WIDTH
    //  // and HEIGHT because of a bug with highDPI displays
    	int width, height;
    	glfwGetFramebufferSize(window, &width, &height);
    	glViewport(0, 0, width, height);
    	// Bind screen as output framebuffer
    	glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //  // Clear color and depth data on framebuffer
    	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //  // Bind depth map texture: not needed, by default it is active
    	 glActiveTexture(GL_TEXTURE0);
    //  // Bind geometry
    //  
    //}
    ///**/
	}

	// Disable blending
	glDisable(GL_BLEND);

	//bind vao
	glBindVertexArray(cubeVAO);

	drawTop(shaderProgram);
	drawBottom(shaderProgram);
}
void AlphaNumeric::drawTop(Shader* shaderProgram) {
	for (int i = 0; i < numberOfTopCubes; i++) {
		shaderProgram->setMat4("worldMatrix", topComponents[i].getModelMatrix());//setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

void AlphaNumeric::drawBottom(Shader* shaderProgram) {
	for (int i = 0; i < numberOfBotCubes; i++) {
		shaderProgram->setMat4("worldMatrix", bottomComponents[i].getModelMatrix());//setting modelmatrix of each cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

void AlphaNumeric::create() {
	cubeVAO = components[0].createCubeVAO();
	textureId = loadTexture(filename);
}

void AlphaNumeric::randomLocation(float x, float z)
{
	mat4 t = glm::translate(mat4(1.0), glm::vec3(x, 0.0f, z));
	modelMatrix = t * modelMatrix;

	/*for (int i = 0; i < numberOfCubes; i++) {
		components[i].updateTranslation(t);
	}*/

	for (int i = 0; i < numberOfTopCubes; i++) {
		topComponents[i].updateTranslation(t);
	}
	for (int i = 0; i < numberOfBotCubes; i++) {
		bottomComponents[i].updateTranslation(t);
	}

}

AlphaNumeric::~AlphaNumeric() {
	//delete[] components;
	delete[] topComponents;
	delete[] bottomComponents;
}
