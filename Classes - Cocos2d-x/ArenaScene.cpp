#include "ArenaScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace cocos2d::ui;

USING_NS_CC;

Scene* Arena::createScene(){
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Arena::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

void::Arena::changeScene(){
    stopFrame=true;
    auto nextScene=Arena::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, nextScene, Color3B(0,0,0)));
}

Point Arena::tileCoordForPosition(Point position){
    int x = position.x / map->getTileSize().width;
    int y = ((map->getMapSize().height * map->getTileSize().height) - position.y) / map->getTileSize().height;
    return Point(x, y);
}

Point Arena::adjustPosition(Point position){
    return Point((int)(position.x/tileWidth)*tileWidth+1,(int)(position.y/tileHeight)*tileHeight+1);
}

void Arena::startQuestion(){
    node=Node::create();
    auto question=Label::createWithTTF("This is my question!!!!!!", "fonts/Calibri.ttf", 60);
    question->setWidth(0.8*visibleSize.width);
    question->setAnchorPoint(Vec2(0,1));
    question->setPosition(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height*0.85));
    question->setColor(Color3B(0,0,0));
    node->addChild(question,4);
    auto A=Button::create("arena/button.png");
    auto B=Button::create("arena/button.png");
    auto C=Button::create("arena/button.png");
    auto D=Button::create("arena/button.png");
    auto A_text=Label::createWithTTF("A.  ", "fonts/Calibri.ttf", 60);
    auto B_text=Label::createWithTTF("B.  ", "fonts/Calibri.ttf", 60);
    auto C_text=Label::createWithTTF("C.  ", "fonts/Calibri.ttf", 60);
    auto D_text=Label::createWithTTF("D.  ", "fonts/Calibri.ttf", 60);
    auto bg=Sprite::create("arena/question-bg.png");
    bg->setAnchorPoint(Vec2(0,0));
    A->setAnchorPoint(Vec2(0,0));
    B->setAnchorPoint(Vec2(0,0));
    C->setAnchorPoint(Vec2(0,0));
    D->setAnchorPoint(Vec2(0,0));
    A_text->setAnchorPoint(Vec2(0,1));
    B_text->setAnchorPoint(Vec2(0,1));
    C_text->setAnchorPoint(Vec2(0,1));
    D_text->setAnchorPoint(Vec2(0,1));
    A_text->setWidth(0.3*visibleSize.width);
    B_text->setWidth(0.3*visibleSize.width);
    C_text->setWidth(0.3*visibleSize.width);
    D_text->setWidth(0.3*visibleSize.width);
    A->setPosition(Vec2(origin.x+visibleSize.width*0.08,origin.y+visibleSize.height*0.35));
    B->setPosition(Vec2(origin.x+visibleSize.width*0.55,origin.y+visibleSize.height*0.35));
    C->setPosition(Vec2(origin.x+visibleSize.width*0.08,origin.y+visibleSize.height*0.1));
    D->setPosition(Vec2(origin.x+visibleSize.width*0.55,origin.y+visibleSize.height*0.1));
    A_text->setPosition(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height*0.5));
    B_text->setPosition(Vec2(origin.x+visibleSize.width*0.57,origin.y+visibleSize.height*0.5));
    C_text->setPosition(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height*0.24));
    D_text->setPosition(Vec2(origin.x+visibleSize.width*0.57,origin.y+visibleSize.height*0.24));
    bg->setPosition(Vec2(origin.x,origin.y));
    questionIndex=rand()%questionSet.size();
    int questionN=questionSet[questionIndex];
    if (_Boss==1) {
        if (questionN==1) {
            //GOOD
            question->setString("Which of the following is an invalid variable assignment?");
            //question->setScale(0.3f);
            A_text->setString("A.  short z = 3");
            B_text->setString("B.  char c = “c3");
            C_text->setString("C.  Protected");
            D_text->setString("D.  int y = 37485");
            key=_B;
        }
        //GOOD
        else if (questionN==2){
            question->setString("Information stored in ____ is called volatile because it is usually erased when the computer is turned off.");
            //question->setScale(0.3f);
            A_text->setString("A.  CD-ROM drives");
            B_text->setString("B.  input devices");
            C_text->setString("C.  secondary storage");
            D_text->setString("D.  primary or main memory");
            
            A_text->setScale(0.7f);
            C_text->setScale(0.7f);
            D_text->setScale(0.7f);
            key=_D;
        }
        //GOOD
        else if (questionN==3){
            question->setString("The _____ is responsible for performing calculations and decision making.");
            //question->setScale(0.3f);
            A_text->setString("A.  arithmetic and logic unit");
            B_text->setString("B.  secondary storage");
            C_text->setString("C.  input device");
            D_text->setString("D.  output device");
            A_text->setScale(0.7f);
            B_text->setScale(0.7f);
            C_text->setScale(0.7f);
            D_text->setScale(0.7f);
            key=_A;
        }
        //GOOD
        else if (questionN==4){
            question->setString("What value would be stored in alpha after the following statement is executed?double alpha = (4 + 19) / 3 – 1");
            //question->setScale(0.3f);
            A_text->setString("A.  11.0");
            B_text->setString("B.  7.0");
            C_text->setString("C.  6.0");
            D_text->setString("D.  11.5");
            key=_C;
        }
        //GOOD
        else if (questionN==5){
            question->setString("What is the result of the C++ expression 39 % 7?");
            //question->setScale(1.0f);
            A_text->setString("A.  5.57142");
            B_text->setString("B.  5.0");
            C_text->setString("C.  6");
            D_text->setString("D.  none of the above");
            D_text->setScale(0.7f);
            key=_D;
        }
        //GOOD
        else if (questionN==6){
            question->setString("A missing semicolon (;) is an example of a __________");
            //question->setScale(0.3f);
            A_text->setString("A.  it is not an error");
            B_text->setString("B.  runtime error");
            C_text->setString("C.  syntax error");
            D_text->setString("D.  preprocessor error");
            
            A_text->setScale(0.7f);
            B_text->setScale(0.7f);
            D_text->setScale(0.7f);
            key=_C;
        }
        //GOOD
        else if (questionN==7){
            question->setString("All of the following are examples of logical operators except");
            //question->setScale(0.3f);
            A_text->setString("A.  =");
            B_text->setString("B.  &&");
            C_text->setString("C.  !");
            D_text->setString("D.  ||");
            key=_A;
        }
    }
    else if (_Boss==2) {
        if (questionN==1) {
            //GOOD
            question->setString("You want subclasses in any package to have access to members of a superclass. Which is the most restrictive access that accomplishes this objective?");
            question->setPosition(Vec2(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height*0.9)));
            question->setScale(0.8f);
            A_text->setString("A.  Public");
            B_text->setString("B.  Private");
            C_text->setString("C.  Protected");
            D_text->setString("D.  Transient");
            key=_C;
        }
        else if (questionN==2){
            //GOOD
            question->setString("Which one creates an instance of an array in java?");
            A_text->setString("A.  Int[] ia = new int[15];");
            B_text->setString("B.  Float fa = new float[20];");
            C_text->setString("C.  Char[] ca = “Some String”;");
            D_text->setString("D.  Int ia[][]={4,5,6},{1,2,3};");
            A_text->setScale(0.7f);
            B_text->setScale(0.7f);
            C_text->setScale(0.7f);
            D_text->setScale(0.6f);
            key=_A;
        }
        //GOOD
        else if (questionN==3){
            question->setString("What is the numerical range of char in java?");
            A_text->setString("A.  0 to 32767");
            B_text->setString("B.  0 to 65535");
            C_text->setString("C.  -256 to 255");
            D_text->setString("D.  -32768 to 32767");
            
            D_text->setScale(0.7f);
            key=_B;
        }
        else if (questionN==4){
            //GOOD
            question->setString("Which of the following are Java reserved words? I.Run II.Import III.Default IV.Implement");
            A_text->setString("A.  1 and 2");
            B_text->setString("B.  2 and 3");
            C_text->setString("C.  3 and 4");
            D_text->setString("D.  2 and 4");
            key=_B;
        }
        else if (questionN==5){
            //GOOD
            question->setString("Which is a valid keyword in Java?");
            A_text->setString("A.  interface");
            B_text->setString("B.  string");
            C_text->setString("C.  float");
            D_text->setString("D.  unsigned");
            key=_A;
        }
        //GOOD
        else if (questionN==6){
            question->setString("How many numeric data types are supported in Java?");
            A_text->setString("A.  8");
            B_text->setString("B.  4");
            C_text->setString("C.  2");
            D_text->setString("D.  6");
            key=_D;
        }
        //GOOD
        else if (questionN==7){
            question->setString("In Java if result = 2+3*5, what is the value and type of 'result' variable?");
            A_text->setString("A.  17,byte");
            B_text->setString("B.  25,byte");
            C_text->setString("C.  17,int");
            D_text->setString("D.  25,int");
            key=_C;
        }
    }
    else if (_Boss==3) {
        //GOOD
        if (questionN==1) {
            question->setString("How will you free the allocated memory ?");
            A_text->setString("A.  remove(var-name)");
            B_text->setString("B.  free(var-name)");
            C_text->setString("C.  delete(var-name)");
            D_text->setString("D.  dalloc(var-name);");
            A_text->setScale(0.7f);
            B_text->setScale(0.7f);
            C_text->setScale(0.7f);
            D_text->setScale(0.7f);
            key=_B;
        }
        //GOOD
        else if (questionN==2){
            question->setString("Which of the following statements should be used to obtain a remainder after dividing 3.14 by 2.1 ?");
            A_text->setString("A.  rem = 3.14 % 2.1;");
            B_text->setString("B.  rem = modf(3.14, 2.1);");
            C_text->setString("C.  rem = fmod(3.14, 2.1);");
            D_text->setString("D.  Remainder cannot be obtain in floating point division.");
            A_text->setScale(0.7f);
            B_text->setScale(0.7f);
            C_text->setScale(0.7f);
            D_text->setScale(0.5f);
            key=_C;
        }
        else if (questionN==3){
            //GOOD
            question->setString("A pointer is");
            A_text->setString("A. keyword used to create variables");
            B_text->setString("B. A variable that stores address of an instruction");
            C_text->setString("C. A variable that stores address of an instruction");
            D_text->setString("D. All of the above");
            
            A_text->setScale(0.7f);
            B_text->setScale(0.5f);
            C_text->setScale(0.5f);
            D_text->setScale(0.7f);
            key=_C;
        }
        //GOOD
        else if (questionN==4){
            question->setString("Which of the following cannot be checked in a switch-case statement?");
            A_text->setString("A.  Character");
            B_text->setString("B.  Integer");
            C_text->setString("C.  Float");
            D_text->setString("D.  enum");
            key=_C;
        }
        //Good
        else if (questionN==5){
            question->setString("The library function used to reverse a string is: ");
            A_text->setString("A.  strstr()");
            B_text->setString("B.  strrev()");
            C_text->setString("C.  revstr()");
            D_text->setString("D.  strreverse()");
            key=_B;
        }
        else if (questionN==6){
            //GOOD
            question->setString("Which of the following is TRUE about argv?");
            A_text->setString("A.  It is an array of character pointers");
            B_text->setString("B.  It is a pointer to an array of character pointers");
            C_text->setString("C.  It is an array of strings");
            D_text->setString("D.  None of above");
            A_text->setScale(0.7f);
            B_text->setScale(0.5f);
            C_text->setScale(0.7f);
            D_text->setScale(0.7f);
            key=_A;
        }
        else if (questionN==7){
            //Good
            question->setString("What do the following declaration signify? int *f();");
            A_text->setString("A.  f is a pointer variable of function type.");
            B_text->setString("B.  f is a function returning pointer to an int.");
            C_text->setString("C.  f is a function pointer.");
            D_text->setString("D.  f is a simple declaration of pointer variable.");
            A_text->setScale(0.5f);
            B_text->setScale(0.5f);
            C_text->setScale(0.5f);
            D_text->setScale(0.5f);
            key=_B;
        }
    }
    
    A->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                if (key==_A) {
                    _bossHP--;
                    //bossBurnSprite->runAction(bossAnimate);
                    BossHP->setString("BOSS HP: "+std::to_string(_bossHP));
                    questionSet.erase(questionSet.begin()+questionIndex);
                    correct=250;
                }
                else{
                    wrong=250;
                }
                node->removeAllChildren();
                this->removeChild(node);
                stopFrame=false;
                //node->release();
                break;
            }
            default:
                break;
        }
    });
    B->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                if (key==_B) {
                    _bossHP--;
                    //bossBurnSprite->runAction(bossAnimate);
                    BossHP->setString("BOSS HP: "+std::to_string(_bossHP));
                    questionSet.erase(questionSet.begin()+questionIndex);
                    correct=250;
                }
                else{
                    wrong=250;
                }
                node->removeAllChildren();
                this->removeChild(node);
                stopFrame=false;
                //node->release();
                break;
            }
            default:
                break;
        }
    });
    C->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                if (key==_C) {
                    _bossHP--;
                    //bossBurnSprite->runAction(bossAnimate);
                    BossHP->setString("BOSS HP: "+std::to_string(_bossHP));
                    questionSet.erase(questionSet.begin()+questionIndex);
                    correct=250;
                }
                else{
                    wrong=250;
                }
                node->removeAllChildren();
                this->removeChild(node);
                stopFrame=false;
                //node->release();
                break;
            }
            default:
                break;
        }
    });
    D->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:{
                if (key==_D) {
                    _bossHP--;
                    BossHP->setString("BOSS HP: "+std::to_string(_bossHP));
                    questionSet.erase(questionSet.begin()+questionIndex);
                    correct=250;
                }
                else{
                    wrong=250;
                }
                node->removeAllChildren();
                this->removeChild(node);
                stopFrame=false;
                //node->release();
                break;
            }
            default:
                break;
        }
    });

    
    /*
    this->addChild(A,4);
    this->addChild(B,4);
    this->addChild(C,4);
    this->addChild(D,4);
    this->addChild(A_text,5);
    this->addChild(B_text,5);
    this->addChild(C_text,5);
    this->addChild(D_text,5);
    this->addChild(bg,3);
     */
    node->addChild(A,4);
    node->addChild(B,4);
    node->addChild(C,4);
    node->addChild(D,4);
    node->addChild(A_text,5);
    node->addChild(B_text,5);
    node->addChild(C_text,5);
    node->addChild(D_text,5);
    node->addChild(bg,3);
    this->addChild(node,4);
}

