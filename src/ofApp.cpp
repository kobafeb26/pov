#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    beforeTime = ofGetElapsedTimeMillis();
    
    
    dataReciveController.setup();
    
    SharedData::instance().isSony = ISSONY;
    
    
    SwitchCameraController::setup();
    
    font.loadFont("mono0755.ttf", 20);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    ofEnableDepthTest();
    bHelpText = false;

    cam.setPosition(0, 100, 500);

    std::vector<GogglesController*>* gogglesesRef = &SharedData::instance().gogglesesRef;
    std::vector<ActorController*>* actorsRef = &SharedData::instance().actorsRef;
    std::vector<WathcerModel*>* wathcersRef = &SharedData::instance().wathcersRef;
    

    //==ゴーグル初期化
    GogglesController *g = new GogglesController;
    WathcerModel *w;
    
    //--0--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 199;
    if(SharedData::instance().isSony)
    {
        g->camera_id = 199;
        g->watcher_id = 531;
    }else{
        g->camera_id = 0;
        g->watcher_id = 0;
    }
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    g->intarvalCounter = 0;
    g->y = 10000;
    g->x = 0.1;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);
    
    
    //--1--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 200;
    if(SharedData::instance().isSony)
    {
        g->camera_id = 200;
        g->watcher_id = 534;
    }else{
        g->camera_id = 1;
        g->watcher_id = 1;
    }
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    
    g->intarvalCounter = 0;
    g->y = 10000;
    g->x = 0.1;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);
    
    //--2--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 201;
    if(SharedData::instance().isSony)
    {
        g->camera_id = 201;
        g->watcher_id = 533;
    }else{
        g->camera_id = 2;
        g->watcher_id = 2;
    }
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    g->intarvalCounter = 0;
    g->y = 10000;
    g->x = 0.1;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);
    
    //--3--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 202;
    if(SharedData::instance().isSony)
    {
        g->camera_id = 202;
        g->watcher_id = 532;
    }else{
        g->camera_id = 3;
        g->watcher_id = 3;
    }
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    g->intarvalCounter = 0;
    g->y = 10000;
    g->x = 0.1;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);

    //--4--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 203;
    if(SharedData::instance().isSony)
    {
        g->camera_id = 203;
        g->watcher_id = 542;
    }else{
        g->camera_id = 4;
        g->watcher_id = 4;
    }
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    g->intarvalCounter = 0;
    g->y = 10000;
    g->x = 0.1;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);

    //--5--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID =204;
    if(SharedData::instance().isSony)
    {
        g->camera_id = 204;
        g->watcher_id = 543;
    }else{
        g->camera_id = 5;
        g->watcher_id = 5;
    }
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    g->intarvalCounter = 0;
    g->y = 10000;
    g->x = 0.1;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);


    //--6--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID =205;
    if(SharedData::instance().isSony)
    {
        g->camera_id = 205;
        g->watcher_id = 543;
    }else{
        g->camera_id = 6;
        g->watcher_id = 6;
    }
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    g->intarvalCounter = 0;
    g->y = 10000;
    g->x = 0.1;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);

    
//    w = new WathcerModel;
//    w->camera_id = 0;
//    w->watcher_id = 555;
//    wathcersRef->push_back(w);
//
//    w = new WathcerModel;
//    w->camera_id = 0;
//    w->watcher_id = 556;
//    wathcersRef->push_back(w);

    
    //todo データが一定事案こなかったらどっかにとばす
    //==アクターの初期化
    ActorController *a;

    
    //--0--//
    a = new ActorController;
    a->id = 199;
    a->x = 0;
    a->y = 0;
    a->z = 10000;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);

    
    
    //--1--//
    a = new ActorController;
    a->id = 200;
    a->x = 0;
    a->y = 0;
    a->z = 10000;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);

    //--2--//
    a = new ActorController;
    a->id = 201;
    a->x = 0;
    a->y = 0;
    a->z = 1000;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);

    //--3--//
    a = new ActorController;
    a->id = 202;
    a->x = 0;
    a->y = 0;
    a->z = 10000;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);

    //--4--//
    a = new ActorController;
    a->id = 203;
    a->x = 0;
    a->y = 0;
    a->z = 10000;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);

    //--5--//
    a = new ActorController;
    a->id = 204;
    a->x = 0;
    a->y = 0;
    a->z =  10000;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);
    
    //--6--//
    a = new ActorController;
    a->id = 205;
    a->x = 0;
    a->y = 0;
    a->z = 10000;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);
    
    
    //--Dancer1--//
    a = new ActorController;
    a->id = 501;
    a->x = 0;
    a->y = 0;
    a->z = 10000;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);
    
    
    
