#include "LetterI.h"
#include "Number3.h"
#include "Student.h"

class Anissa : public Student
{
public: 
	Anissa();
	~Anissa();
	void setup();
	void draw(GLuint modelMatrixLocation);
	//int getVAO();
};