#ifndef DataReciveController_hpp
#define DataReciveController_hpp

#define PORT 12345
#define NUM_MSG_STRINGS 20
#include "ofxOsc.h"
#include "DataModel.hpp"

#include <stdio.h>

class DataReciveController
{
    ofxOscReceiver receiver;
    int currentMsgString;
    std::string msgStrings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];
    
    
    
public:
    void setup();
    void update();

};



#endif /* DataReciveController_hpp */
