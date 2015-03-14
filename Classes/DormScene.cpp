#include "DormScene.h"
#include "ChooseScene.h"
#include <iostream>
#include "transitScene.h"
using namespace cocos2d::ui;


USING_NS_CC;

Scene* Dorm::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Dorm::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Dorm::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    auto dormBG=Sprite::create("choose/bg.png");
    dormBG->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(dormBG,0);
    
    pollock = Button::create("choose/pollockBall.png");
    east = Button::create("choose/eastBall.png");
    north = Button::create("choose/northBall.png");
    south = Button::create("choose/southBall.png");
    west = Button::create("choose/westBall.png");
    pollockInfo=Sprite::create("choose/pollockInfo.png");
    eastInfo=Sprite::create("choose/eastInfo.png");
    northInfo=Sprite::create("choose/northInfo.png");
    southInfo=Sprite::create("choose/southInfo.png");
    westInfo=Sprite::create("choose/westInfo.png");
    start = Button::create("choose/start.png");
    
    pollock->setPosition(Vec2(origin.x+0.46*visibleSize.width, origin.y+0.29*visibleSize.height));
    east->setPosition(Vec2(origin.x+0.265*visibleSize.width, origin.y+0.48*visibleSize.height));
    north->setPosition(Vec2(origin.x+0.70*visibleSize.width, origin.y+0.453*visibleSize.height));
    south->setPosition(Vec2(origin.x+0.369*visibleSize.width, origin.y+0.68*visibleSize.height));
    west->setPosition(Vec2(origin.x+0.571*visibleSize.width,origin.y+0.63*visibleSize.height));
    
    pollockInfo->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    eastInfo->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    northInfo->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    southInfo->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    westInfo->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    pollockInfo->setVisible(false);
    eastInfo->setVisible(false);
    northInfo->setVisible(false);
    westInfo->setVisible(false);
    southInfo->setVisible(false);
    start->setPosition(Vec2(origin.x+0.90*visibleSize.width,origin.y+0.90*visibleSize.height));
    this->addChild(pollock,1);
    this->addChild(east,1);
    this->addChild(north,1);
    this->addChild(west,1);
    this->addChild(south,1);
    this->addChild(pollockInfo,2);
    this->addChild(eastInfo,2);
    this->addChild(northInfo,2);
    this->addChild(westInfo,2);
    this->addChild(southInfo,2);
    this->addChild(start,1);

    start->setVisible(false);

    //auto fadeIn = FadeIn::create(1.0f);
    //auto fadeOut = FadeOut::create(1.0f);
    
    pollock->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:{
                if(current==1) pollockInfo->setVisible(false);
                else if(current==2) eastInfo->setVisible(false);
                else if(current==3) northInfo->setVisible(false);
                else if(current==4) southInfo->setVisible(false);
                else if(current==5) westInfo->setVisible(false);
                break;


            }
            case ui::Widget::TouchEventType::ENDED:{
                pollock->setOpacity(100);
                west->setOpacity(255);
                east->setOpacity(255);
                south->setOpacity(255);
                north->setOpacity(255);
                pollockInfo->setVisible(true);
                start->setVisible(true);
                current=1;
                std::cout<<"Tooch: Current: "<<current<<std::endl;
                break;
            }
            default:
                break;
        }
    });
    east->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:{
                if(current==1) pollockInfo->setVisible(false);
                else if(current==2) eastInfo->setVisible(false);
                else if(current==3) northInfo->setVisible(false);
                else if(current==4) southInfo->setVisible(false);
                else if(current==5) westInfo->setVisible(false);
                break;
            }
            case ui::Widget::TouchEventType::ENDED:{
                east->setOpacity(100);
                west->setOpacity(255);
                pollock->setOpacity(255);
                south->setOpacity(255);
                north->setOpacity(255);
                eastInfo->setVisible(true);
                start->setVisible(true);
                current=2;
                std::cout<<"Tooch: Current: "<<current<<std::endl;
                break;

            }
            default:
                break;
        }
    });
    north->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:{
                if(current==1) pollockInfo->setVisible(false);
                else if(current==2) eastInfo->setVisible(false);
                else if(current==3) northInfo->setVisible(false);
                else if(current==4) southInfo->setVisible(false);
                else if(current==5) westInfo->setVisible(false);
                break;
            }
            case ui::Widget::TouchEventType::ENDED:{
                north->setOpacity(100);
                west->setOpacity(255);
                pollock->setOpacity(255);
                east->setOpacity(255);
                south->setOpacity(255);
                northInfo->setVisible(true);
                start->setVisible(true);
                current=3;
                std::cout<<"Tooch: Current: "<<current<<std::endl;
                break;

            }
            default:
                break;
        }
    });
    south->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:{
                if(current==1) pollockInfo->setVisible(false);
                else if(current==2) eastInfo->setVisible(false);
                else if(current==3) northInfo->setVisible(false);
                else if(current==4) southInfo->setVisible(false);
                else if(current==5) westInfo->setVisible(false);
                break;
            }
            case ui::Widget::TouchEventType::ENDED:{
                south->setOpacity(100);
                west->setOpacity(255);
                pollock->setOpacity(255);
                east->setOpacity(255);
                north->setOpacity(255);
                southInfo->setVisible(true);
                start->setVisible(true);
                current=4;
                break;

            }
            default:
                break;
        }
    });
    west->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:{
                if(current==1) pollockInfo->setVisible(false);
                else if(current==2) eastInfo->setVisible(false);
                else if(current==3) northInfo->setVisible(false);
                else if(current==4) southInfo->setVisible(false);
                else if(current==5) westInfo->setVisible(false);
                break;
            }
            case ui::Widget::TouchEventType::ENDED:{
                west->setOpacity(100);
                pollock->setOpacity(255);
                east->setOpacity(255);
                south->setOpacity(255);
                north->setOpacity(255);
                westInfo->setVisible(true);
                start->setVisible(true);
                current=5;
                std::cout<<"Tooch: Current: "<<current<<std::endl;
                break;

            }
            default:
                break;
        }
    });
    start->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                UserDefault::getInstance()->setIntegerForKey("Dorm",current);
                UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                UserDefault::getInstance()->setIntegerForKey("Entry",_BIRTH);
                UserDefault::getInstance()->setIntegerForKey("Choosen", current);
                std::cout<<"Birth: Dorm: "<<current<<std::endl;
                auto gameScene=Transit::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, gameScene, Color3B(0,0,0)));
                break;
            }
            default:
                break;
        }
    });
    
        /*
     // add "HelloWorld" splash screen"
     auto sprite = Sprite::create("school/school.png");
     
     // position the sprite on the center of the screen
     sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
     
     // add the sprite as a child to this layer
     this->addChild(sprite, 0);
     */
    auto back = Button::create("choose/back.png");
    back->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                auto chooseScene=Choose::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, chooseScene, Color3B(0,0,0)));
                break;
            }
            default:
                break;
        }
    });
    back->setPosition(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height*0.1));
    this->addChild(back,1);
    return true;
}


void Dorm::menuCloseCallback(Ref* pSender)
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
