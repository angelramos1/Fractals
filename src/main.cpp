#include "ofApp.h"
#include "ofMain.h"

//========================================================================
int main() {
    ofSetupOpenGL(1440, 1000, OF_WINDOW); // <-------- setup the GL context
    ofSetFrameRate(60);

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
}
