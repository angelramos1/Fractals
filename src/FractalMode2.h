#pragma once

#include "AbstractFractal.h"
#include "ofMain.h"  

class FractalMode2 : public AbstractFractal {
public:
    FractalMode2(const std::string& name, int level);

    void draw() const override;

private:
    void drawFractal(float x, float y, int n, float length, float rad) const;
};