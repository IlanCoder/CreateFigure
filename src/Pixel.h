#pragma once
#include "ofMain.h"
#include "ofMath.h"

class Pixel {
private:
	ofTexture tex;
	ofPixels pix;
public:
	void putPixel(int x, int y, int r, int g, int b);
	void getPixel();
	void init();
	void draw();
};