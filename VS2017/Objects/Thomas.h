#include "LetterO.h"
#include "Number3.h"
#include "Student.h"

class Thomas : public Student {
public :
	Thomas();
	~Thomas();
	void setup();
	void draw(GLuint modelMatrixLocation);
	//int getVAO();
};