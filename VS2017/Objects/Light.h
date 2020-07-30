#pragma once
#include <glm\glm.hpp>

using namespace glm;

class Light
{
public:
	vec3 lightSourcePosition = vec3(0.0f, 3.0f, -1.0f);
	vec3 lightFocus = vec3(0.0f, 0.0f, 0.0f);
	float lightNearPlane = 0.01f;
	float lightFarPlane = 100.0f;
	vec3 objectColor = vec3(1.0f, 0.5f, 0.31f);
	vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

	Light() {};
	~Light() {};
};

