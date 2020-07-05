// OpenGLDojo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <GL/glut.h>

#define APP_TITLE "OpenGLDojo"

int windowWidth = 800;
int windowHeight = 600;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    // initialize matrix
    glLoadIdentity();
    gluOrtho2D(
        0, windowWidth,
        windowHeight, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(
        windowWidth / 2,
        windowHeight / 2,
        0
    );
    static float angle;
    glRotatef(
        angle++, //angle
        0, 0, 1 // axis, z
    );
    glScalef(256, 256, 1);
    glutWireTeapot(1);
    // glFlush();
    glutSwapBuffers();
}
void timer(int v)
{
    glutPostRedisplay();

    glutTimerFunc(1000/60, timer, 0);
}
void reshape(int width, int height)
{
    printf("reshape: width:%d height:%d\n", width, height);
    glViewport(0, 0, width, height);
    windowWidth = width;
    windowHeight = height;
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(640, 0);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow(APP_TITLE);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
