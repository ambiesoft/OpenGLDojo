// OpenGLDojo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../glm/glm/glm.hpp"
#include <GL/glut.h>
#include "font.h"

#define APP_TITLE "OpenGLDojo"

using namespace glm;
ivec2 windowSize = { 800,600 };

bool keys[256];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    // initialize matrix
    glLoadIdentity();
    gluOrtho2D(
        0, windowSize.x,
        windowSize.y, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(
        windowSize.x / 2,
        windowSize.y / 2,
        0
    );
    static float angle;
    if (keys['d'])
        angle += 1;
    if (keys['a'])
        angle -= 1;
    glRotatef(
        angle, //angle
        0, 0, 1 // axis, z
    );
    glScalef(256, 256, 1);
    glutWireTeapot(1);
    // glFlush();

    fontBegin();
    {
        fontSetColor(0, 0xff, 0xee);
        fontSetSize(FONT_DEFAULT_SIZE);
        float lineHeight = fontGetSize() * 1.5;
        float y = windowSize.y - lineHeight * 2;

        fontSetWeight(fontGetWeightMin());
        fontSetPosition(0, y);
        fontDraw("min:%f", fontGetWeightMin());

        fontSetWeight(fontGetWeightMax());
        fontSetPosition(0, y += lineHeight);
        fontDraw("max:%f", fontGetWeightMax());
    }
    fontEnd();

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
    windowSize = ivec2{ width,height };
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 0x1b)
        exit(0);
    // printf("keyboard: '%c' (%#x)\n", key, key);
    keys[key] = true;
}
void keyboardup(unsigned char key, int x, int y)
{
    // printf("keyboard up: '%c' (%#x)\n", key, key);
    keys[key] = false;
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(640, 0);
    glutInitWindowSize(windowSize.x, windowSize.y);
    glutCreateWindow(APP_TITLE);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardup);
    glutIgnoreKeyRepeat(GL_TRUE);
    glutMainLoop();
}
