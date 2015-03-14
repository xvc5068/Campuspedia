#include "NameScene.h"
#include "SchoolScene.h"
#include <iostream>
using namespace cocos2d::ui;

USING_NS_CC;

Scene* Name::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Name::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Name::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto title=Sprite::create("choose/nameTitle.png");
    title->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.8));
    this->addChild(title,1);
    textField = TextField::create("Your Name","fonts/arial.ttf",45);
    textField->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.6));
    this->addChild(textField,1);
    next=Button::create("choose/next.png");
    next->setPosition(Vec2(origin.x+visibleSize.width*0.9,origin.y+visibleSize.height*0.1));
    this->addChild(next,1);
    next->setVisible(false);
    textField->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        next->setVisible(true);
    });
    auto back = Button::create("backw.png");
    back->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                auto schoolScene=School::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, schoolScene, Color3B(0,0,0)));
                break;
            }
            default:
                break;
        }
    });
    back->setPosition(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height*0.1));
    this->addChild(back,1);
    next->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                UserDefault::getInstance()->setStringForKey("Name",textField->getString());
                std::string myName=UserDefault::getInstance()->getStringForKey("Name");
                std::cout<<myName<<std::endl;
                auto chooseScene=Choose::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, chooseScene, Color3B(0,0,0)));
                break;
            }
            default:
                break;
        }
    });

    /////////////////////////////
    
    return true;
}


void Name::menuCloseCallback(Ref* pSender)
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
