#include "GameScene.h"
#include "transitScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "OpenWeb.h"
using namespace cocos2d::ui;

USING_NS_CC;

Scene* Game::createScene(){
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Game::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

void::Game::changeScene(){
    stopFrame=true;
    auto nextScene=Transit::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, nextScene, Color3B(0,0,0)));
}

Point Game::tileCoordForPosition(Point position){
    int x = position.x / map->getTileSize().width;
    int y = ((map->getMapSize().height * map->getTileSize().height) - position.y) / map->getTileSize().height;
    return Point(x, y);
}

Point Game::adjustPosition(Point position){
    //return Point(position.x/tileWidth*tileWidth+tileWidth/2,position.y/tileHeight*tileHeight+tileHeight/2);
    return Point((int)(position.x/tileWidth)*tileWidth+1,(int)(position.y/tileHeight)*tileHeight+1);

}

void Game::initMap() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    Point position;
    int dorm;
    disable=5;
    section=_MOVE;
    //std::cout<<"SCENE: "<<UserDefault::getInstance()->getIntegerForKey("Scene")<<std::endl;
    //std::cout<<"DORM"<<UserDefault::getInstance()->getIntegerForKey("Dorm")<<std::endl;
    if (scene==_DORM) {
        dorm=UserDefault::getInstance()->getIntegerForKey("Dorm");
        if (dorm==_POLLOCK) {
            map = TMXTiledMap::create("birth/pollock.tmx");
            tileWidth=map->getTileSize().width;
            tileHeight=map->getTileSize().height;
            int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
            if (entry==_BIRTH) {
                position=Vec2(visibleSize.width*0.65+ origin.x, visibleSize.height*0.5 + origin.y);
                section=_BIRTH;
            }
            else if(entry==_UP){
                position=Vec2(visibleSize.width*0.05+ origin.x, visibleSize.height*0.9  + origin.y);
            }
            else if(entry==_RIGHT){
                position=Vec2(visibleSize.width*0.95+ origin.x, visibleSize.height*0.9 + origin.y);
            }
            else if(entry==_LEFT){
                position=Vec2(visibleSize.width*0.15+ origin.x, visibleSize.height*0.3  + origin.y);
            }
            else if(entry==_DOWN){
                position=Vec2(visibleSize.width*0.5+ origin.x, visibleSize.height*0.1 + origin.y);
            }
            else if (entry==_NONBIRTH) {
                position=Vec2(visibleSize.width*0.65+ origin.x, visibleSize.height*0.5 + origin.y);
            }
            
        }
        else if (dorm==_EAST) {
            map = TMXTiledMap::create("birth/east.tmx");
            tileWidth=map->getTileSize().width;
            tileHeight=map->getTileSize().height;
            int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
            if (entry==_BIRTH) {
                position=Vec2(visibleSize.width*0.5+ origin.x, visibleSize.height*0.45 + origin.y);
                section=_BIRTH;
            }
            else if (entry==_NONBIRTH) {
                position=Vec2(visibleSize.width*0.5+ origin.x, visibleSize.height*0.45 + origin.y);
            }
            else if(entry==_LEFT){
                position=Vec2(visibleSize.width*0.05+ origin.x, visibleSize.height*0.05 + origin.y);
            }
            else if(entry==_DOWN){
                position=Vec2(visibleSize.width*0.35+ origin.x, visibleSize.height*0.1 + origin.y);
            }
            else if(entry==_UP){
                position=Vec2(visibleSize.width*0.05+ origin.x, visibleSize.height*0.75 + origin.y);
            }
        }
        else if (dorm==_WEST) {
            map = TMXTiledMap::create("birth/west.tmx");
            tileWidth=map->getTileSize().width;
            tileHeight=map->getTileSize().height;
            int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
            if (entry==_BIRTH) {
                position=Vec2(visibleSize.width*0.7+ origin.x, visibleSize.height*0.25 + origin.y);
                section=_BIRTH;
            }
            else if (entry==_NONBIRTH) {
                position=Vec2(visibleSize.width*0.7+ origin.x, visibleSize.height*0.25 + origin.y);
            }
            else if(entry==_UP){
                position=Vec2(visibleSize.width*0.95+ origin.x, visibleSize.height*0.8 + origin.y);
            }
            else if(entry==_RIGHT){
                position=Vec2(visibleSize.width*0.87+ origin.x, visibleSize.height*0.05 + origin.y);
            }
            else if(entry==_DOWN){
                position=Vec2(visibleSize.width*0.5+ origin.x, visibleSize.height*0.05 + origin.y);
            }
            else if(entry==_LEFT){
                position=Vec2(visibleSize.width*0.2+origin.x,visibleSize.height*0.3+origin.y);
            }
        }
        else if (dorm==_NORTH){
            map = TMXTiledMap::create("birth/north.tmx");
            tileWidth=map->getTileSize().width;
            tileHeight=map->getTileSize().height;
            int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
            if (entry==_BIRTH) {
                position=Vec2(visibleSize.width*0.6+ origin.x, visibleSize.height*0.55 + origin.y);
                section=_BIRTH;
            }
            else if (entry==_NONBIRTH) {
                position=Vec2(visibleSize.width*0.6+ origin.x, visibleSize.height*0.55 + origin.y);
            }
            else if(entry==_RIGHT){
                position=Vec2(visibleSize.width*0.95+ origin.x, visibleSize.height*0.4 + origin.y);
            }
            else if(entry==_DOWN){
                position=Vec2(visibleSize.width*0.85+ origin.x, visibleSize.height*0.05 + origin.y);
            }
        }
        else if (dorm==_SOUTH){
            map = TMXTiledMap::create("birth/south.tmx");
            tileWidth=map->getTileSize().width;
            tileHeight=map->getTileSize().height;
            int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
            if (entry==_BIRTH) {
                position=Vec2(visibleSize.width*0.55+ origin.x, visibleSize.height*0.35 + origin.y);
                section=_BIRTH;
            }
            else if (entry==_NONBIRTH) {
                position=Vec2(visibleSize.width*0.55+ origin.x, visibleSize.height*0.35 + origin.y);
            }
            else if(entry==_UP){
                position=Vec2(visibleSize.width*0.35+ origin.x, visibleSize.height*0.8 + origin.y);
            }
            else if(entry==_RIGHT){
                position=Vec2(visibleSize.width*0.55+ origin.x, visibleSize.height*0.55 + origin.y);
            }
            else if(entry==_DOWN){
                position=Vec2(visibleSize.width*0.75+ origin.x, visibleSize.height*0.35 + origin.y);
            }
            else if(entry==_LEFT){
                position=Vec2(visibleSize.width*0.2+origin.x,visibleSize.height*0.4+origin.y);
            }

        }
    }
    else if (scene==_HUB) {
        int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
        map = TMXTiledMap::create("game/hub.tmx");
        tileWidth=map->getTileSize().width;
        tileHeight=map->getTileSize().height;
        if (entry==_RIGHT) {
            position=Vec2(visibleSize.width*0.95+ origin.x, visibleSize.height*0.75 + origin.y);
        }
        else if(entry==_DOWN){
            position=Vec2(visibleSize.width*0.9+ origin.x, visibleSize.height*0.33 + origin.y);
        }
        if (entry==_LEFT) {
            position=Vec2(visibleSize.width*0.05+ origin.x, visibleSize.height*0.7 + origin.y);
        }

    }
    else if (scene==_PATTEE) {
        int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
        map = TMXTiledMap::create("game/pattee.tmx");
        tileWidth=map->getTileSize().width;
        tileHeight=map->getTileSize().height;
        if (entry==_RIGHT) {
            position=Vec2(visibleSize.width*0.95+ origin.x, visibleSize.height*0.75 + origin.y);
        }
        else if(entry==_DOWN){
            position=Vec2(visibleSize.width*0.50+ origin.x, visibleSize.height*0.05 + origin.y);
        }
        else if(entry==_LEFT){
            position=Vec2(visibleSize.width*0.05+ origin.x, visibleSize.height*0.35+origin.y);
        }
    }
    else if (scene==_IST){
        int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
        map = TMXTiledMap::create("game/ist.tmx");
        tileWidth=map->getTileSize().width;
        tileHeight=map->getTileSize().height;
        if (entry==_BIRTH) {
            position=Vec2(visibleSize.width*0.75+ origin.x, visibleSize.height*0.4 + origin.y);
        }
        else if (entry==_UP) {
            position=Vec2(visibleSize.width*0.53+ origin.x, visibleSize.height*0.85 + origin.y);
        }
        else if(entry==_RIGHT){
            position=Vec2(visibleSize.width*0.95+ origin.x, visibleSize.height*0.85 + origin.y);
        }
        else if(entry==_DOWN){
            position=Vec2(visibleSize.width*0.95+ origin.x, visibleSize.height*0.4 + origin.y);
        }
    }
    else if (scene==_OLDMAIN) {
        int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
        map = TMXTiledMap::create("game/oldmain.tmx");
        tileWidth=map->getTileSize().width;
        tileHeight=map->getTileSize().height;
        if (entry==_UP) {
            position=Vec2(visibleSize.width*0.42+ origin.x, visibleSize.height*0.85 + origin.y);
        }
        else if(entry==_RIGHT){
            position=Vec2(visibleSize.width*0.95+ origin.x, visibleSize.height*0.65 + origin.y);
        }
        else if(entry==_DOWN){
            position=Vec2(visibleSize.width*0.62+ origin.x, visibleSize.height*0.85 + origin.y);
        }
        else if(entry==_LEFT){
            position=Vec2(visibleSize.width*0.05+ origin.x, visibleSize.height*0.6 + origin.y);
        }
        
    }
    else if (scene==_LIFESC){
        int entry=UserDefault::getInstance()->getIntegerForKey("Entry");
        map = TMXTiledMap::create("game/lifescience.tmx");
        tileWidth=map->getTileSize().width;
        tileHeight=map->getTileSize().height;
        auto top=Sprite::create("game/lifeTop.png");
        top->setAnchorPoint(Vec2(0,0));
        top->setPosition(Vec2(origin.x,origin.y));
        this->addChild(top,6);
        if (entry==_UP) {
            position=Vec2(visibleSize.width*0.4+ origin.x, visibleSize.height*0.85 + origin.y);
        }
        else if(entry==_RIGHT){
            position=Vec2(visibleSize.width*0.8+ origin.x, visibleSize.height*0.1 + origin.y);
        }
        else if(entry==_DOWN){
            position=Vec2(visibleSize.width*0.40+ origin.x, visibleSize.height*0.05 + origin.y);
        }
        else if(entry==_LEFT){
            position=Vec2(visibleSize.width*0.05+ origin.x, visibleSize.height*0.05 + origin.y);
        }
    }
    position=adjustPosition(position);
    player->setPosition(position);
}

