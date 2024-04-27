#pragma once

#include <string>

class Fractal {
public:
    virtual void draw() const = 0; 
    virtual std::string getName() const = 0; 
    virtual int getLevel() const = 0; 

    
    virtual void setName(const std::string& name) = 0; 
    virtual void setLevel(int level) = 0; 
};