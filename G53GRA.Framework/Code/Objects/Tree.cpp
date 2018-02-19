#include "Tree.h"

string genRandSeq(int branchRate, int depth) {
	string randSeq;


	for (int i = 0; i < branchRate; i++) {
		int rndVal = round(rand() % 8);

		randSeq += "f";

		switch (rndVal) {
		case 0:
			randSeq += '+';
			break;
		case 1:
			randSeq += '-';
			break;
		case 2:
			randSeq += '^';
			break;
		case 3:
			randSeq += '&';
			break;
		case 4:
			randSeq += '<';
			break;
		case 5:
			randSeq += '>';
			break;
		case 6:
			randSeq += '|';
			break;
		}

		if (depth > 0)
			randSeq += 'g' + genRandSeq(branchRate, depth - 1) + 'h';
	}

	return randSeq;
}

Tree::Tree() {
	sequence = genRandSeq(2, 5);
	angle = rand() % 90;

}

Tree::Tree(string seq, float branchAngle) 
	: sequence(seq), angle(branchAngle)
{
}

void Tree::branch() {
	float res = 0.1f*M_PI;                  // resolution (in radians: equivalent to 18 degrees)
	float r = 0.15f;                        // ratio of radius to height
	float x = r, z = 0.f;                   // initialise x and z on right of cylinder centre
	float t = 0.f;                          // initialise angle as 0

	do
	{                                     // create branch with multiple QUADS
		glBegin(GL_LINE_LOOP);
		// Create first points
		glVertex3f(x, 0.f, z);          // bottom
		glVertex3f(x, 1.f, z);          // top
										// Iterate around circle
		t += res;                       // add increment to angle
		x = r*cos(t);                   // move x and z around circle
		z = r*sin(t);
		// Close quad
		glVertex3f(x, 1.f, z);          // top
		glVertex3f(x, 0.f, z);          // bottom
		glEnd();
	} while (t <= 2 * M_PI);                // full rotation around circle

	glTranslatef(0.f, 1.f, 0.f);            // translate to top of branch
}

void Tree::Display() {
	glTranslatef(pos[0], pos[1], pos[2]);
	//glScalef(scale[0], scale[1], scale[2]);
	glScalef(100, 100, 100);

	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);

	glColor3f(0.f, 0.f, 0.f);

	for (unsigned int i = 0; i < sequence.size(); i++) {
		switch (sequence[i])
		{
		case 'f':
			branch();
			break;
		case 'g':
			glPushMatrix();
			break;
			case 'h':
				glPopMatrix();
				break;
		case '+':
			glRotatef(-angle, 0.f, 0.f, 1.f);
			break;
		case '-':
			glRotatef(angle, 0.f, 0.f, 1.f);
			break;
		case '^':
			glRotatef(-angle, 1.f, 0.f, 0.f);
			break;
		case '&':
			glRotatef(angle, 1.f, 0.f, 0.f);
			break;
		case '<':
			glRotatef(-angle, 0.f, 1.f, 0.f);
			break;
		case '>':
			glRotatef(angle, 0.f, 1.f, 0.f);
			break;
		case '|':
			glRotatef(180.f, 0.f, 1.f, 0.f);
			break;
		}
	}
}