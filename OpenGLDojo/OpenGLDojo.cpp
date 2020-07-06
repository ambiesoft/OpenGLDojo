// OpenGLDojo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../glm/glm/glm.hpp"
#include <GL/glut.h>
#include "font.h"
#include "Rect.h"

#define APP_TITLE "OpenGLDojo"

using namespace glm;
ivec2 windowSize = { 800,600 };

bool keys[256];
Rect rect1(vec2(100, 100), vec2(100, 200));
Rect rect2(vec2(windowSize.x / 2, windowSize.y / 2), vec2(200, 100));

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

    if (rect1.intersect(rect2))
    {
        glColor3ub(0xff, 0, 0);
    }
    else
    {
        glColor3ub(0, 0, 0xff);
    }
    rect1.draw();

    glColor3ub(0, 0xff, 0);
    rect2.draw();


    fontBegin();
    fontSetColor(0, 0xff, 0xee);
    fontSetPosition(0, windowSize.y - fontGetSize()*1.5);
    fontSetSize(FONT_DEFAULT_SIZE / 2);
    fontEnd();

    glutSwapBuffers();
}
void timer(int v)
{
    float f = 2;
    if (keys['w'])
        rect1.m_position.y -= f;
    if (keys['s'])
        rect1.m_position.y += f;
    if (keys['a'])
        rect1.m_position.x -= f;
    if (keys['d'])
        rect1.m_position.x += f;
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
