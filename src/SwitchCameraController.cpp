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
void SwitchCameraController::switcher()
{
    std::vector<WathcerModel*>* wathcersRef = &SharedData::instance().wathcersRef;
    
    if(SharedData::instance().isSony)
    {
        //リクスト文字列生成
        ostringstream ss;
        ss << "[";
        int i = 0;
        for(WathcerModel* w :  *wathcersRef)
        {
            ss << "{\"event_id\":" << STREEM_GROUP_ID << ",\"camera_id\":" << w->camera_id << ",\"watcher_id\":" << w->watcher_id << "}";
            if(i++ < wathcersRef->size()-1) ss << ",";//最後以外はカンマで挿入

        }
        ss << "]";
         
        
        
        //リクエスト準備
        CURL *curl;

        Memory body;
        body.m = (char *)malloc(1);
        body.m[0] = '\0';
        body.size = 0;


        char buf[512];
        
        sprintf(buf, "%s", ss.str().c_str()); //リクエスト文字列コンソールアウト
        int len = ss.str().length();
        
        printf("--------\nRequest: \n%s\n", buf);
       
        // curlのセットアップ
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.ace-livestream.com/api/v2/switchcamera");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buf);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, len);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        
        
        uint64_t nowtime = ofGetElapsedTimeMillis();
        // リクエスト実行と結果
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) { //レスポンス結果をコンソールアウト
            printf("ERR: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response: \n%s\n", body.m);
        }
        printf("Response time: %lld msec\n", ofGetElapsedTimeMillis()-nowtime); //処理時間をコンソールアウト
        
        // 後始末
        free(body.m);
        curl_easy_cleanup(curl);
    }else
    {
        
        for(WathcerModel* w :  *wathcersRef)
        {

            /*
             if(m.getAddress() == "/switcher"){
                 int watcher = m.getArgAsInt32(0);
                 int camera = m.getArgAsInt32(1);
             }
             */
            
            ofxOscMessage m;
            m.setAddress("/switcher");
            m.addIntArg(w->watcher_id);
            m.addIntArg(w->camera_id);
            oscSender.sendMessage(m, false);
            
            
            
            if(w->watcher_id == 0)
            {
                ofxOscMessage m;
                m.setAddress("/switcher");
                m.addIntArg(6);
                m.addIntArg(w->camera_id);
                oscSender.sendMessage(m, false);
                
                //ofxOscMessage m;
                m.setAddress("/switcher");
                m.addIntArg(7);
                m.addIntArg(w->camera_id);
                oscSender.sendMessage(m, false);
                
                //ofxOscMessage m;
                m.setAddress("/switcher");
                m.addIntArg(8);
                m.addIntArg(w->camera_id);
                oscSender.sendMessage(m, false);
                
                //ofxOscMessage m;
                m.setAddress("/switcher");
                m.addIntArg(9);
                m.addIntArg(w->camera_id);
                oscSender.sendMessage(m, false);
                
            }
            

        }
        
        
    }
}
