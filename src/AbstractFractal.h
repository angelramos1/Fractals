#pragma once

#include "Fractal.h"
#include <string>

class AbstractFractal : public Fractal {
protected:
    std::string name;
    int level;

public:
    AbstractFractal(const std::string& name, int level) : name(name), level(level) {}

    std::string getName() const override {
        return name;
    }

    int getLevel() const override {
        return level;
    }

    void setName(const std::string& newName) override {
        name = newName;
    }

    void setLevel(int newLevel) override {
        level = newLevel;
    }

    virtual void draw() const = 0;
};