#include "LightCube.h"
#include "Student.h"

class LightSourceContainer : public Student {
public:
	LightSourceContainer(glm::vec3* lightSourcePosition);
	~LightSourceContainer();
	void setup();
	void draw(GLuint modelMatrixLocation);
	//int getVAO();

	glm::vec3 lightSourcePosition;
};