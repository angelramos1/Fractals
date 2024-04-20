#include "ofApp.h"
#include "SnowFlake.h"
#include "Fractal3D.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",15);

    //LEVELS VECTOR INITIALIZING
    levels = vector<int>{3, 10, 7, 50, 5, 3};
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    text.drawString("(Insert Fractal Name Here)",25,60);

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        float r = 0.31 * ofGetHeight();
        angle += 0.01;
        drawMode1(ofGetWidth() / 2, ofGetHeight() / 2, r, levels[0]);
    } break;
    case '2': {
        // Tree
        float length = 0.31 * ofGetHeight();
        drawMode2(ofGetWidth() / 2, ofGetHeight() - 20, levels[1], length, 1.5 * PI);
    } break;
    case '3': {
        // Sierpinski Triangle
        float size = 0.88 * ofGetHeight();
        drawMode3((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, levels[2]);
    } break;
    case '4': {
        // Barnsley Fern
        drawMode4(0, 0, levels[3] *1000);
    }    break;
    case '5': {
        // Koch SnowFlake
        SnowFlake().draw(levels[4]);
    }   break;
    case '6': {
        //3d Fractal
        Fractal3D(&cam).draw(map<string, float> {{"n", levels[5]}, {"scale", 100}});
    }   break;
    }
}

void ofApp::drawMode1(float x, float y, float r, int n) {
    if (n == 0) return;

    int delta = r * 0.35;
    ofDrawCircle(x, y, r);

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    drawMode1(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1);
    drawMode1(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1);
    drawMode1(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1);
    drawMode1(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1);
    drawMode1(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1);
    drawMode1(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1);
}

void ofApp::drawMode2(float x, float y, int n, float length, float rad) {
    if (n == 0) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofDrawLine(x, y, x2, y2);

    drawMode2(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI);
    drawMode2(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI);
}

void ofApp::drawMode3(float x, float y, float size, int n) {
    if (n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    drawMode3(x, y, size / 2, n - 1);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
}

void ofApp::drawMode4(float x, float y, float n) {
    if (n == 0) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    ofFill();
    ofSetColor(ofColor::green);
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        drawMode4(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        drawMode4(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        drawMode4(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        drawMode4(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '6'){
        mode = key;
    }

    //Changes the depth level depending on the mode
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