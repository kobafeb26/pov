#ifndef GogglesController_hpp
#define GogglesController_hpp


#include "ofxRaycaster.h"
#include "ActorController.hpp"
//#include "DataModel.hpp"
#include <stdio.h>


class GogglesController
{
    ofxraycaster::Ray ray;
    ofNode lookat;
    ofNode center;
    
  
   
    uint64_t beforeTime;
    

public:
    GogglesController();
    int dataID;
    float x;
    float y;
    float z;

    
    float offset_x = 0.f;
    float offset_y = 0.f;
    float offset_z = 0.f;
    
    glm::quat q;
    glm::quat offset_q;
    

    int actorID;
    float actorDistance;
    ActorController *lookActorRef;
    ActorController *myActorRef;
    
    int camera_id;
    int watcher_id;
    

    void setup();
    void update();
    void draw();
    //bool intersectsPrimitive(const of3dPrimitive& primitive);
    int intersectsPrimitive(std::vector<ActorController*>* actorsRef);
    //int checkSamePovCamera(std::vector<GogglesController*>* gogglesesRef);
    //void switching();
    //void switching(int _myInterval, int _otherInterval);
    //void resetSwitch();
    
    void send(bool isCameraEnable, bool isCameraSwitchingEnable);
    
    
    
    //std::vector<int> samePovCameras;
    //int samePovCamerasIndex;
    
    
    //int switch_camera_id_buf;
    //int intarvalCounter;
    
    int minInterval;
    
    int sendCameraIDBefore;
    
    int debug_cameraID;
    
};

#endif /* GogglesController_hpp */