void Game::greeting() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    upArrow->setVisible(false);
    rightArrow->setVisible(false);
    downArrow->setVisible(false);
    leftArrow->setVisible(false);
    chat=Label::createWithTTF(chatss[0], "fonts/Cantarell-Bold.ttf", 40);
    chat->setWidth(0.6*visibleSize.width);
    chat->setAnchorPoint(Vec2(0,1));
    chat->setPosition(Vec2(origin.x+visibleSize.width*0.15,origin.y+visibleSize.height*0.27));
    this->addChild(chat,4);
    if (talkOrder[0]==_LION) {
        NameL = Label::createWithTTF("Nittany Lion :","fonts/Cantarell-Bold.ttf", 30);
    }
    else if (talkOrder[0]==_ME) {
        NameL = Label::createWithTTF(UserDefault::getInstance()->getStringForKey("Name")+" :","fonts/Cantarell-Bold.ttf", 30);
    }
    NameL->setAnchorPoint(Vec2(0,0));
    NameL->setPosition(Vec2(origin.x+visibleSize.width*0.15,origin.y+visibleSize.height*0.3));
    this->addChild(NameL,4);
    currentChat=0;
    listenerChat = EventListenerTouchOneByOne::create();
    lion=Sprite::create("lion.png");
    me=Sprite::create("game/"+std::to_string(UserDefault::getInstance()->getIntegerForKey("Gender"))+".png");
    chatbg=Sprite::create("chatbg1.png");
    lion->setPosition(Vec2(origin.x+visibleSize.width/4,origin.y+visibleSize.height/2));
    me->setPosition(Vec2(origin.x+visibleSize.width*0.7,visibleSize.height/2+origin.y));
    chatbg->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+chatbg->getContentSize().height/2));
    this->addChild(lion,2);
    this->addChild(me,2);
    this->addChild(chatbg,3);
    
    me->setVisible(false);
    listenerChat->onTouchBegan = [=](Touch* touch, Event* event){
        return true;
    };
    listenerChat->onTouchEnded = [&](Touch* touch, Event* event){
        if (currentChat<chatss.size()-1) {
            currentChat=currentChat+1;
            if (talkOrder[currentChat]==_LION) {
                //me->setVisible(false);
                NameL->setString("Nittany Lion :");
            }
            else if (talkOrder[currentChat]==_ME) {
                me->setVisible(true);
                NameL->setString(UserDefault::getInstance()->getStringForKey("Name")+" :");
            }
            chat->setString(chatss[currentChat]);
        }
        else if(currentChat==chatss.size()-1){
            chat->setVisible(false);
            chatbg->setVisible(false);
            lion->setVisible(false);
            NameL->setVisible(false);
            upArrow->setVisible(true);
            rightArrow->setVisible(true);
            downArrow->setVisible(true);
            leftArrow->setVisible(true);
            me->setVisible(false);
            section=_MOVE;
            this->getEventDispatcher()->removeEventListener(listenerChat);
        }
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerChat, this);
}

