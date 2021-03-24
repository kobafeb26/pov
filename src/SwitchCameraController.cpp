#include "SwitchCameraController.hpp"
#include "DataModel.hpp"

#define BUFFER_MAX 0x10000
size_t write_length = 0;

ofxOscSender SwitchCameraController::oscSender;
int SwitchCameraController::intarvalCounter;

typedef struct {
    char *m;
    size_t size;
} Memory;

//libcurlコールバック
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    char *p;
    Memory *mem = (Memory *)userdata;
    size_t append_size = size * nmemb;

    p = (char *)realloc(mem->m, mem->size + append_size + 1);
    if (p == NULL) {
        return 0;
    }
    memcpy(p + mem->size, ptr, append_size);

    mem->m = p;
    mem->size += append_size;
    mem->m[mem->size] = '\0';

    return size * nmemb;
}

void SwitchCameraController::setup()
{
    oscSender.setup("127.0.0.1", 55555);
}

void SwitchCameraController::switcher(int camera_id, int watcher_id)
{
    ofxOscMessage m;
    m.setAddress("/switcher");
    m.addIntArg(watcher_id);
    m.addIntArg(camera_id);
    oscSender.sendMessage(m, false);
}
//void SwitchCameraController::switcher()
//{
//    std::vector<WathcerModel*>* wathcersRef = &SharedData::instance().wathcersRef;
//    
//    
//        
//    for(WathcerModel* w :  *wathcersRef)
//    {
//
//        /*
//         if(m.getAddress() == "/switcher"){
//             int watcher = m.getArgAsInt32(0);
//             int camera = m.getArgAsInt32(1);
//         }
//         */
//        
//        ofxOscMessage m;
//        m.setAddress("/switcher");
//        m.addIntArg(w->watcher_id);
//        m.addIntArg(w->camera_id);
//        oscSender.sendMessage(m, false);
//        
//        
//        
//        if(w->watcher_id == 0)
//        {
//            ofxOscMessage m;
//            m.setAddress("/switcher");
//            m.addIntArg(6);
//            m.addIntArg(w->camera_id);
//            oscSender.sendMessage(m, false);
//            
//            //ofxOscMessage m;
//            m.setAddress("/switcher");
//            m.addIntArg(7);
//            m.addIntArg(w->camera_id);
//            oscSender.sendMessage(m, false);
//            
//            //ofxOscMessage m;
//            m.setAddress("/switcher");
//            m.addIntArg(8);
//            m.addIntArg(w->camera_id);
//            oscSender.sendMessage(m, false);
//            
//            //ofxOscMessage m;
//            m.setAddress("/switcher");
//            m.addIntArg(9);
//            m.addIntArg(w->camera_id);
//            oscSender.sendMessage(m, false);
//            
//        }
//        
//
//    }
//        
//        
//    
//}
