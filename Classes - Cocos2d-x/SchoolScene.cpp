#include "SchoolScene.h"
#include "HelloWorldScene.h"
using namespace cocos2d::ui;

USING_NS_CC;

Scene* School::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = School::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool School::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto sprite = Sprite::create("school/bg.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    page1on = Sprite::create("school/page1on.png");
    page1off = Sprite::create("school/page1off.png");
    page2on = Sprite::create("school/page2on.png");
    page2off = Sprite::create("school/page2off.png");
    up=Sprite::create("school/up.png");
    next=Button::create("school/next.png");
    previous=Button::create("school/previous.png");
    start=Button::create("school/start.png");
    
    next->setPosition(Vec2(origin.x+visibleSize.width*0.7,origin.y+visibleSize.height*0.8));
    previous->setPosition(Vec2(origin.x+visibleSize.width*0.7,origin.y+visibleSize.height*0.8));
    start->setPosition(Vec2(origin.x+visibleSize.width*0.25, origin.y+visibleSize.height*0.35));
    this->addChild(next,2);
    this->addChild(previous,2);
    this->addChild(start,2);
    this->addChild(up,3);
    up->setVisible(false);
    previous->setVisible(false);
    previous->setEnabled(false);
    start->setVisible(false);
    //bug=Node::create();
    up->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    page1on->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    page1off->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    page2on->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    page2off->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(page1on,1);
    this->addChild(page1off,1);
    this->addChild(page2on,1);
    this->addChild(page2off,1);
    //this->addChild(bug,3);
    page1off->setVisible(false);
    page2on->setVisible(false);
    page2off->setVisible(false);
    page=1;
    
    for (int i=0; i<9; i++) {
        photos.pushBack(Button::create("school/void.png"));
        deburger.pushBack(Sprite::create("school/"+std::to_string(i+1)+".png"));
        deburger.at(i)->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        this->addChild(photos.at(i),3);
        deburger.at(i)->setVisible(false);
        this->addChild(deburger.at(i),4);
    }
    
    photos.at(0)->setPosition(Vec2(origin.x+visibleSize.width*0.416,origin.y+visibleSize.height*0.635));
    photos.at(1)->setPosition(Vec2(origin.x+visibleSize.width*0.585,origin.y+visibleSize.height*0.635));
    photos.at(2)->setPosition(Vec2(origin.x+visibleSize.width*0.754,origin.y+visibleSize.height*0.635));
    photos.at(3)->setPosition(Vec2(origin.x+visibleSize.width*0.416,origin.y+visibleSize.height*0.446));
    photos.at(4)->setPosition(Vec2(origin.x+visibleSize.width*0.585,origin.y+visibleSize.height*0.446));
    photos.at(5)->setPosition(Vec2(origin.x+visibleSize.width*0.754,origin.y+visibleSize.height*0.446));
    photos.at(6)->setPosition(Vec2(origin.x+visibleSize.width*0.416,origin.y+visibleSize.height*0.252));
    photos.at(7)->setPosition(Vec2(origin.x+visibleSize.width*0.585,origin.y+visibleSize.height*0.252));
    photos.at(8)->setPosition(Vec2(origin.x+visibleSize.width*0.754,origin.y+visibleSize.height*0.252));
    photos.at(0)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                if (page==1) {
                    //bug->removeAllChildren();
                    //bug->addChild(up,3);
                    up->setVisible(true);
                    
                    start->setVisible(true);
                    page1off->setVisible(true);
                    page1on->setVisible(false);
                }
                else{
                    deburger.at(0)->setVisible(true);
                    page2off->setVisible(true);
                    page2on->setVisible(false);
                }
                break;
            }
            default:
                break;
        }
    });
    photos.at(1)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:{
                    up->setVisible(false);
                    start->setVisible(false);
                    for (int i=0; i<9; i++) {
                        deburger.at(i)->setVisible(false);
                    }
                    deburger.at(1)->setVisible(true);
                    if (page==1) {
                        page1off->setVisible(true);
                        page1on->setVisible(false);
                    }
                    else{
                        page2off->setVisible(true);
                        page2on->setVisible(false);
                    }
                    break;
                }
                default:
                    break;
            }
        });
    photos.at(2)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                up->setVisible(false);
                start->setVisible(false);
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                deburger.at(2)->setVisible(true);
                if (page==1) {
                    page1off->setVisible(true);
                    page1on->setVisible(false);
                }
                else{
                    page2off->setVisible(true);
                    page2on->setVisible(false);
                }
                break;
            }
            default:
                break;
        }
    });
    photos.at(3)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                up->setVisible(false);
                start->setVisible(false);
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                deburger.at(3)->setVisible(true);
                if (page==1) {
                    page1off->setVisible(true);
                    page1on->setVisible(false);
                }
                else{
                    page2off->setVisible(true);
                    page2on->setVisible(false);
                }
                break;
            }
            default:
                break;
        }
    });
    photos.at(4)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                up->setVisible(false);
                start->setVisible(false);
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                deburger.at(4)->setVisible(true);
                if (page==1) {
                    page1off->setVisible(true);
                    page1on->setVisible(false);
                }
                else{
                    page2off->setVisible(true);
                    page2on->setVisible(false);
                }
                break;
            }
            default:
                break;
        }
    });
    photos.at(5)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                up->setVisible(false);
                start->setVisible(false);
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                deburger.at(5)->setVisible(true);
                if (page==1) {
                    page1off->setVisible(true);
                    page1on->setVisible(false);
                }
                else{
                    page2off->setVisible(true);
                    page2on->setVisible(false);
                }
                break;
            }
            default:
                break;
        }
    });
    photos.at(6)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                up->setVisible(false);
                start->setVisible(false);
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                deburger.at(6)->setVisible(true);
                if (page==1) {
                    page1off->setVisible(true);
                    page1on->setVisible(false);
                }
                else{
                    page2off->setVisible(true);
                    page2on->setVisible(false);
                }
                break;
            }
            default:
                break;
        }
    });
    photos.at(7)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                up->setVisible(false);
                start->setVisible(false);
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                deburger.at(7)->setVisible(true);
                if (page==1) {
                    page1off->setVisible(true);
                    page1on->setVisible(false);
                }
                else{
                    page2off->setVisible(true);
                    page2on->setVisible(false);
                }
                break;
            }
            default:
                break;
        }
    });
    photos.at(8)->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                up->setVisible(false);
                start->setVisible(false);
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                deburger.at(8)->setVisible(true);
                if (page==1) {
                    page1off->setVisible(true);
                    page1on->setVisible(false);
                }
                else{
                    page2off->setVisible(true);
                    page2on->setVisible(false);
                }
                break;
            }
            default:
                break;
        }
    });
    
    next->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                up->setVisible(false);
                start->setVisible(false);
                next->setVisible(false);
                next->setEnabled(false);
                previous->setVisible(true);
                previous->setEnabled(true);
                page1on->setVisible(false);
                page1off->setVisible(false);
                page2on->setVisible(true);
                page2off->setVisible(false);
                page=2;
                break;
            }
            default:
                break;
        }
    });
    previous->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                for (int i=0; i<9; i++) {
                    deburger.at(i)->setVisible(false);
                }
                up->setVisible(false);
                start->setVisible(false);
                next->setVisible(true);
                next->setEnabled(true);
                previous->setVisible(false);
                previous->setEnabled(false);
                page1on->setVisible(true);
                page1off->setVisible(false);
                page2on->setVisible(false);
                page2off->setVisible(false);
                page=1;
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
                auto nameScene=Name::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, nameScene, Color3B(0,0,0)));
                break;
            }
            default:
                break;
        }
    });

    
    /////////////////////////////
    /*
    auto button = Button::create("school/up.png");
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                auto nameScene=Name::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, nameScene, Color3B(0,0,0)));
                break;
            }
            default:
                break;
        }
    });
    button->setPosition(Vec2(origin.x+3*visibleSize.width/4,
                             origin.y+visibleSize.height/2));
    
    this->addChild(button,1);
     */
    // add "HelloWorld" splash screen"
    
    return true;
}


void School::menuCloseCallback(Ref* pSender)
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