void Arena::initMap() {
    Point position;
    disable=5;
    map = TMXTiledMap::create("arena/arena1.tmx");
    tileWidth=map->getTileSize().width;
    tileHeight=map->getTileSize().height;
    position=Vec2(origin.x+0.9*visibleSize.width,origin.y+0.5*visibleSize.height);
    position=adjustPosition(position);
    player->setAnchorPoint(Vec2(0,0));
    player->setPosition(position);
}
// on "init" you need to initialize your instance
void Arena::startIceball(){
    int count;
    //Vector<int> slot;
    std::vector<int> slot;
    slot.push_back(1);
    slot.push_back(2);
    slot.push_back(3);
    slot.push_back(4);
    Point position;
    if (_Boss==1) {
        count=_boss1Amount;
    }
    else if(_Boss==2) {
        count=_boss2Amount;
    }
    else if(_Boss==3) {
        count=_boss3Amount;
    }
    for (int i=0; i<count; i++) {
        auto temp=Sprite::create("arena/iceball"+std::to_string(_Boss)+".png");
        iceballs.pushBack(temp);
        int index=rand() % slot.size();
        int mySlot = slot[index];
        slot.erase(slot.begin()+index);
        if (mySlot==1) {
            position=Vec2(origin.x+visibleSize.width*0.2,origin.y+visibleSize.height*0.7);
        }
        else if (mySlot==2) {
            position=Vec2(origin.x+visibleSize.width*0.2,origin.y+visibleSize.height*0.6);
        }
        else if (mySlot==3) {
            position=Vec2(origin.x+visibleSize.width*0.2,origin.y+visibleSize.height*0.4);
        }
        else if (mySlot==4) {
            position=Vec2(origin.x+visibleSize.width*0.2,origin.y+visibleSize.height*0.3);
        }
        position=adjustPosition(position);
        temp->setAnchorPoint(Vec2(0,0));
        temp->setPosition(position);
        bossNode->addChild(temp,3);
        //this->addChild(temp,3);
    }
    if (_Boss==1) ballMove=_iceBallSpeed1;
    else if (_Boss==2) ballMove=_iceBallSpeed2;
    else if (_Boss==3) ballMove=_iceBallSpeed3;
}

