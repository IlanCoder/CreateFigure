#include "Pixel.h"

void Pixel::putPixel(int x, int y, int r, int g, int b){
	ofColor col;
	col.set(r, g, b);
	if (x <= ofGetWidth() && x >= 0) { //prevents from beign draws outside bitmap
		if (y <= ofGetHeight() && y >= 0) {
			pix.setColor(x, y, col);
		}
	}
}

void Pixel::getPixel(){
	tex.loadData(pix);
}

void Pixel::init(){
	pix.allocate(ofGetWidth(), ofGetHeight(), OF_PIXELS_RGB);
	tex.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
}

void Pixel::draw(){
	tex.draw(0, 0);
}
