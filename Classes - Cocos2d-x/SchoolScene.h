#ifndef __SCHOOL_SCENE_H__
#define __SCHOOL_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "NameScene.h"
using namespace cocos2d::ui;

class School : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(School);
    
private:
    Vector<Sprite*> deburger;
    Vector<Button*> photos;
    Sprite* up;
    Sprite* page1on;
    Sprite* page1off;
    Sprite* page2on;
    Sprite* page2off;
    Button* next;
    Button* previous;
    Button* start;
    int page;
    Node* bug;
};

#endif // __HELLOWORLD_SCENE_H__
