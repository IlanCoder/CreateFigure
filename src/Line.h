#pragma once
#include "Pixel.h"

class Line {
private:
	Pixel pixel;
	bool filter;
	int val, dX, dY, a, b, d, changeLine;
	ofColor col;
	ofVec2f currPoint;
public:
	void init();
	void draw();
	void update();
	void createLine(int x1, int y1, int x2, int y2, int red, int green, int blue);
	void setColor(ofColor color);
	void setPoint(int x, int y);
	void moveTo(int x, int y);
	ofColor getColor();
};