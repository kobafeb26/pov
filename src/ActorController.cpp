#include "ActorController.hpp"
ActorController::ActorController()
{
    offset_q.x = 1.0f;
    offset_q.y = 0.0f;
    offset_q.z = 0.0f;
    offset_q.w = 0.0f;
    
    q.x = 0.0f;
    q.y = 0.0f;
    q.z = 0.0f;
    q.w = 0.0f;
    
    
}
void ActorController::setup()
{

    parentRef=NULL;
    box.set(width, height, depth );
    box.setPosition(x, y+(height/2), z);
    

    
}
 

void ActorController::updatePos()
{
    
//    if(id <= 499 && id >= 199)
//    {
//        box.setPosition(x, (y)-((height)/2) + 50, z);
//    }else{
//        box.setPosition(x, y+(height/2), z);
//    }
    
    box.setPosition(x+offset_x, y+offset_y, z+offset_x);
    
    if(rotationEnable)
    {
//        glm::quat qt;
//        qt.x = qx;
//        qt.y = qy;
//        qt.z = qz;
//        qt.w = qw;

        box.setOrientation(q*offset_q);
    }
    
    box.set(width, height, depth );
}


void ActorController::updateCam(int interval)
{
 
    if(watch_cameras.size() > 0) //見ているカメラがいる
    {
        //int minInterval = interval/watch_cameras.size();
        int minInterval = interval;
        //スイッチングタイミング
        //uint64_t nowtime = ofGetElapsedTimeMillis();
        //if((nowtime-beforeTime) > minInterval) //interval(msec)
        {
            //beforeTime = nowtime;
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


