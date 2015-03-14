#ifndef __ARENA_SCENE_H__
#define __ARENA_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;

#define _HUB 1
#define _PATTEE 2
#define _IST 3
#define _DORM 0
#define _POLLOCK 1
#define _EAST 2
#define _NORTH 3
#define _SOUTH 4
#define _WEST 5
#define _BIRTH -1
#define _UP 0
#define _RIGHT 1
#define _DOWN 2
#define _LEFT 3
#define _ARENA 10
#define _GREETING 1
#define _MOVE 2
#define _LION 1
#define _ME 2
#define _Boss1 3
#define _Boss2 4
#define _Boss3 5

#define _A 1
#define _B 2
#define _C 3
#define _D 4

#define _boss1HP 3
#define _boss2HP 5
#define _boss3HP 7
#define _boss1Freq 80
#define _boss1Amount 1
#define _boss2Freq 80
#define _boss2Amount 2
#define _boss3Freq 80
#define _boss3Amount 3
#define _iceBallSpeed1 20
#define _iceBallSpeed2 20
#define _iceBallSpeed3 10
#define _starPeriod 300

class Arena : public cocos2d::Layer
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
    void showStar();
    void startBoss(int boss_num);
    void startIceball();
    void startQuestion();
    void congra();
    void nextBoss();
    void update(float dt);
    cocos2d::Point adjustPosition(cocos2d::Point position);
    // implement the "static create()" method manually
    CREATE_FUNC(Arena);
    
private:
    int dir;
    Sprite* player;
    Sprite* chatbg;
    Sprite* lion;
    Sprite* me;
    Sprite* boss1;
    Sprite* boss2;
    Sprite* boss3;
    Sprite* star;
    Sprite* upArrow;
    Sprite* rightArrow;
    Sprite* downArrow;
    Sprite* leftArrow;
    Sprite* Wrong;
    Sprite* Correct;
    Vector<Sprite*> burnSprites;
    int currentBurn;
    Sprite* burnSprite0;
    Sprite* burnSprite1;
    Sprite* burnSprite2;
    Sprite* bossBurnSprite;
    MoveBy* move;
    TMXTiledMap* map;
    TMXLayer* building;
    std::vector<std::string> chatss;
    std::vector<int> talkOrder;
    std::vector<int> questionSet;
    Label* NameL;
    Label* chat;
    Label* meHP;
    Label* BossHP;
    EventListenerTouchOneByOne* listenerChat;
    Size visibleSize;
    Vec2 origin;
    Vector<Sprite*> iceballs;
    Vector<SpriteFrame*> burn;
    Vector<SpriteFrame*> bossBurn;
    //Vector<SpriteFrame*> burn;
    Node* node;
    Node* bossNode;
    Node* chatNode;
    Animate* animate1;
    Animate* animate2;
    Animate* animate3;
    Animate* bossAnimate;
    Animation* animation1;
    Animation* animation2;
    Animation* animation3;
    Animation* bossAnimation;
    Vector<Animate*> Animate;
//    SpriteFrame* aa;
//SpriteFrame* bb;
//    SpriteFrame* cc;
//    SpriteFrame* dd;
//   SpriteFrame* ee;
    
    
    int _meHP;
    int _bossHP;
    int scene;
    float tileHeight;
    float tileWidth;
    bool stopFrame;
    int disable;
    int section;
    int currentChat;
    int _Boss;
    int iceBallFreq;
    int fire;
    int ballMove;
    int _star;
    int key;
    int questionIndex;
    int wrong;
    int correct;
    int pause;
};

#endif // __HELLOWORLD_SCENE_H__