bool Game::init() {
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    scene=UserDefault::getInstance()->getIntegerForKey("Scene");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    stopFrame=false;
    dir=-1;
    if (UserDefault::getInstance()->getIntegerForKey("Gender")==1) {
        this->player =Sprite::create("game/boy.png");
    }
    else if(UserDefault::getInstance()->getIntegerForKey("Gender")==2) {
        this->player =Sprite::create("game/girl.png");
        
    }
    initMap();
    this->addChild(map,0,99);
    player->setAnchorPoint(Vec2(0,0));
    building = map->getLayer("building");
    building->setVisible(false);
    this->addChild(player,1);
    
    
    if (scene==_PATTEE) {
        auto cataBus=Sprite::create("game/cata.png");
        cataBus->setPosition(Vec2(origin.x+visibleSize.width*0.15,origin.y+visibleSize.height*0.45));
        this->addChild(cataBus,2);
        auto listenerCata = EventListenerTouchOneByOne::create();
        listenerCata->onTouchBegan = [=](Touch* touch, Event* event){
            return true;
        };
        listenerCata->onTouchEnded = [=](Touch* touch, Event* event){
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            //Get the position of the current point relative to the button
            Point locationInNode = target->convertToNodeSpace(touch->getLocation());
            Size s = target->getContentSize();
            Rect rect = Rect(0, 0, s.width, s.height);
            //Check the click area
            if (rect.containsPoint(locationInNode))
            {
                OpenWeb* test = new OpenWeb();
                test->OpenCata();
                delete test;
                test = NULL;
            }
        };
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerCata, cataBus);
    }
    else if (scene==_DORM && UserDefault::getInstance()->getIntegerForKey("Dorm")==_EAST) {
        auto cataBus=Sprite::create("game/cata.png");
        cataBus->setPosition(Vec2(origin.x+visibleSize.width*0.83,origin.y+visibleSize.height*0.13));
        this->addChild(cataBus,2);
        auto listenerCata = EventListenerTouchOneByOne::create();
        listenerCata->onTouchBegan = [=](Touch* touch, Event* event){
            return true;
        };
        listenerCata->onTouchEnded = [=](Touch* touch, Event* event){
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            //Get the position of the current point relative to the button
            Point locationInNode = target->convertToNodeSpace(touch->getLocation());
            Size s = target->getContentSize();
            Rect rect = Rect(0, 0, s.width, s.height);
            //Check the click area
            if (rect.containsPoint(locationInNode))
            {
                OpenWeb* test = new OpenWeb();
                test->OpenCata();
                delete test;
                test = NULL;
            }
        };
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerCata, cataBus);

    }
    else if (scene==_DORM && UserDefault::getInstance()->getIntegerForKey("Dorm")==_POLLOCK){
        auto orderUp=Sprite::create("game/orderup.png");
        orderUp->setPosition(Vec2(origin.x+visibleSize.width*0.18,origin.y+visibleSize.height*0.07));
        this->addChild(orderUp,2);
        auto listenerOrder = EventListenerTouchOneByOne::create();
        listenerOrder->onTouchBegan = [=](Touch* touch, Event* event){
            return true;
        };
        listenerOrder->onTouchEnded = [=](Touch* touch, Event* event){
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            //Get the position of the current point relative to the button
            Point locationInNode = target->convertToNodeSpace(touch->getLocation());
            Size s = target->getContentSize();
            Rect rect = Rect(0, 0, s.width, s.height);
            //Check the click area
            if (rect.containsPoint(locationInNode))
            {
                OpenWeb* test = new OpenWeb();
                test->OpenOrder();
                delete test;
                test = NULL;
            }
        };
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerOrder, orderUp);
        

    }
    
    //greeting();
    upArrow =Sprite::create("game/up.png");
    rightArrow =Sprite::create("game/right.png");
    downArrow =Sprite::create("game/down.png");
    leftArrow =Sprite::create("game/left.png");

    if (section==_BIRTH) {
        talkOrder.push_back(_LION);
        talkOrder.push_back(_ME);
        talkOrder.push_back(_LION);
        talkOrder.push_back(_ME);
        talkOrder.push_back(_LION);
        talkOrder.push_back(_LION);
        talkOrder.push_back(_LION);
        talkOrder.push_back(_LION);
        talkOrder.push_back(_LION);
        talkOrder.push_back(_LION);
        chatss.push_back("Hi " + UserDefault::getInstance()->getStringForKey("Name")+", Welcome to Penn State!");
        chatss.push_back("Hi..Eh..What is this?");
        chatss.push_back("This is a game that can help you get familiar with campus. ");
        chatss.push_back("What can I do in the game?");
        chatss.push_back("You can walk around and explore the campus.");
        chatss.push_back("Especially if you are a freshman, I suggest you start from your dorm and explore as many buildings as you can.");
        chatss.push_back("And try not to get lost!");
        chatss.push_back("Have Fun in Campuspedia!!");
        chatss.push_back("OH, one more thing. Be careful, something out there might surprise you.");
        chatss.push_back("Bye!!");
        greeting();
    }

    //else if (section==_MOVE) {
    

        auto listener0 = EventListenerTouchOneByOne::create();
        auto listener1 = EventListenerTouchOneByOne::create();
        auto listener2 = EventListenerTouchOneByOne::create();
        auto listener3 = EventListenerTouchOneByOne::create();
        
        listener0->onTouchBegan = [=](Touch* touch, Event* event){
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            
            //Get the position of the current point relative to the button
            Point locationInNode = target->convertToNodeSpace(touch->getLocation());
            Size s = target->getContentSize();
            Rect rect = Rect(0, 0, s.width, s.height);
            
            //Check the click area
            if (rect.containsPoint(locationInNode))
            {
                dir=0;
                return true;
            }
            return true; // if you are consuming it
        };
        listener0->onTouchEnded = [=](Touch* touch, Event* event){
            dir=-1;
        };
        listener1->onTouchBegan = [=](Touch* touch, Event* event){
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            
            //Get the position of the current point relative to the button
            Point locationInNode = target->convertToNodeSpace(touch->getLocation());
            Size s = target->getContentSize();
            Rect rect = Rect(0, 0, s.width, s.height);
            
            //Check the click area
            if (rect.containsPoint(locationInNode))
            {
                dir=1;
                return true;
            }
            return true; // if you are consuming it
        };
        listener1->onTouchEnded = [=](Touch* touch, Event* event){
            dir=-1;
        };
        listener2->onTouchBegan = [=](Touch* touch, Event* event){
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            
            //Get the position of the current point relative to the button
            Point locationInNode = target->convertToNodeSpace(touch->getLocation());
            Size s = target->getContentSize();
            Rect rect = Rect(0, 0, s.width, s.height);
            
            //Check the click area
            if (rect.containsPoint(locationInNode))
            {
                dir=2;
                return true;
            }
            return true; // if you are consuming it
        };
        listener2->onTouchEnded = [=](Touch* touch, Event* event){
            dir=-1;
        };
        listener3->onTouchBegan = [=](Touch* touch, Event* event){
            auto target = static_cast<Sprite*>(event->getCurrentTarget());
            
            //Get the position of the current point relative to the button
            Point locationInNode = target->convertToNodeSpace(touch->getLocation());
            Size s = target->getContentSize();
            Rect rect = Rect(0, 0, s.width, s.height);
            
            //Check the click area
            if (rect.containsPoint(locationInNode))
            {
                dir=3;
                return true;
            }
            return true; // if you are consuming it
        };
        listener3->onTouchEnded = [=](Touch* touch, Event* event){
            dir=-1;
        };

    //set Arrow position
    {
        
        upArrow->setPosition(Vec2(visibleSize.width*0.15+origin.x,visibleSize.height*0.3+origin.y));
        this->addChild(upArrow,3);
        
        rightArrow->setPosition(Vec2(0.2*visibleSize.width+origin.x,visibleSize.height*0.2+origin.y));
        this->addChild(rightArrow,3);
        
        downArrow->setPosition(Vec2(visibleSize.width*0.15+origin.x,visibleSize.height*0.1+origin.y));
        this->addChild(downArrow,3);
        
        leftArrow->setPosition(Vec2(0.1*visibleSize.width+origin.x,visibleSize.height*0.2+origin.y));
        this->addChild(leftArrow,3);
        //#####################################
    }
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener0, upArrow);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, rightArrow);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, downArrow);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener3, leftArrow);
    this-> scheduleUpdate();
    //}//set Arrow
    return true;
}

