#include "HelloWorldScene.h"
#include "transitScene.h"
#include "SimpleAudioEngine.h"
#include <iostream>
using namespace cocos2d::ui;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    
    // set the background music and continuously play it.
    audio->playBackgroundMusic("audio/bgmusic.mp3", true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    /*
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
     */
    // create menu, it's an autorelease object
    auto menu = Menu::create( NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    /*auto myTitle = Sprite::create("title.png");
    myTitle->setPosition(Vec2(origin.x+visibleSize.width/4,
                              origin.y+visibleSize.height - myTitle->getContentSize().height/1.5));
    this->addChild(myTitle,1);*/
    
    auto button = Button::create("start/start.png");
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
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
    button->setPosition(Vec2(origin.x+visibleSize.width*0.3, origin.y+visibleSize.height*0.22));
    
    this->addChild(button,1);
    std::cout<<UserDefault::getInstance()->getIntegerForKey("Choosen")<<std::endl;
    if (UserDefault::getInstance()->getIntegerForKey("Choosen")==_POLLOCK ||UserDefault::getInstance()->getIntegerForKey("Choosen")==_SOUTH || UserDefault::getInstance()->getIntegerForKey("Choosen")==_EAST || UserDefault::getInstance()->getIntegerForKey("Choosen")==_WEST || UserDefault::getInstance()->getIntegerForKey("Choosen")==_NORTH) {
        auto resume=Button::create("start/continue.png");
        resume->setPosition(Vec2(origin.x+visibleSize.width*0.6,origin.y+visibleSize.height*0.22));
        this->addChild(resume,3);
        resume->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    break;
                case ui::Widget::TouchEventType::ENDED:{
                    UserDefault::getInstance()->setIntegerForKey("Dorm",UserDefault::getInstance()->getIntegerForKey("Choosen"));
                    UserDefault::getInstance()->setIntegerForKey("Scene",_DORM);
                    UserDefault::getInstance()->setIntegerForKey("Entry",_NONBIRTH);
                    auto Scene=Transit::createScene();
                    Director::getInstance()->replaceScene(TransitionFade::create(0.5, Scene, Color3B(0,0,0)));
                    break;
                }
                default:
                    break;
            }
        });
        button->setPosition(Vec2(origin.x+visibleSize.width*0.3, origin.y+visibleSize.height*0.22));
    }
    /*auto start = Sprite::create("start.png");
    start->setPosition(Vec2(origin.x+3*visibleSize.width/4+start->getContentSize().width/2,
                              origin.y+visibleSize.height/4));
    this->addChild(start,1);*/
    /*
    auto player = Sprite::create("player.png");
    player->setPosition(Vec2(origin.x+5*visibleSize.width/16,
                            origin.y+player->getContentSize().height));
    this->addChild(player,1);
    
    auto label = Label::createWithTTF("Xiangren Chen", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
     */
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("start/opening.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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
