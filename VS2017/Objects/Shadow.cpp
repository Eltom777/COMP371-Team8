#include "Shadow.h"


Shadow::Shadow()
{
	setupBuffer();
}

void Shadow::setupBuffer()
{
	// Setup texture and framebuffer for creating shadow map
	GLuint FramebufferName = 0;
	glGenFramebuffers(1, &FramebufferName);
	glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

	// Depth texture. Slower than a depth buffer, but you can sample it later in your shader
	GLuint depthTexture;
	glGenTextures(1, &depthTexture);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);

	glDrawBuffer(GL_NONE); // No color buffer is drawn to.

	// check if buffer is set
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
		isSet = true;
}

void Shadow::setupLight(Shader* shaderProgram)
{
	// Light parameters for shadow rendering
	vec3 lightDirection = normalize(light.lightFocus - light.lightSourcePosition);


	mat4 lightProjMatrix = //frustum(-1.0f, 1.0f, -1.0f, 1.0f, lightNearPlane, lightFarPlane);
		perspective(50.0f, (float)DEPTH_MAP_TEXTURE_SIZE / (float)DEPTH_MAP_TEXTURE_SIZE, light.lightNearPlane, light.lightFarPlane);
	mat4 lightViewMatrix = lookAt(light.lightSourcePosition, light.lightFocus, vec3(0, 1, 0));
	mat4 lightSpaceMatrix = lightProjMatrix * lightViewMatrix;

	//Send uniforms to shader
	shaderProgram->setMat4("light_proj_view_matrix", lightSpaceMatrix);
	shaderProgram->setFloat("light_near_plane", light.lightNearPlane);
	shaderProgram->setFloat("light_far_plane", light.lightFarPlane);
	shaderProgram->setVec3("light_position", light.lightSourcePosition);
	shaderProgram->setVec3("light_direction", lightDirection);
}


Shadow::~Shadow()
{
}
