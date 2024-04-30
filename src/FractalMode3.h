#pragma once

#include "AbstractFractal.h"
#include "ofMain.h"  

class FractalMode3 : public AbstractFractal {
public:
    FractalMode3(const std::string& name, int level);

    void draw() const override;

private:
    void drawFractal(float x, float y, float size, int n) const;
};