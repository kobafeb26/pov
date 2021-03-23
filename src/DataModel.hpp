#ifndef DataModel_hpp
#define DataModel_hpp
#include "ofMain.h"
#include <stdio.h>

#include "GogglesController.hpp"
#include "ActorController.hpp"

#define ISSONY false
#define REQUEST_INTERVAL 1000
#define STREEM_GROUP_ID 65




class WathcerModel
{
public:
    int camera_id;
    int watcher_id;
    
};

class GogglesModel
{
public:
    int id;
    float x;
    float y;
    float z;
    float qx;
    float qy;
    float qz;
    float qw;
    
};



class SharedData
{
    SharedData() = default;
    ~SharedData() = default;
public:
    
    //GogglesModel gogglesModels[8];
    //ActorModel ActorModels
    
    std::vector<GogglesController*> gogglesesRef;
    std::vector<ActorController*> actorsRef;
    std::vector<WathcerModel*> wathcersRef;
    
    bool isSony;
//    
    
    SharedData(const SharedData&) = delete;
    SharedData& operator=(const SharedData&) = delete;
    SharedData(SharedData&&) = delete;
    SharedData& operator=(SharedData&&) = delete;
    
    static SharedData& instance() {
        static SharedData instance;
        return instance;
    }
};

#endif /* DataModel_hpp */
