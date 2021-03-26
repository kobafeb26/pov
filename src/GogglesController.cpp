#include "GogglesController.hpp"
#include "DataModel.hpp"
#include "SwitchCameraController.hpp"

GogglesController::GogglesController()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;

    offset_q.x = 0.0f;
    offset_q.y = 0.0f;
    offset_q.z = 0.0f;
    offset_q.w = 0.0f;
    
    q.x = 0.0f;
    q.y = 0.0f;
    q.z = 0.0f;
    q.w = 0.0f;
}
void GogglesController::setup()
{


    
    
    center.setPosition(x, y, z);
    lookat.setPosition(x, y+1000, z);
    lookat.setParent(center);

    glm::vec3 rayDirection = glm::vec3(0,1,0);
    ray.setup(center.getGlobalPosition(), rayDirection);
    
    
    //samePovCamerasIndex = 0;
    //intarvalCounter = 0xffff;
    
    //switch_camera_id_buf = -1;
}

void GogglesController::update()
{
    
    
    center.setPosition(x+offset_x, y+offset_y, z+offset_z);


    center.setOrientation(q*offset_q);
    
    
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
        
        
        if(!a	->isParent && a->id == dataID )
        {
//            if(dataID==199){
//                std::cout << dataID << "<<<<<<<<<<<<<<<<" <<  a->id << std::endl;
//            }
            continue; //自分のアクターなので参照しない
        }
        
        //TODO : 自分のアクターが、見ているグループの中にいたら弾く
        
        //指定の大きさでチェク
        if(ray.intersectsPrimitive(a->box, baricentricCoordinates, dist, surfaceNormal)){
            if(dist > 0 && dist < actorDistance)
            {
                
                actorID = a->id;
                actorDistance = dist;
                lookActorRef = a;
            }

        }
        //最小の大きさでチェク　//近接対応
        float w = a->box.getWidth();
        float h = a->box.getHeight();
        float d = a->box.getDepth();
        
        a->box.setWidth(20);
        a->box.setHeight(20);
        a->box.setDepth(20);
        if(ray.intersectsPrimitive(a->box, baricentricCoordinates, dist, surfaceNormal)){
            if(dist > 0 && dist < actorDistance)
            {
                
                actorID = a->id;
                actorDistance = dist;
                lookActorRef = a;
            }
        }
        a->box.setWidth(w);
        a->box.setHeight(h);
        a->box.setDepth(d);
        
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


