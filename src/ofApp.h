#pragma once

#include "ofMain.h"
#include "Line.h"
enum type{LINES,LINE_LOOP,TRIANGLE,POLYGON};
class ofApp : public ofBaseApp{

	public:
		Line line;
		vector<ofVec2f> points;
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void createRegPolygon(ofVec2f central, int sides);
		void addPoint(ofVec2f newPoint);
		void drawFigure(vector<ofVec2f> &points, int type);
		void sierpinsky(ofVec2f a, ofVec2f b, ofVec2f c, int level);
		ofVec2f midPoint(ofVec2f a, ofVec2f b);
};
