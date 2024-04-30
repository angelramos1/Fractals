#pragma once

#include "AbstractFractal.h"
#include "ofMain.h"  

class FractalMode4 : public AbstractFractal {
public:
    FractalMode4(const std::string& name, int level);

    void draw() const override;

private:
    void drawFractal(float x, float y, int n) const;
};