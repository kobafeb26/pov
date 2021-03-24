#include "GogglesController.hpp"
#include "DataModel.hpp"
#include "SwitchCameraController.hpp"

void GogglesController::setup()
{

    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    qx = 0.0f;
    qy = 0.0f;
    qz = 0.0f;
    qw = 0.0f;
    
    center.setPosition(0, 0, 0);
    lookat.setPosition(0, 1000, 0);
    lookat.setParent(center);

    glm::vec3 rayDirection = glm::vec3(0,1,0);
    ray.setup(center.getGlobalPosition(), rayDirection);
    
    
    //samePovCamerasIndex = 0;
    //intarvalCounter = 0xffff;
    
    //switch_camera_id_buf = -1;
}

void GogglesController::update()
{
    
    
    center.setPosition(x, y, z);
    glm::quat qt;
    qt.x = qx;
    qt.y = qy;
    qt.z = qz;
    qt.w = qw;

    center.setOrientation(qt);
    
    
    ray.setOrigin(center.getGlobalPosition());
    glm::vec3 rayDirection = glm::normalize(lookat.getGlobalPosition() - center.getGlobalPosition());
    ray.setDirection(rayDirection);

    
}

//void GogglesController::resetSwitch()
//{
//    beforeTime = 0;
//    samePovCamerasIndex =0;
//}
int GogglesController::intersectsPrimitive(std::vector<ActorController*>* actorsRef)
{

    actorID = -1;
    lookActorRef = NULL;
    actorDistance = 999999999.0;
    for (auto a : *actorsRef)
    {
        glm::vec2 baricentricCoordinates;
        float dist;
        glm::vec3 surfaceNormal;
        
        
        if(a->id == dataID ) continue; //自分のアクターなので参照しない
        
        //TODO : 自分のアクターが、見ているグループの中にいたら弾く
        
        
        if(ray.intersectsPrimitive(a->box, baricentricCoordinates, dist, surfaceNormal)){
            if(dist > 0 && dist < actorDistance)
            {
                
                actorID = a->id;
                actorDistance = dist;
                lookActorRef = a;
            }

        }
        
    }
    
    return actorID;
}

void GogglesController::send(bool isCameraEnable, bool isCameraSwitchingEnable)
{
    int camid = -1;
    if(!isCameraEnable)
    {
        debug_cameraID = camid;
        SwitchCameraController::switcher(camid, watcher_id);
    }else if(isCameraSwitchingEnable)
    {
        if(lookActorRef!=NULL)
        {
            
            camid = lookActorRef->getCamID();
        }
        
        if(sendCameraIDBefore!=camid)
        {
            sendCameraIDBefore = camid;
            if(camid < 0) //見ているアクターが無い
            {
                debug_cameraID = camera_id;
                SwitchCameraController::switcher(camera_id, watcher_id);
            }else{ //アクターを見ている
                debug_cameraID = camid;
                SwitchCameraController::switcher(camid, watcher_id);
            }
        }
    }else{
        debug_cameraID = camera_id;
        SwitchCameraController::switcher(camera_id, watcher_id);
    }

}
//void GogglesController::switching(int _myInterval, int _otherInterval)
//{
//    if(samePovCameras.size()-1 < samePovCamerasIndex) samePovCamerasIndex = 0;
//    int switch_camera_id = samePovCameras[samePovCamerasIndex];
//    switch_camera_id_buf = switch_camera_id;
//    std::vector<WathcerModel*>* wathcersRef = &SharedData::instance().wathcersRef;
//    for(WathcerModel* w :  *wathcersRef)
//    {
//        if(w->watcher_id == watcher_id)
//        {
//            w->camera_id = switch_camera_id;
//            break;
//        }
//    }
//    
//    samePovCamerasIndex++;
//
//    
//}
//int GogglesController::checkSamePovCamera(std::vector<GogglesController*>* gogglesesRef)
//{
//    samePovCameras.clear();
//    for (auto g : *gogglesesRef)
//    {
//        if(actorID >= 0 && actorID == g->actorID)
//        {
//            
//            samePovCameras.push_back(g->camera_id);
//        }
//        
//    }
//    if(samePovCameras.size() <= 0) samePovCameras.push_back(camera_id);
//}

void GogglesController::draw()
{
    ofDrawSphere(center.getGlobalPosition(), 5);
    
    if(actorID < 0)
    {
        ofDrawLine(center.getGlobalPosition(), lookat.getGlobalPosition());
    }else{
        
        auto intersection = ray.getOrigin() + ray.getDirection() * actorDistance;

        ofSetColor(255, 0, 0);
        ofDrawLine(ray.getOrigin(), intersection);
        ofSetColor(255);
    }

}


