#ifndef ActorController_hpp
#define ActorController_hpp
#include "ofMain.h"
//#include "DataModel.hpp"
#include <stdio.h>
//
//class ActorModel
//{
//public:
//    int id;
//    float width;
//    float height;
//    float depth;
//
//    float x;
//    float y;
//    float z;
////    float qx;
////    float qy;
////    float qz;
////    float qw;
//};

class ActorController
{
//    ofxraycaster::Ray ray;
//    ofNode lookat;
//    ofNode center;
    
    

public:
    
    int id;
    float width;
    float height;
    float depth;
    
    float x;
    float y;
    float z;
    
    
    void setup();
    void update();
    void draw();
    
    ofBoxPrimitive box;
    //ActorModel state;
    
    std::vector<int> watcherGoggleses;
};

#endif /* ActorController_hpp */
