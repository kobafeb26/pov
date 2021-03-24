#pragma once

#include "ofMain.h"
#include "GogglesController.hpp"
#include "ActorController.hpp"
#include "DataReciveController.hpp"
#include "SwitchCameraController.hpp"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        void drawInteractionArea();
        bool bHelpText;
        ofEasyCam cam; // add mouse controls for camera movement
		
private:
    ofLight light;
    uint64_t beforeTime;
    
//    ofNode test1;
//    ofNode test2;
//    
//    std::vector<GogglesController*> gogglesesRef;
//    std::vector<ActorController*> actorsRef;
    
    DataReciveController dataReciveController;
    
    
    ofBoxPrimitive box;
    
    ofTrueTypeFont font;
    
    ofxPanel gui;
    
    ofxIntSlider uiSliderInterval;
    ofxToggle CameraEnable;
    ofxToggle SwitchCameraEnable;
    
    
    int intarvalCounter;
};
