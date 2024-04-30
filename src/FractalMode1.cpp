#include "FractalMode1.h"
#include "ofMain.h"

FractalMode1::FractalMode1(const std::string& name, int level) : AbstractFractal(name, level) {}

void FractalMode1::draw() const {
    float r = 0.31 * ofGetHeight();
    drawFractal(ofGetWidth() / 2, ofGetHeight() / 2, r, this->level);
}

void FractalMode1::drawFractal(float x, float y, float r, int n) const {
    if (n == 0) return;
    
    int delta = r * 0.35;
    ofDrawCircle(x, y, r);

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    drawFractal(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1);
    ofSetColor(ofColor::green);
    drawFractal(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1);
    ofSetColor(ofColor::blue);
    drawFractal(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1);
    ofSetColor(ofColor::red);
    drawFractal(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1);
    ofSetColor(ofColor::yellow);
    drawFractal(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1);
    ofSetColor(ofColor::orange);
    drawFractal(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1);
    ofSetColor(ofColor::white);
}