#include "LetterL.h"
#include "Number9.h"
#include "Student.h"

class Melina : public Student {
public:
	Melina();
	~Melina();
	void setup();
	void draw(GLuint modelMatrixLocation);
	//int getVAO();
};