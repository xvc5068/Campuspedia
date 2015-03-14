#include "TransitScene.h"
using namespace cocos2d::ui;

USING_NS_CC;

Scene* Transit::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Transit::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Transit::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    ini=60;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    stopFrame=false;
    scene=UserDefault::getInstance()->getIntegerForKey("Scene");
        auto label=Label::createWithTTF("", "fonts/Calibri.ttf", 120);
        label->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
        this->addChild(label,1);
        if (scene==_DORM) {
            int dorm=UserDefault::getInstance()->getIntegerForKey("Dorm");
            if (dorm==_POLLOCK) {
                label->setString("POLLOCK DORM AREA");
            }
            else if(dorm==_EAST){
                label->setString("EAST DORM AREA");
            }
            else if(dorm==_WEST){
                label->setString("WEST DORM AREA");
            }
            else if(dorm==_SOUTH){
                label->setString("SOUTH DORM AREA");
            }
            else if(dorm==_NORTH){
                label->setString("NORTH DORM AREA");
            }
        }
        else if(scene==_HUB){
            label->setString("HUB AREA");
        }
        else if(scene==_OLDMAIN){
            label->setString("OLD MAIN AREA");
        }
        else if(scene==_LIFESC){
            label->setString("LIFE SCIENCE AREA");
        }
        else if(scene==_PATTEE){
            label->setString("PATTEE LIBRARY AREA");
        }
        else if(scene==_IST){
            label->setString("IST AREA");
        }
        else if(scene==_ARENA){
            label->setString("ARENA");
            auto ist_bg=Sprite::create("transit/ist.png");
            ist_bg->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
            this->addChild(ist_bg,0);
        }
    this->scheduleUpdate();
    return true;
}


void Transit::update(float dt) {
    if (stopFrame==false) {
        if (ini!=0) {
            ini--;
        }
        else{
            stopFrame=true;
            if (scene!=_ARENA) {
                auto Scene=Game::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, Scene, Color3B(0,0,0)));
            }
            else{
                auto arenaScene=Arena::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, arenaScene, Color3B(0,0,0)));
            }
        }
    }
    
}

void Transit::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
