#include "FractalMode2.h"
#include "ofMain.h"

FractalMode2::FractalMode2(const std::string& name, int level) : AbstractFractal(name, level) {}

void FractalMode2::draw() const {
    float length = 0.31 * ofGetHeight();

    // Tree 1
    drawFractal(0.8 * length, ofGetHeight() - 20, this->level, 0.4 * length, 1.5 * PI);
    // Tree 2
    drawFractal(ofGetWidth() - (0.8 * length), ofGetHeight() - 20, this->level, 0.4 * length, 1.5 * PI);
    // Tree 3
    drawFractal(ofGetWidth() / 2, ofGetHeight() - 20, this->level, length, 1.5 * PI);
}

void FractalMode2::drawFractal(float x, float y, int n, float length, float rad) const {
    if (n == 0) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::blue);
    // Recursion to create the branching effect
    drawFractal(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI);
    ofSetColor(ofColor::red);
    drawFractal(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI);
    ofSetColor(ofColor::white);
}