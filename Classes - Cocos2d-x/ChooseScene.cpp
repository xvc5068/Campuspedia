#include "ChooseScene.h"
#include "NameScene.h"
using namespace cocos2d::ui;

USING_NS_CC;


Scene* Choose::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Choose::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Choose::init()
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
    auto GenderTitle = Sprite::create("choose/title.png");
    GenderTitle->setPosition(Vec2(origin.x+visibleSize.width/2,
                              origin.y+visibleSize.height/2 ));
    this->addChild(GenderTitle,1);
    
    auto boy = Button::create("choose/boy.png");
    auto girl = Button::create("choose/girl.png");
    boy->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                UserDefault::getInstance()->setIntegerForKey("Gender",1);
                //auto dormScene=Dorm::createScene();
                auto dormScene=Dorm::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, dormScene, Color3B(0,0,0)));
                break;
            }
            default:
                break;
        }
    });
    girl->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                UserDefault::getInstance()->setIntegerForKey("Gender",2);
                //auto dormScene=Dorm::createScene();
                auto dormScene=Dorm::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, dormScene, Color3B(0,0,0)));
                break;
            }
            default:
                break;
        }
    });
    boy->setPosition(Vec2(origin.x+visibleSize.width/4,
                             origin.y+visibleSize.height/2));
    girl->setPosition(Vec2(origin.x+3*visibleSize.width/4,
                          origin.y+visibleSize.height/2));
    this->addChild(girl,1);
    this->addChild(boy,1);
    auto back = Button::create("backw.png");
    back->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
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
    back->setPosition(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height*0.1));
    this->addChild(back,1);
    /*
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("school/school.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    */
    return true;
}


void Choose::menuCloseCallback(Ref* pSender)
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
