// OpenGLDojo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <GL/glut.h>

#define APP_TITLE "OpenGLDojo"

void display()
{
    glutWireTeapot(1);
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(640, 0);
    glutInitWindowSize(640, 640);
    glutCreateWindow(APP_TITLE);
    glutDisplayFunc(display);
    glutMainLoop();
}