void Arena::showStar(){
    star = Sprite::create("arena/star.png");
    int x = rand() % 8 + 4;
    int y = rand() % 4 + 2;
    star->setAnchorPoint(Vec2(0,0));
    star->setPosition(Vec2(origin.x+tileWidth*x,origin.y+tileHeight*y));
    this->addChild(star,2);
    _star=-1;
}

void Arena::startBoss(int boss_num){
    bossNode=Node::create();
    auto boss=Sprite::create("arena/boss"+std::to_string(boss_num)+".png");
    boss->setPosition(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height/2));
    bossNode->addChild(boss,2);
    this->addChild(bossNode,2);
    //this->addChild(boss,2);
    
    //_Boss=boss_num;
    fire=60;
    _star=_starPeriod;
    if (boss_num==1) {
         _meHP=5;
        iceBallFreq=_boss1Freq;
        _bossHP=_boss1HP;
    }
    else if (boss_num==2){
        iceBallFreq=_boss2Freq;
        _bossHP=_boss2HP;
    }
    else if (boss_num==3){
        iceBallFreq=_boss3Freq;
        _bossHP=_boss3HP;
    }
    questionSet.clear();
    questionSet.push_back(1);
    questionSet.push_back(2);
    questionSet.push_back(3);
    questionSet.push_back(4);
    questionSet.push_back(5);
    questionSet.push_back(6);
    questionSet.push_back(7);
    meHP = Label::createWithTTF("HP: "+std::to_string(_meHP), "fonts/After_Shok.ttf", 30);
    meHP->setColor(Color3B(0,0,0));
    BossHP = Label::createWithTTF("BOSS HP: "+std::to_string(_bossHP), "fonts/After_Shok.ttf", 30);
    BossHP->setColor(Color3B(0,0,0));
    meHP->setAnchorPoint(Vec2(0,0));
    BossHP->setAnchorPoint(Vec2(0,0));
    meHP->setPosition(Vec2(origin.x+visibleSize.width*0.85,origin.y+visibleSize.height*0.9));
    BossHP->setPosition(Vec2(origin.x+visibleSize.width*0.1,origin.y+visibleSize.height*0.9));
    //this->addChild(meHP,2);
    //this->addChild(BossHP,2);
    bossNode->addChild(meHP,2);
    bossNode->addChild(BossHP,2);
}

