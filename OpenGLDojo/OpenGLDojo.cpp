// OpenGLDojo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <GL/glut.h>

#define APP_TITLE "OpenGLDojo"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(1, //angle
        0, 0, 1 // axis, z
    );
    glutWireTeapot(1);
    // glFlush();
    glutSwapBuffers();
}
void timer(int v)
{
    glutPostRedisplay();

    glutTimerFunc(1000/60, timer, 0);
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(640, 0);
    glutInitWindowSize(640, 640);
    glutCreateWindow(APP_TITLE);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
}
