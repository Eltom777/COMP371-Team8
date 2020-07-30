#include "Shadow.h"


Shadow::Shadow()
{
	setupBuffer();
}

void Shadow::setupBuffer()
{
	// Setup texture and framebuffer for creating shadow map

  // Dimensions of the shadow texture, which should cover the viewport window
  // size and shouldn't be oversized and waste resources
  const unsigned int DEPTH_MAP_TEXTURE_SIZE = 1024;

  // Variable storing index to texture used for shadow mapping
  depth_map_texture;
  // Get the texture
  glGenTextures(1, &depth_map_texture);
  // Bind the texture so the next glTex calls affect it
  glBindTexture(GL_TEXTURE_2D, depth_map_texture);
  // Create the texture and specify it's attributes, including widthn height,
  // components (only depth is stored, no color information)
  glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, DEPTH_MAP_TEXTURE_SIZE,
               DEPTH_MAP_TEXTURE_SIZE, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
  // Set texture sampler parameters.
  // The two calls below tell the texture sampler inside the shader how to
  // upsample and downsample the texture. Here we choose the nearest filtering
  // option, which means we just use the value of the closest pixel to the
  // chosen image coordinate.
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  // The two calls below tell the texture sampler inside the shader how it
  // should deal with texture coordinates outside of the [0, 1] range. Here we
  // decide to just tile the image.
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // Variable storing index to framebuffer used for shadow mapping
  depth_map_fbo;  // fbo: framebuffer object
  // Get the framebuffer
  glGenFramebuffers(1, &depth_map_fbo);
  // Bind the framebuffer so the next glFramebuffer calls affect it
  glBindFramebuffer(GL_FRAMEBUFFER, depth_map_fbo);
  // Attach the depth map texture to the depth map framebuffer
  // glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
  // depth_map_texture, 0);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D,
                         depth_map_texture, 0);
  glDrawBuffer(GL_NONE);  // disable rendering colors, only write depth values

	// check if buffer is set
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
		isSet = true;
}

void Shadow::setupLight(Shader* shaderProgram, Shader* shadowShader)
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
																		 //model matrix (TODO maybe ?)
	shadowShader->setMat4("transform_in_light_space", lightSpaceMatrix * translate(mat4(1.0), light.lightSourcePosition));
}


Shadow::~Shadow()
{
}
