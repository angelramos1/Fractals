#include "FractalMode3.h"
#include "ofMain.h"

FractalMode3::FractalMode3(const std::string& name, int level) : AbstractFractal(name, level) {}

void FractalMode3::draw() const {
    float size = 0.88 * ofGetHeight();
    drawFractal((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, this->level);
}

void FractalMode3::drawFractal(float x, float y, float size, int n) const {
    if (n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c((x + size / 2), y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);
    
    ofSetColor(ofColor::yellow);  
    drawFractal((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1);

    ofSetColor(ofColor::green);  
    drawFractal(x, y, size / 2, n - 1);

    ofSetColor(ofColor::purple);  
    drawFractal((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);

    ofSetColor(ofColor::white);  
}