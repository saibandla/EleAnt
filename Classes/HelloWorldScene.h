#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "sqlite3.h"
class HelloWorld : public cocos2d::CCLayer
{
public:
	sqlite3 *m_db;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    void partic();
    void level2();
    void initia();
    void cht();
    void backtime();
    void background1();
    void foreground();
    void creditss();
    void helpp();
    void playpause();
    void audio();
    void updatemeters(float dt);
    void level2start(float dt);
    void snowcreation();
    void level3();
    void getscore();
    void scoreall();
    void clo();
    void level3start(float dt);
    void eleleg2(float dt);
    void eleleg3(float dt);
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void eleleg1(float dt);
    void elelegremove(float dt);
    void initiate();
    void enteranme();
    void mainscene();
    void removeele(float dt);
    void ccTouchesBegan(cocos2d::CCSet *touches,cocos2d::CCEvent *event);
    void antcheck(float dt);
    void offtouch();
    void ontouch();
void shake();
void collisions(float dt);
void Gameover();

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
