#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 180;
	for (int x = span * 0.5; x < ofGetWidth(); x += span) {

		for (int y = span * 0.5; y < ofGetHeight(); y += span) {

			int a = ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.005), 0, 1, 2, 12);
			int b = ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.005), 0, 1, 2, 12);
			this->draw_div_rect(glm::vec2(x, y), a, b);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_div_rect(glm::vec2 draw_location, int a, int b) {

	// 数学から創るジェネラティブアート P.51

	auto scale = 13;
	auto width = a * scale;
	auto height = b * scale;
	auto length = height;
	auto location = glm::vec2();
	auto count = 0;

	ofPushMatrix();
	ofTranslate(draw_location.x - width * 0.5, draw_location.y - height * 0.5);

	while (length > 0) {

		if (count++ % 2 == 0) {

			while (location.x + length <= width) {

				ofDrawRectangle(location, length, length);
				location.x += length;
			}
			length = width - location.x;
		}
		else {

			while (location.y + length <= height) {

				ofDrawRectangle(location, length, length);
				location.y += length;
			}
			length = height - location.y;
		}
	}

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}