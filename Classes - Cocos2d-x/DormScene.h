#ifndef __DORM_SCENE_H__
#define __DORM_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"



class Dorm : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Dorm);
private:
    cocos2d::Sprite* pollockInfo;
    cocos2d::Sprite* eastInfo;
    cocos2d::Sprite* southInfo;
    cocos2d::Sprite* northInfo;
    cocos2d::Sprite* westInfo;
    cocos2d::ui::Button* start;
    cocos2d::ui::Button* east;
    cocos2d::ui::Button* north;
    cocos2d::ui::Button* pollock;
    cocos2d::ui::Button* south;
    cocos2d::ui::Button* west;
    int current;
};

#endif // __HELLOWORLD_SCENE_H__
