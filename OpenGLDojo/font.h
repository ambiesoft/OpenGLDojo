#pragma once

#define FONT_DEFAULT_SIZE 100

void fontBegin();
void fontEnd();

void fontSetPosition(float x, float y);
float fontGetSize();
void fontSetSize(float size);

float fontGetWeightMin();
float fontGetWeightMax();
void fontSetWeight(float weight);

void fontSetColor(unsigned char red, unsigned char green, unsigned char blue);
void fontDraw(const char* format, ...);