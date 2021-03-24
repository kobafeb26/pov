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
    void updatePos();
    void updateCam(int interval);
    int getCamID();
    void draw();
    
    ofBoxPrimitive box;
    //ActorModel state;
    
    std::vector<int> watcherGoggleses;
    
    uint64_t beforeTime;
    //todo:
    //見ているカメラ配列
    //見ているカメラ配列のindex
    std::vector<int> watch_cameras;
    int watch_cameras_index;
    //この現在のカメラIDをwatcherが参照すれば、みんな同じタイミングのカメラを見るはず
    
    //見ているwatcher配列
//    std::vector<int> watchers;
//    int watchers_index;


    
    
    //親アクト 近所にアクトがいるか確認
    //親だったら親IDをもらって参加に
    //親でなかったら、自分が親になり参加させる

    ActorController * parentRef;
    bool isParent;
    
    int getCamera_id();

    
};

#endif /* ActorController_hpp */