//    a = new ActorController;
//    a->id = 50;
//    a->x = 0;
//    a->y = 100;
//    a->z = 0;
//    a->width = 50;
//    a->height = 60;
//    a->depth = 50;
//    actorsRef->push_back(a);
//
//
//    a = new ActorController;
//    a->id = 51;
//    a->x = -160;
//    a->y = 0;
//    a->z = 160;
//    a->width = 35;
//    a->height = 60;
//    a->depth = 45;
//    actorsRef->push_back(a);
//
//    a = new ActorController;
//    a->id = 52;
//    a->x = 120;
//    a->y = 70;
//    a->z = 0;
//    a->width = 20;
//    a->height = 56;
//    a->depth = 60;
//    actorsRef->push_back(a);
//
    
    for (auto a : *actorsRef)
    {
        a->setup();
    }

    gui.setup(); // most of the time you don't need a name
    gui.add(uiSliderInterval.setup("interval", /*def*/1000, /*min*/1000, /*max*/3000));
    
    
    // ライティングを有効に
    light.enable();
    // スポットライトを配置
    light.setPointLight();
    // 照明の位置
    light.setPosition(-100, 100, 100);
    // 鏡面反射光の色
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    // 拡散反射光の色
    light.setDiffuseColor(ofFloatColor(0.5, 0.5, 1.0));
    // 環境反射光の色
    light.setAmbientColor(ofFloatColor(0.2, 0.2, 0.2, 1.0));
    
}

