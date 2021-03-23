#ifndef GogglesController_hpp
#define GogglesController_hpp

#include "ActorController.hpp"
#include "ofxRaycaster.h"
//#include "DataModel.hpp"
#include <stdio.h>


class GogglesController
{
    ofxraycaster::Ray ray;
    ofNode lookat;
    ofNode center;
    
  
   
    uint64_t beforeTime;
    

public:
    int dataID;
    float x;
    float y;
    float z;
    float qx;
    float qy;
    float qz;
    float qw;


    int actorID;
    float actorDistance;
    
    int camera_id;
    int watcher_id;
    

    void setup();
    void update();
    void draw();
    //bool intersectsPrimitive(const of3dPrimitive& primitive);
    
    int intersectsPrimitive(std::vector<ActorController*>* actorsRef);
    int checkSamePovCamera(std::vector<GogglesController*>* gogglesesRef);
    //void switching();
    void switching(int _myInterval, int _otherInterval);
    void resetSwitch();
    
    std::vector<int> samePovCameras;
    int samePovCamerasIndex;
    
    
    int switch_camera_id_buf;
    int intarvalCounter;
    
    int minInterval;
    
};

#endif /* GogglesController_hpp */