void Game::update(float dt) {
    if (stopFrame==false) {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        bool stop =false;
        Point position;
        if(dir==0) {
            position=Vec2(player->getPosition().x,player->getPosition().y+tileWidth/4.0/*+player->getContentSize().height/2*/);
        }
        else if(dir==1) {
            position=Vec2(player->getPosition().x+tileWidth/4.0+player->getContentSize().width,player->getPosition().y/*-player->getContentSize().height/2*/);
        }
        else if(dir==2) {
            position=Vec2(player->getPosition().x,player->getPosition().y-tileWidth/4.0/*-player->getContentSize().height/2*/);
        }
        else if(dir==3) {
            position=Vec2(player->getPosition().x-tileWidth/4.0/*-player->getContentSize().width/2*/,player->getPosition().y/*-player->getContentSize().height/2*/);
        }
        if (dir>=0 && position.x >0 && position.y>0) {
            Point tileCoord = this->tileCoordForPosition(position);
            //std::cout<<tileCoord.x<<"     "<<tileCoord.y<<std::endl;
            int tileGid = building->getTileGIDAt(tileCoord);
            //std::cout<<tileGid<<std::endl;
            if (tileGid) {
                Value test=map->getPropertiesForGID(tileGid);
                ValueMap properties = test.asValueMap();
                if (!properties.empty()) {
                    auto collision = properties["collision"].asString();
                    if (collision=="false") {
                        stop = true;
                    }
                    else if (collision=="true" && disable<=0) {
                        if (scene==_DORM) {
                            int dorm=scene=UserDefault::getInstance()->getIntegerForKey("Dorm");
                            if (dorm==_POLLOCK) {
                                //up
                                if (tileCoord.x<=1 && tileCoord.y<=4) {
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_LIFESC);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                    std::cout<<"POLLOCK -> LS\n";
                                    changeScene();
                                }
                                //right
                                else if(tileCoord.x>=40){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                    UserDefault::getInstance()->setIntegerForKey("Dorm",_EAST);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                    std::cout<<"POLLOCK -> EAST\n";
                                    changeScene();
                                }
                                //down
                                else if(tileCoord.y>=22&&tileCoord.x>=13){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                    UserDefault::getInstance()->setIntegerForKey("Dorm",_SOUTH);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                    std::cout<<"POLLOCK -> SOUTH\n";
                                    changeScene();
                                }
                                //left
                                else if(tileCoord.x<=4&&tileCoord.y>=10){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                    UserDefault::getInstance()->setIntegerForKey("Dorm",_SOUTH);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                    std::cout<<"POLLOCK -> SOUTH\n";
                                    changeScene();
                                }
                            }
                            else if (dorm==_EAST) {
                                //up
                                if (tileCoord.x<=1 && tileCoord.y<=8) {
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                    UserDefault::getInstance()->setIntegerForKey("Dorm", _NORTH);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                    std::cout<<"EAST -> NORTH\n";
                                    changeScene();
                                }
                                //down
                                else if(tileCoord.y>=22&&tileCoord.x>=13){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                    UserDefault::getInstance()->setIntegerForKey("Dorm",_POLLOCK);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                    std::cout<<"EAST -> PALLOCK\n";
                                    changeScene();
                                }
                                //left
                                else if(tileCoord.x<=1 &&tileCoord.y>=19){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_PATTEE);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                    std::cout<<"EAST -> PATTEE\n";
                                    changeScene();
                                }
                            }
                            else if (dorm==_WEST){
                                //up
                                if (tileCoord.x>=40 && tileCoord.y<=5) {
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_PATTEE);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_LEFT);
                                    std::cout<<"WEST -> PATTEE\n";
                                    changeScene();
                                }
                                //right
                                else if(tileCoord.x>=35 && tileCoord.y>=22){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_OLDMAIN);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_UP);
                                    std::cout<<"WEST -> OLDMAIN\n";
                                    changeScene();
                                }
                                //down
                                else if(tileCoord.y>=22&&tileCoord.x<=22){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_IST);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                    std::cout<<"WEST -> IST\n";
                                    changeScene();
                                }
                                //left
                                else if(tileCoord.x<=9&&tileCoord.y>=18){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_IST);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_UP);
                                    std::cout<<"WEST -> IST\n";
                                    changeScene();
                                }
                            }
                            else if (dorm==_NORTH){
                                //right
                                if(tileCoord.x>=40){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                    UserDefault::getInstance()->setIntegerForKey("Dorm",_EAST);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_UP);
                                    std::cout<<"NORTH -> EAST\n";
                                    changeScene();
                                }
                                //down
                                else if(tileCoord.y>=22&&tileCoord.x>=34){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_LIFESC);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_UP);
                                    std::cout<<"NORTH -> LS\n";
                                    changeScene();
                                }
                                //left
                                else if(tileCoord.x<=5&&tileCoord.y>=22){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_PATTEE);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                    std::cout<<"NORTH -> PATTEE\n";
                                    changeScene();
                                }
                            }
                            else if (dorm==_SOUTH){
                                //up
                                if (tileCoord.x>=14 && tileCoord.x<=15 && tileCoord.y<=3) {
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_LIFESC);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                    std::cout<<"SOUTH -> LS\n";
                                    changeScene();
                                }
                                //right
                                else if(tileCoord.x>=23 && tileCoord.y<=13){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                    UserDefault::getInstance()->setIntegerForKey("Dorm",_POLLOCK);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_LEFT);
                                    std::cout<<"SOUTH -> POLLOCK\n";
                                    changeScene();
                                }
                                //down
                                else if(tileCoord.y>=14&&tileCoord.x>=23){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                    UserDefault::getInstance()->setIntegerForKey("Dorm",_POLLOCK);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                    std::cout<<"SOUTH -> POLLOCK\n";
                                    changeScene();
                                }
                                //left
                                else if(tileCoord.x<=8&&tileCoord.y>=7){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_HUB);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                    std::cout<<"SOUTH -> HUB\n";
                                    changeScene();
                                }
                                else if(tileCoord.x<=9 && tileCoord.y<=4){
                                    UserDefault::getInstance()->setIntegerForKey("Scene",_HUB);
                                    UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                    std::cout<<"SOUTH -> HUB\n";
                                    changeScene();
                                }
                            }
                        }
                        else if(scene==_HUB){
                            //up
                            if (tileCoord.y<=3) {
                                UserDefault::getInstance()->setIntegerForKey("Scene",_PATTEE);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                std::cout<<"HUB -> PATTEE\n";
                                changeScene();
                            }
                            //right
                            else if(tileCoord.x>=40 && tileCoord.y<=8){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_LIFESC);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_LEFT);
                                std::cout<<"HUB -> LS\n";
                                changeScene();
                            }
                            //down
                            else if(tileCoord.y>=17&&tileCoord.x>=38){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_SOUTH);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_LEFT);
                                std::cout<<"HUB -> SOUTH\n";
                                changeScene();
                            }
                            //left
                            else if(tileCoord.x<=1){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_OLDMAIN);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                std::cout<<"HUB -> OLDMAIN\n";
                                changeScene();
                            }
                        }
                        else if(scene==_PATTEE){
                            if (tileCoord.x>=39) {
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_EAST);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_LEFT);
                                std::cout<<"PATTEE -> EAST\n";
                                changeScene();
                            }
                            else if(tileCoord.x<=1){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_WEST);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_UP);
                                std::cout<<"PATTEE -> WEST\n";
                                changeScene();
                            }
                            else if (tileCoord.y>=22){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_OLDMAIN);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                std::cout<<"PATTEE -> OLDMAIN\n";
                                changeScene();
                            }
                        }
                        else if(scene==_IST){
                            if (tileCoord.y<=3 && tileCoord.x<=25) {
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_WEST);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_LEFT);
                                std::cout<<"IST -> EAST\n";
                                changeScene();
                            }
                            else if(tileCoord.x>=38 && tileCoord.y<=3){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_WEST);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                std::cout<<"IST -> WEST\n";
                                changeScene();
                            }
                            else if(tileCoord.x>=40 && tileCoord.y>=12){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_OLDMAIN);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_LEFT);
                                std::cout<<"IST -> OLDMAIN\n";
                                changeScene();
                            }
                            else if(tileCoord.x>=5 && tileCoord.x<=7){
                                std::cout<<"IST -> ARENA\n";
                                stopFrame=true;
                                UserDefault::getInstance()->setIntegerForKey("Scene",_ARENA);
                                changeScene();
                                /*
                                auto arenaScene=Arena::createScene();
                                Director::getInstance()->replaceScene(TransitionFade::create(0.5, arenaScene, Color3B(0,0,0)));*/
                            }
                            else if(tileCoord.x>=29 && tileCoord.x<=31){
                                std::cout<<"IST -> ARENA\n";
                                stopFrame=true;
                                UserDefault::getInstance()->setIntegerForKey("Scene",_ARENA);
                                changeScene();
                                /*
                                auto arenaScene=Arena::createScene();
                                Director::getInstance()->replaceScene(TransitionFade::create(0.5, arenaScene, Color3B(0,0,0)));
                                 */
                            }
                        }
                        else if(scene==_OLDMAIN){
                            if (tileCoord.x>=40) {
                                UserDefault::getInstance()->setIntegerForKey("Scene",_HUB);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_LEFT);
                                std::cout<<"OLDMAIN -> HUB\n";
                                changeScene();
                            }
                            else if(tileCoord.x<=1){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_IST);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                std::cout<<"OLDMAIN -> IST\n";
                                changeScene();
                            }
                            else if (tileCoord.x>=2 && tileCoord.x<=6){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_WEST);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                std::cout<<"OLDMAIN -> WEST\n";
                                changeScene();
                            }
                            else if (tileCoord.x>=16 && tileCoord.x<=19){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_WEST);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                std::cout<<"OLDMAIN -> WEST\n";
                                changeScene();
                            }
                            else if (tileCoord.x>=24 && tileCoord.x<=28){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_PATTEE);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                std::cout<<"OLDMAIN -> PATTEE\n";
                                changeScene();
                            }
                        }
                        else if(scene==_LIFESC){
                            if (tileCoord.x>=32) {
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_POLLOCK);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_UP);
                                std::cout<<"LS -> POLLOCK\n";
                                changeScene();
                            }
                            else if(tileCoord.x<=1){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_HUB);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_RIGHT);
                                std::cout<<"LS -> HUB\n";
                                changeScene();
                            }
                            else if (tileCoord.x>=15 && tileCoord.x<=19 && tileCoord.y>=22){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_SOUTH);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_UP);
                                std::cout<<"LS -> SOUTH\n";
                                changeScene();
                            }
                            else if (tileCoord.x>=14 && tileCoord.x<=18 && tileCoord.y<=3){
                                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                                UserDefault::getInstance()->setIntegerForKey("Dorm",_NORTH);
                                UserDefault::getInstance()->setIntegerForKey("Entry",_DOWN);
                                std::cout<<"LS -> NORTH\n";
                                changeScene();
                            }
                        }
                        
                    }
                }
            }
        }
        if(dir==0 && player->getPosition().y+tileWidth/4.0<visibleSize.height-player->getContentSize().height/*/2*/ && stop==false)
        {
            player->setPosition(Vec2(player->getPosition().x,player->getPosition().y+tileWidth/4.0));
            disable--;
        }
        else if (dir==1 && player->getPosition().x+tileWidth/4.0<visibleSize.width-player->getContentSize().width/*/2*/&& stop==false)
        {
            player->setPosition(Vec2(player->getPosition().x+tileWidth/4.0,player->getPosition().y));
            disable--;
        }
        else if (dir==2 && player->getPosition().y-tileWidth/4.0>0/*+player->getContentSize().height/2*/&& stop==false)
        {
            player->setPosition(Vec2(player->getPosition().x,player->getPosition().y-tileWidth/4.0));
            disable--;
        }
        else if (dir==3 && player->getPosition().x-tileWidth/4.0>0/*+player->getContentSize().width/2*/&& stop==false)
        {
            player->setPosition(Vec2(player->getPosition().x-tileWidth/4.0,player->getPosition().y));
            disable--;
        }
        

    }
}


void Game::menuCloseCallback(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