//--------------------------------------------------------------
void ofApp::update(){
  
    
    dataReciveController.update();
    
    std::vector<GogglesController*>* gogglesesRef = &SharedData::instance().gogglesesRef;
    std::vector<ActorController*>* actorsRef = &SharedData::instance().actorsRef;
    
    for (auto a : *actorsRef)
    {
        a->watcherGoggleses.clear();
        a->update();
    }
    
    //見ているモノをチェック
    for (auto g : *gogglesesRef)
    {
        g->update();
        int aid = g->intersectsPrimitive(&(*actorsRef));
        if(aid >= 0)
        {
            for (auto a : *actorsRef)
            {
                if(a->id == aid)
                {
                    a->watcherGoggleses.push_back(g->camera_id);
                }
            }
        }else{
            g->resetSwitch();
            
        }
    }
    
    //同じモノをみてるゴーグルを探す
    for (auto g : *gogglesesRef)
    {
        g->checkSamePovCamera(&(*gogglesesRef));
    }
    
    
    
    //スイッチング
    if(SharedData::instance().isSony){
        uint64_t nowtime = ofGetElapsedTimeMillis();
        //if((nowtime-beforeTime) > REQUEST_INTERVAL) //interval(msec)
        if((nowtime-beforeTime) > uiSliderInterval) //interval(msec)
        {
            std::cout << "--------" << std::endl;
            std::cout << "  Interval : " << nowtime-beforeTime << " msec" << std::endl;
            beforeTime = nowtime;
            //スイッチング
            for (auto g : *gogglesesRef)
            {
                g->switching(uiSliderInterval, uiSliderInterval);
            }
            
            SwitchCameraController::switcher();
        }
    }else{
        for (auto g : *gogglesesRef)
        {
            g->switching(uiSliderInterval, uiSliderInterval);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(20);
    
    
    cam.begin();
    
    
    ofSetConeResolution(20, 2);
    ofSetCylinderResolution(20, 2);
    ofEnableDepthTest();
//    ofSetColor(ofColor::red);//RIGHT
//    ofDrawCone(100, 0, 0, 50, 100);
//
//    ofSetColor(ofColor::white);//LEFT
//    ofDrawSphere(-100, 0, 0, 50);
//
//    ofSetColor(ofColor::blue);//BOTTOM
//    ofDrawBox(0, 100, 0, 100);
//
//    ofSetColor(ofColor::cyan);//TOP
//    ofDrawCylinder(0, -100, 0, 50, 100);
//
//    ofSetColor(ofColor::yellow);//FRONT
//    ofDrawBox(0, 0, 100, 100);
//
//    ofSetColor(ofColor::magenta);//BACK
//    ofDrawBox(0, 0, -100, 100);
    
    ofDrawGrid(100,5,true,false,true,false);

    
    
    
    
    std::vector<GogglesController*>* gogglesesRef = &SharedData::instance().gogglesesRef;
    std::vector<ActorController*>* actorsRef = &SharedData::instance().actorsRef;
    
    ofSetColor(ofColor::magenta);
    //box.draw();
    ofSetColor(255, 255, 255);
    

    for (auto a : *actorsRef)
    {
        a->draw();
    }
    

    for (auto g : *gogglesesRef)
    {
        g->draw();
    }
    
    
    
    
    
    
    ofDisableDepthTest();
    cam.end();
//    drawInteractionArea();
    ofSetColor(255);
    
    
    
    gui.draw();
    
    
    if (!bHelpText) {
        
        ofPushMatrix();
        //ofScale(3, 3);
        
        stringstream ss;
        ss << "interval my : ";
        ss << uiSliderInterval << endl;
//        ss << "interval other : ";
//        ss << intervals->y << endl;
        
        ss << "Actor List" << endl;
        for (auto a : *actorsRef)
        {
            ss << "act:" << a->id;
            ss << " watcher: ";
            for (auto w : a->watcherGoggleses)
            {
                ss << w << ",";
            }
            ss << endl;
            
        }
        ss << endl;
        
        ss << "Watcher List" << endl;
        for (auto g : *gogglesesRef)
        {
            ss << "min_int:" << g->minInterval;
            ss << " watcher:" << g->watcher_id;
            ss << " pov_actor:" << g->actorID;
            ss << " camera: ";
            ss << g->switch_camera_id_buf;
            ss << " cameras: ";
            for (auto c : g->samePovCameras)
            {
                ss << c << ",";
            }
            ss << endl;
            
        }
        
        font.drawString(ss.str().c_str(), 20, 120);
        //ofDrawBitmapString(ss.str().c_str(), 20, 20);
        
        ofPopMatrix();
        
        
    
    }
    
    
    
    


    if (bHelpText) {
        stringstream ss;
        ss << "FPS: " << ofToString(ofGetFrameRate(),0) <<endl<<endl;
        ss << "MODE: " << (cam.getOrtho()?"ORTHO":"PERSPECTIVE")<<endl;
        ss << "MOUSE INPUT ENABLED: " << (cam.getMouseInputEnabled()?"TRUE":"FALSE")<<endl;
        ss << "INERTIA ENABLED: " << (cam.getInertiaEnabled()?"TRUE":"FALSE")<<endl;
        ss << "ROTATION RELATIVE Y AXIS: " << (cam.getRelativeYAxis()?"TRUE":"FALSE")<<endl;
        ss << endl;
        ss << "Toogle camera projection mode (ORTHO or PERSPECTIVE):"<< endl;
        ss << "    press space bar."<< endl;
        ss << "Toggle mouse input:"<<endl;
        ss << "    press 'c' key."<< endl;
        ss << "Toggle camera inertia:"<<endl;
        ss << "    press 'i' key."<< endl;
        ss << "Toggle rotation relative Y axis:"<<endl;
        ss << "    press 'y' key."<< endl;
        ss << "Toggle this help:"<<endl;
        ss << "    press 'h' key."<< endl;
        ss << endl;
        ss << "camera x,y rotation:" <<endl;
        ss << "    LEFT MOUSE BUTTON DRAG inside yellow circle"<<endl;
        ss << endl;
        ss << "camera z rotation or roll"<<endl;
        ss << "    LEFT MOUSE BUTTON DRAG outside yellow circle"<<endl;

        ss << endl;
        ss << "move over x,y axis / truck and boom:"<<endl;
        ss << "    LEFT MOUSE BUTTON DRAG + m"<<endl;
        ss << "    MIDDLE MOUSE BUTTON PRESS"<<endl;
        ss << endl;
        ss << "move over z axis / dolly / zoom in or out:"<<endl;
        ss << "    RIGHT MOUSE BUTTON DRAG"<<endl;
        ss << "    VERTICAL SCROLL"<<endl<<endl;
        if (cam.getOrtho()) {
            ss << "    Notice that in ortho mode zoom will be centered at the mouse position." << endl;
        }
        ofDrawBitmapString(ss.str().c_str(), 20, 20);
    }
    
    
    

}

//--------------------------------------------------------------
void ofApp::drawInteractionArea(){
    ofRectangle vp = ofGetCurrentViewport();
    float r = std::min<float>(vp.width, vp.height) * 0.5f;
    float x = vp.width * 0.5f;
    float y = vp.height * 0.5f;

    ofPushStyle();
    ofSetLineWidth(3);
    ofSetColor(255, 255, 0);
    ofNoFill();
    glDepthMask(false);
    ofDrawCircle(x, y, r);
    glDepthMask(true);
    ofPopStyle();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
      case ' ':
            cam.getOrtho() ? cam.disableOrtho() : cam.enableOrtho();
            break;
        case 'C':
        case 'c':
            cam.getMouseInputEnabled() ? cam.disableMouseInput() : cam.enableMouseInput();
            break;
        case 'F':
        case 'f':
            ofToggleFullscreen();
            break;
        case 'H':
        case 'h':
            bHelpText ^=true;
            break;
        case 'I':
        case 'i':
            cam.getInertiaEnabled() ? cam.disableInertia() : cam.enableInertia();
            break;
        case 'Y':
        case 'y':
            cam.setRelativeYAxis(!cam.getRelativeYAxis());
            break;
            
        case '1':
            SwitchCameraController::switcher();
            break;
            
        case '2':
            //SwitchCameraController::switcher(STREEM_GROUP_ID, 384, 522);
            break;
            
//        case '1':
//        {
//
//            CURL *curl;
//
//            Memory body;
//            body.m = (char *)malloc(1);
//            body.m[0] = '\0';
//            body.size = 0;
//
//
//            // curlのセットアップ
//            curl = curl_easy_init();
//            curl_easy_setopt(curl, CURLOPT_URL, "https://www.ace-livestream.com/api/v1/cameras?event_id=125");
//            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
//            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);
//            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
//            curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
//            // 実行
//            CURLcode res = curl_easy_perform(curl);
//
//            if (res != CURLE_OK) {
//                printf("ERR: %s\n", curl_easy_strerror(res));
//            } else {
//                printf("response: \n%s\n", body.m);
//            }
//
//
//            // 後始末
//            free(body.m);
//            curl_easy_cleanup(curl);
//
//        }
//            break;
//        case '2':
//        {
//            CURL *curl;
//
//            Memory body;
//            body.m = (char *)malloc(1);
//            body.m[0] = '\0';
//            body.size = 0;
//
//
//            // curlのセットアップ
//            curl = curl_easy_init();
//            curl_easy_setopt(curl, CURLOPT_URL, "https://www.ace-livestream.com/api/v1/switchcamera");
//            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
//
//            char post_data[] = "{\"event_id\":125,\"camera_id\":381,\"watcher_id\":522}";
//
//            curl_easy_setopt(curl, CURLOPT_POST, 1);
//            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
//            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(post_data));
//
//
//            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);
//            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
//            curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
//            // 実行
//            CURLcode res = curl_easy_perform(curl);
//
//            if (res != CURLE_OK) {
//                printf("ERR: %s\n", curl_easy_strerror(res));
//            } else {
//                printf("response: \n%s\n", body.m);
//            }
//
//
//            // 後始末
//            free(body.m);
//            curl_easy_cleanup(curl);
//        }
//            break;
//        case '3':
//        {
//            CURL *curl;
//
//            Memory body;
//            body.m = (char *)malloc(1);
//            body.m[0] = '\0';
//            body.size = 0;
//
//
//            // curlのセットアップ
//            curl = curl_easy_init();
//            curl_easy_setopt(curl, CURLOPT_URL, "https://www.ace-livestream.com/api/v1/switchcamera");
//            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
//
//            char post_data[] = "{\"event_id\":125,\"camera_id\":384,\"watcher_id\":522}";
//
//            curl_easy_setopt(curl, CURLOPT_POST, 1);
//            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
//            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(post_data));
//
//
//            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);
//            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
//            curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
//            // 実行
//            CURLcode res = curl_easy_perform(curl);
//
//            if (res != CURLE_OK) {
//                printf("ERR: %s\n", curl_easy_strerror(res));
//            } else {
//                printf("response: \n%s\n", body.m);
//            }
//
//
//            // 後始末
//            free(body.m);
//            curl_easy_cleanup(curl);
//        }
//            break;
//
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
