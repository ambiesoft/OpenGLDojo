// OpenGLDojo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

#include "../glm/glm/glm.hpp"
#include <GL/glut.h>
#include "font.h"
#include "Ball.h"

#define APP_TITLE "OpenGLDojo"
#define BALL_MAX 256
using namespace glm;
ivec2 windowSize = { 800,600 };

bool keys[256];
Ball balls[BALL_MAX];

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

    unsigned char colors[6][3] = {
        {0xff, 0x00, 0x00},
        {0x00, 0xff, 0x00},
        {0x00, 0x00, 0xff},
        {0xff, 0xff, 0x00},
        {0x00, 0xff, 0xff},
        {0xff, 0x00, 0xff},
    };

    for (int i = 0; i < BALL_MAX; ++i) {
        int index = i % 6;
        glColor3ub(colors[index][0], colors[index][1], colors[index][2]);
        balls[i].draw();
    }

    fontBegin();
    {
        fontSetColor(0, 0xff, 0xee);
        fontSetSize(FONT_DEFAULT_SIZE);
        float lineHeight = fontGetSize() * 1.5f;
        float y = windowSize.y - lineHeight * 2;

        fontSetWeight(fontGetWeightMin());
        fontSetPosition(0, y);
        //fontDraw("min:%f", fontGetWeightMin());

        //fontSetWeight(fontGetWeightMax());
        //fontSetPosition(0, y += lineHeight);
        //fontDraw("max:%f", fontGetWeightMax());
    }
    fontEnd();

    glutSwapBuffers();
}
void timer(int)
{
    for (auto&& ball : balls) {
        ball.update();
        if (ball.m_position.x < 0) {
            ball.m_position = ball.m_lastposition;
            ball.m_speed.x = fabs(ball.m_speed.x);
        }
        if (ball.m_position.y < 0) {
            ball.m_position = ball.m_lastposition;
            ball.m_speed.y = fabs(ball.m_speed.y);
        }
        if (ball.m_position.x >= windowSize.x) {
            ball.m_position = ball.m_lastposition;
            ball.m_speed.x = -fabs(ball.m_speed.x);
        }
        if (ball.m_position.y >= windowSize.y) {
            ball.m_position = ball.m_lastposition;
            ball.m_speed.y = -fabs(ball.m_speed.y);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}
void reshape(int width, int height)
{
    printf("reshape: width:%d height:%d\n", width, height);
    glViewport(0, 0, width, height);
    windowSize = ivec2{ width,height };
}
void keyboard(unsigned char key, int , int )
{
    if (key == 0x1b)
        exit(0);
    // printf("keyboard: '%c' (%#x)\n", key, key);
    keys[key] = true;
}
void keyboardup(unsigned char key, int , int )
{
    // printf("keyboard up: '%c' (%#x)\n", key, key);
    keys[key] = false;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    for (int i = 0; i < BALL_MAX; ++i) {
        balls[i].m_position = vec2(
            rand() % windowSize.x,
            rand() % windowSize.y
        );
        balls[i].m_speed = normalize(vec2(
            // between 0-1
            (float)rand() / RAND_MAX - .5f,
            (float)rand() / RAND_MAX - .5f)
        );
    }
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