void Arena::greeting() {
    stopFrame=true;
    chatNode=Node::create();
    upArrow->setVisible(false);
    rightArrow->setVisible(false);
    downArrow->setVisible(false);
    leftArrow->setVisible(false);
    chat=Label::createWithTTF(chatss[0], "fonts/Cantarell-Bold.ttf", 40);
    chat->setWidth(0.6*visibleSize.width);
    chat->setAnchorPoint(Vec2(0,1));
    chat->setPosition(Vec2(origin.x+visibleSize.width*0.15,origin.y+visibleSize.height*0.27));
    //this->addChild(chat,4);
    chatNode->addChild(chat,4);

    
    
    currentChat=0;
    listenerChat = EventListenerTouchOneByOne::create();
    lion=Sprite::create("lion.png");
    me=Sprite::create("game/"+std::to_string(UserDefault::getInstance()->getIntegerForKey("Gender"))+".png");
    boss1=Sprite::create("arena/boss1chat.png");
    boss2=Sprite::create("arena/boss2chat.png");
    boss3=Sprite::create("arena/boss3chat.png");
    chatbg=Sprite::create("chatbg1.png");
    lion->setPosition(Vec2(origin.x+visibleSize.width/4,origin.y+visibleSize.height/2));
    boss1->setPosition(Vec2(origin.x+visibleSize.width/4,origin.y+visibleSize.height/2));
    boss2->setPosition(Vec2(origin.x+visibleSize.width/4,origin.y+visibleSize.height/2));
    boss3->setPosition(Vec2(origin.x+visibleSize.width/4,origin.y+visibleSize.height/2));
    me->setPosition(Vec2(origin.x+visibleSize.width*0.7,visibleSize.height/2+origin.y));
    chatbg->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+chatbg->getContentSize().height/2));
    /*
    this->addChild(lion,2);
    this->addChild(me,2);
    this->addChild(chatbg,3);
    this->addChild(boss1,2);
    this->addChild(boss2,2);
    this->addChild(boss3,2);
     */
    chatNode->addChild(lion,2);
    chatNode->addChild(me,2);
    chatNode->addChild(chatbg,3);
    chatNode->addChild(boss1,2);
    chatNode->addChild(boss2,2);
    chatNode->addChild(boss3,2);
    this->addChild(chatNode,4);
    
    me->setVisible(false);
    boss1->setVisible(false);
    boss2->setVisible(false);
    boss3->setVisible(false);
    lion->setVisible(false);
    if (talkOrder[0]==_LION) {
        NameL = Label::createWithTTF("Nittany Lion :","fonts/Cantarell-Bold.ttf", 30);
        lion->setVisible(true);
    }
    else if (talkOrder[0]==_ME) {
        NameL = Label::createWithTTF(UserDefault::getInstance()->getStringForKey("Name")+" :","fonts/Cantarell-Bold.ttf", 30);
        me->setVisible(true);
    }
    else if (talkOrder[0]==_Boss1) {
        NameL = Label::createWithTTF("C++ :","fonts/Cantarell-Bold.ttf", 30);
        boss1->setVisible(true);
    }
    else if (talkOrder[0]==_Boss2) {
        NameL = Label::createWithTTF("Java :","fonts/Cantarell-Bold.ttf", 30);
        boss2->setVisible(true);
    }
    else if (talkOrder[0]==_Boss3) {
        NameL = Label::createWithTTF("C :","fonts/Cantarell-Bold.ttf", 30);
        boss3->setVisible(true);
    }
    NameL->setAnchorPoint(Vec2(0,0));
    NameL->setPosition(Vec2(origin.x+visibleSize.width*0.15,origin.y+visibleSize.height*0.3));
    //this->addChild(NameL,4);
    chatNode->addChild(NameL,4);
    listenerChat->onTouchBegan = [=](Touch* touch, Event* event){
        return true;
    };
    listenerChat->onTouchEnded = [&](Touch* touch, Event* event){
        if (currentChat<chatss.size()-1) {
            currentChat=currentChat+1;
            if (talkOrder[currentChat]==_LION) {
                //me->setVisible(false);
                boss1->setVisible(false);
                boss2->setVisible(false);
                boss3->setVisible(false);
                lion->setVisible(true);
                NameL->setString("Nittany Lion :");
            }
            else if (talkOrder[currentChat]==_ME) {
                me->setVisible(true);
                NameL->setString(UserDefault::getInstance()->getStringForKey("Name")+" :");
            }
            else if (talkOrder[currentChat]==_Boss1) {
                //me->setVisible(false);
                boss1->setVisible(true);
                boss2->setVisible(false);
                boss3->setVisible(false);
                lion->setVisible(false);
                NameL->setString("C++ :");
            }
            else if (talkOrder[currentChat]==_Boss2) {
                boss1->setVisible(false);
                boss2->setVisible(true);
                boss3->setVisible(false);
                lion->setVisible(false);
                NameL->setString("Java :");
            }
            else if (talkOrder[currentChat]==_Boss3) {
                boss1->setVisible(false);
                boss2->setVisible(false);
                boss3->setVisible(true);
                lion->setVisible(false);
                NameL->setString("C :");
            }
            chat->setString(chatss[currentChat]);
        }
        else if(currentChat==chatss.size()-1){
            chatNode->removeAllChildren();
            upArrow->setVisible(true);
            rightArrow->setVisible(true);
            downArrow->setVisible(true);
            leftArrow->setVisible(true);
            section=_MOVE;
            stopFrame=false;
            this->getEventDispatcher()->removeEventListener(listenerChat);
            if (_Boss>=1 && _Boss<=3) {
                startBoss(_Boss);
            }
            else if(_Boss==4){
                
                stopFrame=true;
                UserDefault::getInstance()->setIntegerForKey("Scene",_IST);
                UserDefault::getInstance()->setIntegerForKey("Entry",_BIRTH);
                auto gameScene=Game::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, gameScene, Color3B(0,0,0)));
            }

        }
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerChat, this);
}

