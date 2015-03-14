#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;

#define _HUB 1
#define _PATTEE 2
#define _IST 3
#define _OLDMAIN 4
#define _LIFESC 5
#define _DORM 0
#define _POLLOCK 1
#define _EAST 2
#define _NORTH 3
#define _SOUTH 4
#define _WEST 5
#define _BIRTH -1
#define _NONBIRTH -2
#define _UP 0
#define _RIGHT 1
#define _DOWN 2
#define _LEFT 3
#define _ARENA 10
#define _GREETING 1
#define _MOVE 2
#define _LION 1
#define _ME 2

class Game : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void changeScene();
    cocos2d::Point tileCoordForPosition(cocos2d::Point position);
    void initMap();
    void greeting();
    void update(float dt);
    cocos2d::Point adjustPosition(cocos2d::Point position);
    // implement the "static create()" method manually
    CREATE_FUNC(Game);
    
private:
    int dir;
    Sprite* player;
    Sprite* chatbg;
    Sprite* lion;
    Sprite* me;
    Sprite* upArrow;
    Sprite* rightArrow;
    Sprite* downArrow;
    Sprite* leftArrow;
    MoveBy* move;
    TMXTiledMap* map;
    TMXLayer* building;
    std::vector<std::string> chatss;
    std::vector<int> talkOrder;
    Label* NameL;
    Label* chat;
    EventListenerTouchOneByOne* listenerChat;
    
    int scene;
    float tileHeight;
    float tileWidth;
    bool stopFrame;
    int disable;
    int section;
    int currentChat;
};

#endif // __HELLOWORLD_SCENE_H__
