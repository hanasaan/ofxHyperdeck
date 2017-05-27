#include "ofMain.h"
#include "ofxHyperdeck.h"

class ofApp : public ofBaseApp{
    ofxHyperdeck hyperdeck;
public:
    void setup()
    {
        ofSetVerticalSync(true);
        ofSetFrameRate(60);
        
        hyperdeck.setup("192.168.30.101");
    }
    
    void update()
    {
    }
    
    void draw()
    {
        ofClear(0);
        
        if (hyperdeck.checkConnection()) {
            ofDrawRectangle(10, 10, 100, 100);
        }
        ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
    }
    
    void keyPressed(int key)
    {
        switch (key) {
            case '1':
                hyperdeck.play();
                break;
            case '2':
                hyperdeck.stop();
                break;
            case '3':
                hyperdeck.goToTimecode("00:00:30:22");
                
                break;
            case '4':
                hyperdeck.goToClipStart();
                break;
            case '5':
                hyperdeck.goToClipEnd();
                break;
            case 's':
                hyperdeck.setVideoInputType("SDI");
                break;
        }
    }
};

//========================================================================
int main( ){
    ofSetupOpenGL(1280,720,OF_WINDOW);            // <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
}