void Arena::congra(){
    talkOrder.clear();
    talkOrder.push_back(_Boss3);
    talkOrder.push_back(_Boss3);
    talkOrder.push_back(_Boss3);
    chatss.clear();
    chatss.push_back("Good job!");
    chatss.push_back("I have to confess that you do have some gifts of learning programming language. ");
    chatss.push_back("And that's it, wish you good luck for the following exploration on campus!");
    _Boss=4;
    greeting();
}

void Arena::nextBoss(){
    if (_Boss==1) {
        talkOrder.clear();
        talkOrder.push_back(_LION);
        talkOrder.push_back(_LION);
        talkOrder.push_back(_Boss2);
        chatss.clear();
        chatss.push_back("Hnn, Not Bad!");
        chatss.push_back("I see you beat the C++ elf, but there are more challenges coming up. Good luck.");
        chatss.push_back("Hey you! Take that!");
        bossNode->removeAllChildren();
    }
    else if(_Boss==2){
        talkOrder.clear();
        talkOrder.push_back(_Boss3);
        talkOrder.push_back(_Boss3);
        talkOrder.push_back(_Boss3);
        chatss.clear();
        chatss.push_back("I have been waiting here since long long ago.");
        chatss.push_back("And you are the first one that have awakened me up. ");
        chatss.push_back("Let’s do some brainstorming!");
        bossNode->removeAllChildren();
    }
    _Boss++;
    greeting();
}

