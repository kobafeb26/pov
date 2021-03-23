#include "DataReciveController.hpp"

void DataReciveController::setup()
{
    receiver.setup(PORT);
}
void DataReciveController::update()
{
    while(receiver.hasWaitingMessages()){

        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);

        // check for mouse moved message
        if(m.getAddress() == "/tracker"){

            //todo : 直接gogglesControllerを叩いた方が良いのでは
            // both the arguments are floats
            int id = m.getArgAsInt32(0);
            
            //ゴーグルデータ
            for (auto g : SharedData::instance().gogglesesRef)
            {
                if(g->dataID == id)
                {
                    g->x = m.getArgAsFloat(1)*100.0f;
                    g->y = m.getArgAsFloat(2)*100.0f;
                    g->z = m.getArgAsFloat(3)*100.0f;
                    g->qx = m.getArgAsFloat(4);
                    g->qy = m.getArgAsFloat(5);
                    g->qz = m.getArgAsFloat(6);
                    g->qw = m.getArgAsFloat(7);
                    
                }
            }
            
            //アクターデータ
            for (auto a : SharedData::instance().actorsRef)
            {
                if(a->id == id)
                {
                    a->x = m.getArgAsFloat(1)*100.0f;
                    a->y = m.getArgAsFloat(2)*100.0f;
                    a->z = m.getArgAsFloat(3)*100.0f;
//                    g->qx = m.getArgAsFloat(4);
//                    g->qy = m.getArgAsFloat(5);
//                    g->qz = m.getArgAsFloat(6);
//                    g->qw = m.getArgAsFloat(7);
                    
                }
            }
            
            
            
        }
        
    }
}
