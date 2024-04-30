#pragma once

#include "AbstractFractal.h"
#include "ofMain.h"  
#include "ofApp.h"

class FractalMode1 : public AbstractFractal {
public:
    FractalMode1(const std::string& name, int level);

    void draw() const override;
    float angle = 0;

private:
    void drawFractal(float x, float y, float r, int n) const;
};