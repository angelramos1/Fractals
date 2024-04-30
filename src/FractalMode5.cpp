#include "FractalMode5.h"
#include "ofMain.h"

FractalMode5::FractalMode5(const std::string& name, int level) : AbstractFractal(name, level) {}

void FractalMode5::draw() const {
    drawFractal(ofGetWidth() / 2 - 50*7, ofGetHeight() / 2 - 50*7, 100*7, this->level);
}

void FractalMode5::drawFractal(float x, float y, float size, int n) const {
    if (n == 0) {
        return;
    }

    ofDrawRectangle(x, y, size, size);

    float smallerSize = size / 2;

    drawFractal(x, y, smallerSize, n - 1);                            //Top-left
    ofSetColor(ofColor::green);
    drawFractal(x + smallerSize, y, smallerSize, n - 1);              //Top-right
    ofSetColor(ofColor::blue);
    drawFractal(x, y + smallerSize, smallerSize, n - 1);              //Bottom-left
    ofSetColor(ofColor::yellow);
    drawFractal(x + smallerSize, y + smallerSize, smallerSize, n - 1); //Bottom-right
    ofSetColor(ofColor::white);
}