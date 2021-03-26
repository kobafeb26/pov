#include "ProjectorController.hpp"
#include "DataModel.hpp"
#include "SwitchCameraController.hpp"

void ProjectorController::setup()
{

   
}
void ProjectorController::update()
{
    


    
}


void ProjectorController::send(bool isCameraEnable, bool isCameraSwitchingEnable, int cameraID)
{
    int camid = -1;
    if(!isCameraEnable)
    {
        debug_cameraID = camid;
        SwitchCameraController::switcher(camid, watcher_id);
    }else if(isCameraSwitchingEnable)
    {
//        if(lookActorRef!=NULL)
//        {
//
//            camid = lookActorRef->getCamID();
//        }
//
        camid = cameraID;
        if(sendCameraIDBefore!=camid)
        {
            sendCameraIDBefore = camid;
      
            debug_cameraID = camid;
            SwitchCameraController::switcher(camid, watcher_id);
            
        }
    }else{
        debug_cameraID = camid;
        SwitchCameraController::switcher(camid, watcher_id);
    }

}


