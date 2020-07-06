#include "Ball.h"
#include "GL/glut.h"

void Ball::update(){
	m_lastposition = m_position;
	m_position += m_speed;
}
void Ball::draw() {
	glPushMatrix();
	{
		glTranslatef(m_position.x, m_position.y, 0);
		// no okuyuki
		glScalef(16, 16, 0);
		glutSolidSphere(
			1, // radius
			16, // slices
			16  // stacks
		);
	}
	glPopMatrix();
}
