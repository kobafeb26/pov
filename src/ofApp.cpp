#include "ofApp.h"



bool cmp( const ActorController * a,  const ActorController * b)
{
    return a->watch_cameras.size() > b->watch_cameras.size();
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    beforeTime = ofGetElapsedTimeMillis();
    
    
    dataReciveController.setup();
    
   
    
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
    std::vector<ProjectorController*>* projectorsRef = &SharedData::instance().projectorsRef;
    
    
    
    //==ゴーグル初期化
    GogglesController *g = new GogglesController;
    WathcerModel *w;
    
    //--0--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 199;
    g->camera_id = 0;
    g->watcher_id = 0;
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    //g->intarvalCounter = 0;
    g->y = 0;
    g->x = 200;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);
    
    
    //--1--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 200;
    g->camera_id = 1;
    g->watcher_id = 1;
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    g->y = 0;
    g->x = 200;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);
    
    //--2--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 201;
    g->camera_id = 2;
    g->watcher_id = 2;
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    g->y = 0;
    g->x = 0;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);
    
    //--3--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 202;
    g->camera_id = 3;
    g->watcher_id = 3;
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    //g->intarvalCounter = 0;
    g->y = 0;
    g->x = 0;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);

    //--4--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID = 203;
    g->camera_id = 4;
    g->watcher_id = 4;
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    //g->intarvalCounter = 0;
    g->y = 0;
    g->x = -100;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);

    //--5--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID =204;
    g->camera_id = 5;
    g->watcher_id = 5;
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    //g->intarvalCounter = 0;
    g->y = 0;
    g->x = -100;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);


    //--6--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID =205;
    g->camera_id = 6;
    g->watcher_id = 6;
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    //g->intarvalCounter = 0;
    g->y = 0;
    g->x = 100;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);

    
    //--7--//
    w = new WathcerModel;
    g = new GogglesController;
    g->setup();
    g->dataID =206;
    g->camera_id = 7;
    g->watcher_id = 7;
    w->camera_id = g->camera_id;
    w->watcher_id = g->watcher_id;
    //g->intarvalCounter = 0;
    g->y = 0;
    g->x = 300;
    gogglesesRef->push_back(g);
    wathcersRef->push_back(w);
    
    
    
    
    ProjectorController *p;
    p = new ProjectorController;
    p->watcher_id = 8;
    projectorsRef->push_back(p);
    
    
    p = new ProjectorController;
    p->watcher_id = 9;
    projectorsRef->push_back(p);


    p = new ProjectorController;
    p->watcher_id = 10;
    projectorsRef->push_back(p);
    
    
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
    a->x = 300;
    a->y = 500;
    a->z = 0;
    a->width = 40;
    a->height = 190;
    a->depth = 40;
    actorsRef->push_back(a);

    
    
    //--1--//
    a = new ActorController;
    a->id = 200;
    a->x = 0;
    a->y = 0;
    a->z = 1000;
    a->width = 40;
    a->height = 190;
    a->depth = 40;
    actorsRef->push_back(a);

    //--2--//
    a = new ActorController;
    a->id = 201;
    a->x = 0;
    a->y = 0;
    a->z = 1000;
    a->width = 40;
    a->height = 190;
    a->depth = 40;
    actorsRef->push_back(a);

    //--3--//
    a = new ActorController;
    a->id = 202;
    a->x = 0;
    a->y = 0;
    a->z = 1000;
    a->width = 40;
    a->height = 190;
    a->depth = 40;
    actorsRef->push_back(a);

    //--4--//
    a = new ActorController;
    a->id = 203;
    a->x = 0;
    a->y = 0;
    a->z = 1000;
    a->width = 40;
    a->height = 190;
    a->depth = 40;
    actorsRef->push_back(a);

    //--5--//
    a = new ActorController;
    a->id = 204;
    a->x = 0;
    a->y = 0;
    a->z = 1000;
    a->width = 40;
    a->height = 190;
    a->depth = 40;
    actorsRef->push_back(a);

    //--6--//
    a = new ActorController;
    a->id = 205;
    a->x = 0;
    a->y = 0;
    a->z = 1000;
    a->width = 40;
    a->height = 190;
    a->depth = 40;
    actorsRef->push_back(a);

    
    //--7--//
    a = new ActorController;
    a->id = 206;
    a->x = 0;
    a->y = 0;
    a->z = 1000;
    a->width = 40;
    a->height = 190;
    a->depth = 40;
    actorsRef->push_back(a);

    
    
    
    
    
    
    
    
    //--Dancer1--//
    a = new ActorController;
    a->id = 501;
    a->x = 1;
    a->y = 500;
    a->z = 0;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    
    
    
    glm::quat qt, qt2;
    qt.x = cos(45.0/2.0);
    qt.y = 0.0;
    qt.z = 0.0;
    qt.w = sin(45.0/2.0);

    a->rotationEnable = true;
    a->q =qt;
    
    qt2.x = cos(45.0/2.0);
    qt2.y = 0.0;
    qt2.z = sin(45.0/2.0);
    qt2.w = 0.0;
    
    a->offset_q = qt2;
    
    
    actorsRef->push_back(a);
    
    
    //--Dancer2--//
    a = new ActorController;
    a->id = 502;
    a->x = -100;
    a->y = 500;
    a->z = 0;
    a->width = 50;
    a->height = 190;
    a->depth = 50;
    actorsRef->push_back(a);
    
    
    //--Dancer3--//
    a = new ActorController;
    a->id = 503;
    a->x = 200;
    a->y = 500;
    a->z = 0;
    a->width = 10;
    a->height = 60;
    a->depth = 10;
    actorsRef->push_back(a);
    
    
    //--Dancer4--//ぬいぐるみ
    a = new ActorController;
    a->id = 504;
    a->x = 100;
    a->y = 500;
    a->z = 0;
    a->width = 50;
    a->height = 50;
    a->depth = 50;
    actorsRef->push_back(a);
    
    //--Dancer5--//カリンバ
    a = new ActorController;
    a->id = 505;
    a->x = 100;
    a->y = 500;
    a->z = 0;
    a->width = 30;
    a->height = 30;
    a->depth = 30;
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
    gui.add(CameraEnable.setup("Camera Enable", true));
    gui.add(SwitchCameraEnable.setup("Switch camera Enable", false));
    gui.add(uiSliderInterval.setup("interval", /*def*/1000, /*min*/300, /*max*/5000));
    gui.add(SliderDistance.setup("Distance", /*def*/60, /*min*/ 0, /*max*/300));
    gui.add(SliderActorWidth.setup("ActorWidth", /*def*/60, /*min*/ 0, /*max*/300));
    
    
    
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
    std::vector<ProjectorController*>* projectorsRef = &SharedData::instance().projectorsRef;
    
    //アクターの位置を更新
    for (auto a : *actorsRef)
    {
//        a->watch_cameras.clear();
//        a->parentRef = NULL;
//        a->isParent = false;
        a->updatePos();
        a->width = SliderActorWidth;
        a->depth = SliderActorWidth;
    }
    
    //ゴーグルーの位置を更新
    for (auto g : *gogglesesRef)
    {
        g->update();//ゴーグルのポジションをアップデート
        int aid = g->intersectsPrimitive(&(*actorsRef));//見ているアクトを探す
    }
    
    
    
    if(false){//アクターのグルーピング マイフレ
        for (auto a : *actorsRef)
        {
            a->watch_cameras.clear();
            a->parentRef = NULL;
            a->isParent = false;
            //a->updatePos();
        }

        
        if(SliderDistance > 0){
            for (auto a : *actorsRef)
            {
          
                for (auto a2 : *actorsRef)
                {

                    if(a->id == a2->id){
                        //a->isParent = true;
                        continue;
                    }
                    //２点の距離　sqrt( (x1-x2)^2 + (y1-y2)^2 )
                    float dist = std::sqrt(pow((a->x - a2->x), 2.0) + pow((a->y - a2->y), 2) + pow((a->z - a2->z), 2));
                    if(dist <= SliderDistance)
                    {
                        if(!a2->isParent && a2->parentRef == NULL)//まだ親が見つけられてない
                        {
                            //std::cout << a->id << " near " << a2->id << std::endl;
                            if(a->parentRef==NULL)
                            {
                                a2->parentRef = a;
                                a->isParent = true;
                            }else{
                                a2->parentRef = a->parentRef;
                            }
                        }
                    }
                }

            }
        }
    }
    
    
    
    
    //if(SwitchCameraEnable)
    
    int minInterval = uiSliderInterval;
    //スイッチングタイミング
    uint64_t nowtime = ofGetElapsedTimeMillis();
    if((nowtime-beforeTime) > minInterval) //interval(msec)
    {
        beforeTime = nowtime;
     
        if(true){//アクターのグルーピング インターバルあり
            for (auto a : *actorsRef)
            {
                a->watch_cameras.clear();
                a->parentRef = NULL;
                a->isParent = false;
                //a->updatePos();
                a->isCheck = false;
            }

            
            if(SliderDistance > 0){
                for (auto a : *actorsRef)
                {
              
                    for (auto a2 : *actorsRef)
                    {

                        if(a->id == a2->id){
                            //a->isParent = true;
                            continue;
                        }
                        //２点の距離　sqrt( (x1-x2)^2 + (y1-y2)^2 )
                        float dist = std::sqrt(pow((a->x - a2->x), 2.0) + pow((a->y - a2->y), 2) + pow((a->z - a2->z), 2));
                        if(dist <= SliderDistance)
                        {

                            
                            if(!a2->isParent && a2->parentRef == NULL)//親でもない、または親が見つけられてない
                            {
                                //std::cout << a->id << " near " << a2->id << std::endl;
                                if(a->parentRef==NULL)
                                {
                                    a2->parentRef = a;
                                    a->isParent = true;
                                }else{
                                    if(a->parentRef->parentRef == NULL)
                                    {
                                        a2->parentRef = a->parentRef;
                                    }else{
                                        a2->parentRef = a->parentRef->parentRef;
                                    }
                                }
                            }else{
                                
                                
                            }
                        }
                    }

                }
                
                if(true){
                    for (auto a : *actorsRef)
                    {
                        //if(a->isCheck) continue;
                        if(a->id == 501)
                        {
                            std::cout << "hoge" << std::endl;
                        }
                        if(!a->isParent && a->parentRef == NULL)continue; //親でもなく、親もいないものはやらない
                        for (auto a2 : *actorsRef)
                        {
                            //if(a2->isCheck) continue;
                            if(!a2->isParent && a2->parentRef == NULL)continue; //親でもなく、親もいないものはやらない
                            if(a == a2)continue; //同じアクターは無視
                            if(a == a2->parentRef)continue; //親が自分なら無視
                            if(a->parentRef!= NULL && a->parentRef == a2->parentRef)continue; //親が同じなら無視
                            if(a->parentRef == a2) continue;//自分の親と同じなら無視
                            
                            float dist = std::sqrt(pow((a->x - a2->x), 2.0) + pow((a->y - a2->y), 2) + pow((a->z - a2->z), 2));
                            if(dist <= SliderDistance)
                            {
                 
                                if(a->isParent && a2->isParent)//自分が親で、他の親の場合
                                {
                                    for (auto a3 : *actorsRef) //親だった場合、その親に紐づいている子も紐づける
                                    {
                                        if(a3->parentRef == a2)
                                        {
                                            a3->parentRef = a->parentRef;
                                        }
                                    }
                                    a2->isParent = false;
                                    a2->parentRef = a;
                                    a2->isCheck = true;

                                }else if(a->isParent && a2->parentRef != NULL)//自分が親、で他の子をの場合
                                {

                                    a2->parentRef->isParent = false;
                                    a2->parentRef->isCheck = true;
                                    a2->parentRef->parentRef = a;
                                    
                                    a2->watch_cameras.clear();
                                    a2->isParent = false;
                                    a2->isCheck = true;
                                    a2->parentRef = a;
                                    
                                }else if(a->parentRef != NULL && a2->isParent)//　自分が子、他の親
                                {
                                    
                                    for (auto a3 : *actorsRef) //親だった場合、その親に紐づいている子も紐づける
                                    {
                                        if(a3->parentRef == a2)
                                        {
                                            a3->parentRef = a->parentRef;
                                        }
                                    }
                                    a2->isParent = false;
                                    a2->parentRef = a->parentRef;
                                    a2->isCheck = true;
                                    
                                }else if(a->parentRef != NULL && a2->parentRef != NULL) //自分の親と、他人の親
                                {
  
                                        for (auto a3 : *actorsRef)
                                        {
                                            if(a2->parentRef == a3->parentRef)
                                            {
                                                std::cout << a2->parentRef->id << " -- " << a3->parentRef->id  << std::endl;
                                                std::cout << a3->id << " -- " << a->id << " : " << a3->parentRef->id << " - " << a->parentRef->id << std::endl;
                                                a3->parentRef = a->parentRef;
                                                a3->parentRef->isParent = false;
                                                a3->parentRef->isCheck = true;
                                               
                                                
                                                
                                            }
                                        }
    

                                    
                                    a2->watch_cameras.clear();
                                    a2->parentRef = a->parentRef;
                                    a2->isParent = false;
                                    a2->isCheck = true;
                    


                                }



                            }


                        }

                    }
                
                }
                
                
                std::cout << actorsRef << std::endl;
                
                
                
            }
            
            
            
        }
        
        
        
        
        
        
        //各ゴーグルが何をみているか確認する
        for (auto g : *gogglesesRef)
        {
            g->update();//ゴーグルのポジションをアップデート
            int aid = g->intersectsPrimitive(&(*actorsRef));//見ているアクトを探す
            if(aid >= 0)
            {
                
                for (auto a : *actorsRef) //アクト本体を探す
                {
                    if(a->id == aid)//見つけたアクトの配列にカメラIDを追加
                    {
                        if(g->watcher_id == 4)
                        {
                            std::cout << "Hoge" << std::endl;
                        }
                        //a->watcherGoggleses.push_back(g->camera_id);
                        if(a->isParent||a->parentRef == NULL)//親がいなかったらそのアクターに代入
                        {
                            a->watch_cameras.push_back(g->camera_id);
                        }else{ //親がいたら、親のアクターに代入
                            a->parentRef->watch_cameras.push_back(g->camera_id);
                        }
                    }
                }
            }else{
                //g->resetSwitch();//見ているものがなかったらゴーグルのスイッチングをリセット
                
            }
        }
        
        

        
        
        //カメラ切り替え
        for (auto a : *actorsRef)
        {
            a->updateCam(uiSliderInterval);
        }
        
        
        
        
        //配信アプリへ切り替え指示
        for (auto g : *gogglesesRef)
        {
            g->send(CameraEnable, SwitchCameraEnable);
        }
        
        
        
        //アクターを見られている数でソート
        std::vector<ActorController*> aaa;
        copy(actorsRef->begin(), actorsRef->end(), back_inserter(aaa) );
        std::sort(aaa.begin(), aaa.end(),cmp);
        
        //プロジェクター出力
        projectorsRef->at(0)->send(CameraEnable, SwitchCameraEnable, aaa.at(0)->getCamID());
        projectorsRef->at(1)->send(CameraEnable, SwitchCameraEnable, aaa.at(1)->getCamID());
        projectorsRef->at(2)->send(CameraEnable, SwitchCameraEnable, aaa.at(2)->getCamID());
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
    std::vector<ProjectorController*>* projectorsRef = &SharedData::instance().projectorsRef;
    
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

        
        ss << "Actor List" << endl;
        for (auto a : *actorsRef)
        {
            ss << "act:" << a->id;
            ss << " watcher: ";
            for (auto w : a->watch_cameras)
            {
                ss << w << ",";
            }
            ss << endl;
            
        }
        ss << endl;
        
        ss << "Watcher List" << endl;
        for (auto g : *gogglesesRef)
        {
            //ss << "min_int:" << g->minInterval;
            ss << " watcher:" << g->watcher_id;
            ss << " pov_actor:" << g->actorID;
            ss << " camera: ";
            ss << g->debug_cameraID;
//            ss << " cameras: ";
//            for (auto c : g->samePovCameras)
//            {
//                ss << c << ",";
//            }
            ss << endl;
            
        }
        
        ss << "Projector List" << endl;
        for (auto p : *projectorsRef)
        {
            ss << " watcher:" << p->watcher_id;
            //ss << " pov_actor:"
            ss << " camera: " << p->debug_cameraID;
            ss << endl;
        }
        
        
        font.drawString(ss.str().c_str(), 20, 150);
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
            //SwitchCameraController::switcher();
        {
            std::vector<ActorController*>* actorsRef = &SharedData::instance().actorsRef;
            for (auto a : *actorsRef)
            {
                a->x = 1000;
                a->y = 1000;
                a->z = 1000;
                
            }
            
            std::vector<GogglesController*>* gogglesesRef = &SharedData::instance().gogglesesRef;
            for (auto g : *gogglesesRef)
            {
                g->x = 1000;
                g->y = 1000;
                g->z = 1000;
                
            }
            
            
            break;
        }
            
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
