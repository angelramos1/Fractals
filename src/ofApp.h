#pragma once

#include <cmath>
#include <vector> // So we can use a vector
#include "AbstractFractal.h"
#include "FractalMode1.h"
#include "FractalMode2.h"
#include "FractalMode3.h"
#include "FractalMode4.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {
  private:
    char mode = '1';
    float angle = 0;
    //Vector for the level of depth. It'll have 6 positions from 0 to 5, and each one will correspond to a mode.
    //Mode 1 is levels[0], Mode 2 is levels[1], etc. :)
    vector<int> levels;
    bool showDebugInfo = false;
    std::vector<AbstractFractal*> fractals;  // Vector to hold different fractal modes

  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void drawMode1(float x, float y, float r, int n);
    void drawMode2(float x, float y, int n, float length, float rad);
    void drawMode3(float x, float y, float size, int n);
    void drawMode4(float x, float y, float n);

    ofEasyCam cam;
    ofTrueTypeFont text;
    ofTrueTypeFont dataText;
};