bool Arena::init() {
    //////////////////////////////
    // 1. super init first
    srand (time(NULL));
    if ( !Layer::init() )
    {
        return false;
    }
    scene=UserDefault::getInstance()->getIntegerForKey("Scene");
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    stopFrame=true;
    dir=-1;
    wrong=-1;
    pause=-1;
    correct=-1;
    ballMove=1000;
    _star=1000;
    
    Wrong=Sprite::create("arena/wrong.png");
    Correct=Sprite::create("arena/correct.png");
    Wrong->setOpacity(0);
    Correct->setOpacity(0);
    Wrong->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
    Correct->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
    this->addChild(Wrong,5);
    this->addChild(Correct,5);
    if (UserDefault::getInstance()->getIntegerForKey("Gender")==1) {
        this->player =Sprite::create("game/boy.png");
    }
    else if(UserDefault::getInstance()->getIntegerForKey("Gender")==2) {
        this->player =Sprite::create("game/girl.png");
        
    }
    initMap();
    
    burnSprite0=Sprite::create("arena/void.png");
    burnSprite1=Sprite::create("arena/void.png");
    burnSprite2=Sprite::create("arena/void.png");
    
    burnSprite0->setAnchorPoint(Vec2(0,0));
    burnSprite1->setAnchorPoint(Vec2(0,0));
    burnSprite2->setAnchorPoint(Vec2(0,0));
    burnSprites.pushBack(burnSprite0);
    burnSprites.pushBack(burnSprite1);
    burnSprites.pushBack(burnSprite2);
    currentBurn=0;
    this->addChild(burnSprites.at(0),5);
    this->addChild(burnSprites.at(1),5);
    this->addChild(burnSprites.at(2),5);

    
    burn.reserve(5);
    burn.pushBack(SpriteFrame::create("arena/burn1.png", Rect(0,0,tileWidth,tileHeight)));
    burn.pushBack(SpriteFrame::create("arena/burn2.png", Rect(0,0,tileWidth,tileHeight)));
    burn.pushBack(SpriteFrame::create("arena/burn3.png", Rect(0,0,tileWidth,tileHeight)));
    burn.pushBack(SpriteFrame::create("arena/burn4.png", Rect(0,0,tileWidth,tileHeight)));
    burn.pushBack(SpriteFrame::create("arena/void.png", Rect(0,0,tileWidth,tileHeight)));
    animation1 = Animation::createWithSpriteFrames(burn, 0.1f);
    animate1 = Animate::create(animation1);
    animate1->retain();
    /*animation2 = Animation::createWithSpriteFrames(burn, 0.1f);
    animate2 = Animate::create(animation3);
    animate2->retain();
    animation3 = Animation::createWithSpriteFrames(burn, 0.1f);
    animate3 = Animate::create(animation3);
    animate3->retain();*/
    
    Animate.pushBack(animate1);
    Animate.pushBack(animate1->clone());
    Animate.pushBack(animate1->clone());
    
    bossBurnSprite=Sprite::create("arena/bossHit/void.png");
    bossBurnSprite->setAnchorPoint(Vec2(0,0));
    bossBurnSprite->setPosition(Vec2(origin.x-tileWidth,origin.y+2*tileHeight));
    this->addChild(bossBurnSprite,6);
    std::cout<<tileWidth<<std::endl;
    bossBurn.reserve(5);
    bossBurn.pushBack(SpriteFrame::create("arena/bossHit/burn1.png", Rect(0,0,4*tileWidth,4*tileHeight)));
    bossBurn.pushBack(SpriteFrame::create("arena/bossHit/burn2.png", Rect(0,0,4*tileWidth,4*tileHeight)));
    bossBurn.pushBack(SpriteFrame::create("arena/bossHit/burn3.png", Rect(0,0,4*tileWidth,4*tileHeight)));
    bossBurn.pushBack(SpriteFrame::create("arena/bossHit/burn4.png", Rect(0,0,4*tileWidth,4*tileHeight)));
    bossBurn.pushBack(SpriteFrame::create("arena/bossHit/void.png", Rect(0,0,4*tileWidth,4*tileHeight)));
    bossAnimation = Animation::createWithSpriteFrames(bossBurn, 0.1f);
    bossAnimate = Animate::create(bossAnimation);
    bossAnimate->retain();

    
    this->addChild(map,0,99);
    
    building = map->getLayer("building");
    building->setVisible(false);
    this->addChild(player,1);
    
    
        //greeting();
    upArrow =Sprite::create("game/up.png");
    rightArrow =Sprite::create("game/right.png");
    downArrow =Sprite::create("game/down.png");
    leftArrow =Sprite::create("game/left.png");
    
    talkOrder.push_back(_Boss1);
    talkOrder.push_back(_LION);
    talkOrder.push_back(_LION);
    talkOrder.push_back(_LION);
    talkOrder.push_back(_ME);
    chatss.push_back("Hey! How dare you break into IST building! ");
    chatss.push_back("This is an elf in IST building, and his name is C++.");
    chatss.push_back("In order to beat him, you will need to get the star of wisdom, and answer the questions hidden inside.");
    chatss.push_back("The star of wisdom will show up in the arena randomly. Watch out!");
    chatss.push_back("Understand! Let’s do it!");
    _Boss=1;
    greeting();
    
    //else if (section==_MOVE) {
    
    
    auto listener0 = EventListenerTouchOneByOne::create();
    auto listener1 = EventListenerTouchOneByOne::create();
    auto listener2 = EventListenerTouchOneByOne::create();
    auto listener3 = EventListenerTouchOneByOne::create();
    
    listener0->onTouchBegan = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            
            dir=0;
            return true;
        }
        return true; // if you are consuming it
    };
    listener0->onTouchEnded = [=](Touch* touch, Event* event){
        dir=-1;
    };
    listener1->onTouchBegan = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            dir=1;
            return true;
        }
        return true; // if you are consuming it
    };
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        dir=-1;
    };
    listener2->onTouchBegan = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            dir=2;
            return true;
        }
        return true; // if you are consuming it
    };
    listener2->onTouchEnded = [=](Touch* touch, Event* event){
        dir=-1;
    };
    listener3->onTouchBegan = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            dir=3;
            return true;
        }
        return true; // if you are consuming it
    };
    listener3->onTouchEnded = [=](Touch* touch, Event* event){
        dir=-1;
    };

    
    //set Arrow position
    {
        upArrow->setPosition(Vec2(visibleSize.width*0.15+origin.x,visibleSize.height*0.3+origin.y));
        this->addChild(upArrow,3);
        
        rightArrow->setPosition(Vec2(0.2*visibleSize.width+origin.x,visibleSize.height*0.2+origin.y));
        this->addChild(rightArrow,3);
        
        downArrow->setPosition(Vec2(visibleSize.width*0.15+origin.x,visibleSize.height*0.1+origin.y));
        this->addChild(downArrow,3);
        
        leftArrow->setPosition(Vec2(0.1*visibleSize.width+origin.x,visibleSize.height*0.2+origin.y));
        this->addChild(leftArrow,3);
        //#####################################
    }
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener0, upArrow);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, rightArrow);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, downArrow);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener3, leftArrow);
    this-> scheduleUpdate();
    //}//set Arrow
    return true;
}

