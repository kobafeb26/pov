#ifndef ProjectorController_hpp
#define ProjectorController_hpp


#include "ofxRaycaster.h"
#include "ActorController.hpp"
//#include "DataModel.hpp"
#include <stdio.h>


class ProjectorController
{

    

    uint64_t beforeTime;
    

public:

    int actorID;
    float actorDistance;
    ActorController *lookActorRef;
    ActorController *myActorRef;
    
   //int camera_id;
    int watcher_id;
    

    void setup();
    void update();
    void draw();
 
    void send(bool isCameraEnable, bool isCameraSwitchingEnable, int cameraID);
    

    int minInterval;
    
    int sendCameraIDBefore;
    
    int debug_cameraID;
    
};

#endif /* GogglesController_hpp */
