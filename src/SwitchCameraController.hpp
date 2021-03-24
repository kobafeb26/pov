#ifndef SwitchCameraController_hpp
#define SwitchCameraController_hpp

#include "ofMain.h"
#include "ofxCurl.h"
#include "ofxOsc.h"
#include <stdio.h>
#include "DataModel.hpp"

class SwitchCameraController
{

    //static int grpID;
    
    static ofxOscSender oscSender;
public:
    //static void switcher();
    static void switcher(int camera_id, int watcher_id);
    static void setup();
    
    static int intarvalCounter;
    
};

#endif /* SwitchCameraController_hpp */