void Arena::update(float dt) {
    if (stopFrame==false) {
        if (wrong<=250 && wrong>0) {
            Wrong->setOpacity(wrong);
            wrong-=25;
        }
        else if(wrong==0){
            Wrong->setOpacity(wrong);
            wrong=-1;
        }
        if (correct==250) {
            bossBurnSprite->runAction(bossAnimate);
            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
            audio->playEffect("audio/Harm.wav", false, 1.0f, 1.0f, 1.0f);
        }
        if (correct<=250 && correct>0) {
            Correct->setOpacity(correct);
            correct-=25;
        }
        else if(correct==0){
            Correct->setOpacity(correct);
            correct=-1;
        }

        if (pause>0) {
            pause--;
        }
        else if(pause<=0){
        bool stop =false;
        Point position;
        if(dir==0) {
            position=Vec2(player->getPosition().x,player->getPosition().y+tileHeight/*+player->getContentSize().height/2*/);
        }
        else if(dir==1) {
            position=Vec2(player->getPosition().x+tileWidth/*+player->getContentSize().width/2*/,player->getPosition().y/*-player->getContentSize().height/2*/);
        }
        else if(dir==2) {
            position=Vec2(player->getPosition().x,player->getPosition().y-tileHeight);
        }
        else if(dir==3) {
            position=Vec2(player->getPosition().x-tileWidth/*-player->getContentSize().width/2*/,player->getPosition().y/*-player->getContentSize().height/2*/);
        }
        if (dir>=0 && position.x >0 && position.y>0 && position.x<visibleSize.width&&position.y<visibleSize.height) {
            Point tileCoord = this->tileCoordForPosition(position);
            //std::cout<<tileCoord.x<<"     "<<tileCoord.y<<std::endl;
            int tileGid = building->getTileGIDAt(tileCoord);
            //std::cout<<tileGid<<std::endl;
            if (tileGid) {
                Value test=map->getPropertiesForGID(tileGid);
                ValueMap properties = test.asValueMap();
                if (!properties.empty()) {
                    auto collision = properties["collision"].asString();
                    if (collision=="false") {
                        stop = true;
                    }
                }
            }
        }
        if(dir==0 && stop==false)
        {
            player->setPosition(Vec2(player->getPosition().x,player->getPosition().y+tileHeight));
        }
        else if (dir==1 && player->getPosition().x+tileWidth<visibleSize.width-player->getContentSize().width/2&& stop==false)
        {
            player->setPosition(Vec2(player->getPosition().x+tileWidth,player->getPosition().y));
        }
        else if (dir==2 && stop==false)
        {
            player->setPosition(Vec2(player->getPosition().x,player->getPosition().y-tileHeight));
        }
        else if (dir==3 && player->getPosition().x-tileWidth>0+player->getContentSize().width/2&& stop==false)
        {
            player->setPosition(Vec2(player->getPosition().x-tileWidth,player->getPosition().y));
        }
        
        dir=-1;
        if (fire==0) {
            fire=iceBallFreq;
            startIceball();
        }
        else{
            fire--;
        }
        if (ballMove==0) {
            Point iceBallPos;
            int count=0;
            for (int i=0; i<iceballs.size(); i++) {
                iceBallPos=iceballs.at(i)->getPosition();
                if (iceBallPos.x+tileWidth>visibleSize.width) {
                    count++;
                }
                else{
                    break;
                }
            }
            for (int i=0; i<count; i++) {
                iceballs.at(0)->setVisible(false);
                //this->removeChild(iceballs.at(0));
                bossNode->removeChild(iceballs.at(0));
                iceballs.erase(iceballs.begin());
            }
            for (int i=0; i<iceballs.size(); i++) {
                iceBallPos=iceballs.at(i)->getPosition();
                iceBallPos.x+=tileWidth;
                iceballs.at(i)->setPosition(iceBallPos);
            }
            if (_Boss==1) ballMove=_iceBallSpeed1;
            else if (_Boss==2) ballMove=_iceBallSpeed2;
            else if (_Boss==3) ballMove=_iceBallSpeed3;
        }
        else{
            ballMove--;
        }
        Point playerPos=player->getPosition();
        for (int i=0; i<iceballs.size(); i++) {
            if (playerPos.x==iceballs.at(i)->getPosition().x && playerPos.y==iceballs.at(i)->getPosition().y) {
                burnSprites.at(currentBurn)->setPosition(Vec2(playerPos.x,playerPos.y));
                burnSprites.at(currentBurn)->runAction(Animate.at(currentBurn));
                auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
                if (_Boss==1) {
                    audio->playEffect("audio/1.wav", false, 1.0f, 1.0f, 1.0f);
                }
                else if (_Boss==2) {
                    audio->playEffect("audio/2.wav", false, 1.0f, 1.0f, 1.0f);
                }
                else if (_Boss==3) {
                    audio->playEffect("audio/3.wav", false, 1.0f, 1.0f, 1.0f);
                }
                if (currentBurn<2) {
                    currentBurn++;
                }
                else{
                    currentBurn=0;
                }
                _meHP=_meHP-1;
                iceballs.at(i)->setVisible(false);
                //this->removeChild(iceballs.at(i));
                bossNode->removeChild(iceballs.at(i));
                iceballs.erase(iceballs.begin()+i);
                meHP->setString("HP: "+std::to_string(_meHP));
                break;
            }
        }
        if (_star==0) {
            showStar();
        }
        else if(_star>0) _star--;
        if (_meHP==0) {
            Wrong->setOpacity(0);
            UserDefault::getInstance()->setIntegerForKey("Scene",_IST);
            UserDefault::getInstance()->setIntegerForKey("Entry",_BIRTH);
            auto gameScene=Game::createScene();
            stopFrame=true;

            Director::getInstance()->replaceScene(TransitionFade::create(0.5, gameScene, Color3B(0,0,0)));
        }
        if (_star==-1) {
            if (star->getPosition().x +1 == playerPos.x && star->getPosition().y+1 == playerPos.y) {
                stopFrame=true;
                this->removeChild(star);
                _star=_starPeriod;
                startQuestion();
            }
        }
        if (_bossHP==0) {
            Correct->setOpacity(0);
            iceballs.clear();
            if (pause==-1) pause=20;
            if (pause==0) {
                pause=-1;
                if (_Boss==3) {
                    congra();
                }
                else if (_Boss==1) {
                    nextBoss();
                }
                else if (_Boss==2) {
                    nextBoss();
                }

            }
        }
        }
    }
    }

void Arena::menuCloseCallback(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
