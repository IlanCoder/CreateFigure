#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	line.init();
	line.setColor(ofColor::indianRed);
	//sierpinsky(ofVec2f(0,ofGetHeight()), ofVec2f(ofGetWidth(),ofGetHeight()), ofVec2f(ofGetWidth()/2, 0),3);
	//createRegPolygon(central, 5);
	createRegPolygon(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2),4);
}

//--------------------------------------------------------------
void ofApp::update(){
	line.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	line.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

void ofApp::createRegPolygon(ofVec2f central, int sides){
	int x2 = 0, y2 = 0;
	float angles;
	bool firstPoint = true;
	ofVec2f initPoint;
	for (float angle = 0.0f; angle <= 2*PI; angle+=(2*PI/sides)) {
		angles = 50.0f*cos(angle);
		x2 = (int)angles;
		angles = 50.0f*sin(angle);
		y2 = (int)angles;
		if (firstPoint) {
			line.setPoint(x2 + central.x, y2 + central.y);
			initPoint.set(x2 + central.x, y2 + central.y);
			firstPoint = false;
		}
		else{
			line.moveTo(x2 + central.x, y2 + central.y);
		}
	}
	line.moveTo(initPoint.x, initPoint.y);
}

void ofApp::addPoint(ofVec2f newPoint){
	points.push_back(newPoint);
}

void ofApp::drawFigure(vector<ofVec2f> &points, int type){
	int sides;
	if (type > 2) {
		sides = type;
		type = POLYGON;
	}
	switch (type) {
	case LINES:
		line.setPoint(points[0].x, points[0].y);
		for (int i = 1; i < points.size(); i++) {
			line.moveTo(points[i].x, points[i].y);
		}
		break;
	case LINE_LOOP:
		line.setPoint(points[0].x, points[0].y);
		for (int i = 1; i < points.size(); i++) {
			line.moveTo(points[i].x, points[i].y);
		}
		line.moveTo(points[0].x, points[0].y);
		break;
	case TRIANGLE:
		for (int f = 0; f < points.size()-2; f += 3) {
			line.setPoint(points[f].x, points[f].y);
			for (int i = 0; i < 3; i++) {
				line.moveTo(points[f+i].x, points[f+i].y);
			}
			line.moveTo(points[f].x, points[f].y);
		}
		break;
	case POLYGON:
		for (int f = 0; f < points.size() - (sides-1); f += sides) {
			line.setPoint(points[f].x, points[f].y);
			for (int i = 0; i <sides; i++) {
				line.moveTo(points[f + i].x, points[f + i].y);
			}
			line.moveTo(points[f].x, points[f].y);
		}
		break;
	}
}

void ofApp::sierpinsky(ofVec2f a, ofVec2f b, ofVec2f c, int level) {
	if (level == 0) {
		points.push_back(a);
		points.push_back(b);
		points.push_back(c);
		return;
	}
	else {
		ofVec2f ab = midPoint(a, b);
		ofVec2f bc = midPoint(b, c);
		ofVec2f ca = midPoint(c, a);
		sierpinsky(a, ab, ca, level - 1);
		sierpinsky(ab, b, bc, level - 1);
		sierpinsky(ca, bc, c, level - 1);
	}
	drawFigure(points, TRIANGLE);
}

ofVec2f ofApp::midPoint(ofVec2f a, ofVec2f b){
	ofVec2f v;
	v.set((a.x + b.x) / 2, (a.y + b.y) / 2);
	return v;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
}
