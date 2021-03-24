#include "ActorController.hpp"

void ActorController::setup()
{

    
    box.set(width, height, depth );
    box.setPosition(x, y+(height/2), z);
    
}
 

void ActorController::updatePos()
{
    box.set(width, height, depth );
    if(id >= 199)
    {
        box.setPosition(x, (y)-((height)/2) + 50, z);
    }else{
        box.setPosition(x, y+(height/2), z);
    }

    
}


void ActorController::updateCam(int interval)
{
 
    if(watch_cameras.size() > 0) //見ているカメラがいる
    {
        int minInterval = interval/watch_cameras.size();
        //int minInterval = interval;
        //スイッチングタイミング
        uint64_t nowtime = ofGetElapsedTimeMillis();
        if((nowtime-beforeTime) > minInterval) //interval(msec)
        {
            beforeTime = nowtime;
            watch_cameras_index++;
            if(watch_cameras.size()-1 < watch_cameras_index) watch_cameras_index = 0;
        }
    }
}

int ActorController::getCamID()
{
    
    
    int res = -1;
    
    if(parentRef == NULL)//親がいなかったら自分の配列からカメラIDを返す
    {
        if(watch_cameras.size() > 0)
        {
            if(watch_cameras.size()-1 < watch_cameras_index) watch_cameras_index = 0;
            res = watch_cameras[watch_cameras_index];
        }
    }else{ //親がいたら、親のカメラIDを返す
        
        res = parentRef->getCamID();
    }
    return res;
}
void ActorController::draw()
{
    box.draw();
}


