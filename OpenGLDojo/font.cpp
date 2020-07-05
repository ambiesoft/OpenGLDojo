#include <stdio.h>
#include <stdarg.h>

#include "../glm/glm/glm.hpp"
#include "GL/glut.h"

#include "font.h"

using namespace glm;

static vec2 position;
static float size = FONT_DEFAULT_SIZE;
static unsigned char color[3];

void fontBegin()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glMatrixMode(GL_PROJECTION);
    // initialize matrix
    glLoadIdentity();

    GLint viewport[4];
    glGetIntegerv(
        GL_VIEWPORT,
        viewport);
    
    gluOrtho2D(
        0, 
        viewport[2],  // width
        viewport[3],  // height
        0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}
void fontEnd()
{
	glPopMatrix();
	glPopAttrib();
}

void fontSetPosition(float x, float y){
    position = vec2{ x,y };
}
float fontGetSize() {
    return size;
}
void fontSetSize(float sizetmp) {
    size = sizetmp;
}
void fontSetColor(unsigned char red, unsigned char green, unsigned char blue) {
    color[0] = red;
    color[1] = green;
    color[2] = blue;
}
void fontDraw(const char* format, ...) {
    va_list argList;
    va_start(argList, format);
    char str[256];
    vsprintf_s(str, format, argList);
    va_end(argList);

    glColor3ub(color[0], color[2], color[3]);
    glPushMatrix();
    {
        glTranslatef(position.x, position.y + size, 0);
        float s = size / FONT_DEFAULT_SIZE;
        glScalef(s, -s, s);
        for (char* p = str; *p; ++p)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    }
    glPopMatrix();

    printf("%s\n", str);
}