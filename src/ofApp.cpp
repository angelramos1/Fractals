#include "ofApp.h"
#include "SnowFlake.h"
#include "Fractal3D.h"
#include "FractalMode1.h"
#include "FractalMode2.h"
#include "FractalMode3.h"
#include "FractalMode4.h"


//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",15);

    //Initialize the vector containing the "Levels" for each Fractal
    levels = vector<int>{3, 10, 7, 50, 5, 3};

    fractals.push_back(new FractalMode1("Fractal Mode 1", levels[0]));
    fractals.push_back(new FractalMode2("Fractal Mode 2", levels[1]));
    fractals.push_back(new FractalMode3("Fractal Mode 3", levels[2]));
    fractals.push_back(new FractalMode4("Fractal Mode 4", levels[3]));
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        text.drawString("Circle Fractal", 25, 60);
        float r = 0.31 * ofGetHeight();
        fractals[0]->draw();  
    } break;
    case '2': {
        // Tree
        text.drawString("Tree Fractal", 25, 60);
        fractals[1]->draw();  
    } break;
    case '3': {
        // Sierpinski Triangle
        text.drawString("Sierpinski Triangle Fractal", 25, 60);
        fractals[2]->draw();  
    } break;
    case '4': {
        // Barnsley Fern
        text.drawString("Barnsley Fern Fractal", 25, 60);
        fractals[3]->draw();  
    } break;
    case '5': {
        // Koch SnowFlake
        text.drawString("Koch SnowFlake Fractal", 25, 60);
        SnowFlake().draw(levels[4]);
    } break;
    case '6': {
        //3D Fractal
        text.drawString("3D Fractal Fractal", 25, 60);
        Fractal3D(&cam).draw(map<string, float> {{"n", levels[5]}, {"scale", 100}});
    } break;
    }

    if (showDebugInfo) {
        std::vector<std::string> modeNames = {"Circle", "Tree", "Sierpinski Triangle", "Barnsley Fern", "Koch SnowFlake", "3D Fractal"};
        dataText.load("Fonts/fractalFont.otf", 20);

        int initialY = 140;  
        int spacing = 30; 

        for (size_t i = 0; i < modeNames.size(); ++i) {
            std::string info = modeNames[i] + " level: " + std::to_string(levels[i]);
            dataText.drawString(info, 25, initialY + (i * spacing)); 
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '6') {
        mode = key;
        if (mode >= '1' && mode <= '4') { 
            int index = mode - '1'; 
            if (index >= 0 && index < fractals.size()) {
                fractals[index]->setLevel(levels[index]); 
            }
        }
    }

    if (key == 'd' || key == 'D') {
        showDebugInfo = !showDebugInfo;
    }

    if(key == OF_KEY_LEFT){
        if(mode == '1' && levels[0]>1){
            levels[0]--;
        } else if(mode == '2' && levels[1]>1){
            levels[1]--;
        } else if(mode == '3' && levels[2]>1){
            levels[2]--;
        } else if(mode == '4' && levels[3]>5){
            levels[3]--;
        } else if(mode == '5' && levels[4]>1){
            levels[4]--;
        } else if(mode == '6' && levels[5]>0){
            levels[5]--;
        }
        
        if (mode >= '1' && mode <= '4') {
            int index = mode - '1';
            if (index >= 0 && index < fractals.size()) {
                fractals[index]->setLevel(levels[index]);
            }
        }
    }

    if(key == OF_KEY_RIGHT){
        if(mode == '1' && levels[0]<5){
            levels[0]++;
        } else if(mode == '2' && levels[1]<15){
            levels[1]++;
        } else if(mode == '3' && levels[2]<10){
            levels[2]++;
        } else if(mode == '4' && levels[3]<50){
            levels[3]++;
        } else if(mode == '5' && levels[4]<6){
            levels[4]++;
        } else if(mode == '6' && levels[5]<9){
            levels[5]++;
        }
       
        if (mode >= '1' && mode <= '4') {
            int index = mode - '1';
            if (index >= 0 && index < fractals.size()) {
                fractals[index]->setLevel(levels[index]);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}