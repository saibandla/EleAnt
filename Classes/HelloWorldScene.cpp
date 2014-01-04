#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace std;
using namespace CocosDenshion;
CCSize size;
CCSprite *eleleg;
CCSprite *character;
CCSprite *sprite;
int iflag=0;
CCParticleSystem* m_emitter;
CCParticleSystem* m_emitter1;
CCSprite *background;
CCLabelTTF *meters;
CCTextFieldTTF *ga;
string name123;
int newentry=1;
int m4=0,j=0,rc;
std::vector<int> scores;
char str[100];
static const char s_stars1[]= "Images/stars.png";
static const char s_snow[]= "Images/snow.png";
CCMenuItemImage *paly,*pCloseItem;
string nale;
int timeer;
int audioicon=0;
string path1;
CCLabelTTF *timer;
CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}
float x;
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    

    	 	size = CCDirector::sharedDirector()->getWinSize();
    	 	if(size.width>1024)
    	 	    	 {
    	 	    		 fprintf(stderr,"size: %f",size.height);

    	 	    		 path1="z10/";
    	 	    	 }
    	 	    	 else
    	 	    	 {

    	 	    		 path1="q10/";
    	 	    	 }

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
    		(path1+"CloseNormal.png").c_str(),
    		(path1+"CloseSelected.png").c_str(),
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    

    pCloseItem->setPosition(ccp(size.width - 20, 20));
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    rc = sqlite3_open_v2("data/database.db", &m_db, SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE, NULL);
          fprintf(stderr,"\ncreating database 1");
          if (rc != SQLITE_OK) {
       	   fprintf(stderr,"\nentering 27");
              fprintf(stderr, "Could not open scores db. %d\n", rc);
              fprintf(stderr,"\nentering 28");

              //fprintf(stderr,"\nentering 29");
          }
          if(rc==SQLITE_OK)
          {
       	   fprintf(stderr, "created databse %d", rc);
       	   fprintf(stderr,"entering into database");
          }

	    static const char* createSql ="create table if not exists store(name text,score integer)";
	    	     sqlite3_stmt* createStmt;
	    	     int rc15 = sqlite3_prepare_v2(m_db, createSql, strlen(createSql), &createStmt, NULL);
	    	     if (rc15 == SQLITE_OK) {
	    	     fprintf(stderr, "\n Sqlite table created successfully %d\n", rc);

	    	     }

	    	   sqlite3_step(createStmt);
	    	   if( sqlite3_step(createStmt)==SQLITE_DONE)
	    	   {
	    		  fprintf(stderr,"\nit is not possible 1");
	    	    sqlite3_finalize(createStmt);
	    	   }
	    	  sqlite3_finalize(createStmt);
	    	  int sq=sqlite3_step(createStmt);
	    	  if(sq==SQLITE_DONE)
	    	  {
	    		  fprintf(stderr,"\nupdate statement:%d",sq);
	    	  }
    HelloWorld::mainscene();
    return true;
}
void HelloWorld::mainscene()
{
	if(this->getChildByTag(5897))
	{
		ga->detachWithIME();
	}
	this->removeAllChildren();
	this->unscheduleAllSelectors();

	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.wav",true);
	CCSprite *bk=CCSprite::create((path1+"background.png").c_str());
	bk->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(bk,1);
	CCMenuItemImage *ply=CCMenuItemImage::create((path1+"pl.png").c_str(),(path1+"pl.png").c_str(),this,menu_selector(HelloWorld::enteranme));
	ply->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(ply,2);
	CCMenuItemImage *cls=CCMenuItemImage::create((path1+"exit.png").c_str(),(path1+"exit.png").c_str(),this,menu_selector(HelloWorld::menuCloseCallback));
	cls->setPosition(ccp(120,50));
	this->addChild(cls,2);
	CCMenuItemImage *cre=CCMenuItemImage::create((path1+"credits.png").c_str(),(path1+"credits.png").c_str(),this,menu_selector(HelloWorld::creditss));
	cre->setPosition(ccp(size.width-140,size.height-40));
	this->addChild(cre,2);
	CCMenuItemImage *help=CCMenuItemImage::create((path1+"help.png").c_str(),(path1+"help.png").c_str(),this,menu_selector(HelloWorld::helpp));
	help->setPosition(ccp(size.width-160,size.height-160));
	this->addChild(help,2);
	CCMenu *pmenu=CCMenu::create(ply,cls,cre,help,NULL);
	pmenu->setPosition(CCPointZero);
	this->addChild(pmenu,2);
	this->setTouchEnabled(false);

}
void HelloWorld::cht()
{
	if(ga->getString()!=NULL)
	{
	string str=(string)(ga->getString());
	if(str.length()==10)
	{
		nale=(string)(ga->getString());
	}
	if(str.length()>10)
	{

		//str.push_back('\b');
		ga->setString(nale.c_str());

	}
	else
	{
		//ga->attachWithIME();
	}

	}
}
void HelloWorld::playpause()
{
	if(size.width>1000)
	{
	 paly=CCMenuItemImage::create(("z10/2.png"),("z10/2.png"),this,menu_selector(HelloWorld::background1));
		   paly->setPosition(ccp(size.width-65,65));
if(audioicon==0)
{
		   pCloseItem = CCMenuItemImage::create(
				   ("z10/sound-off@2x.png"),
				   ("z10/sound-off@2x.png"),
		   	   			                                        this,
		   	   			                                        menu_selector(HelloWorld::audio));
		   pCloseItem->setPosition(ccp(size.width - 40, size.height-40));


}
else if(audioicon==1)
{
		   pCloseItem = CCMenuItemImage::create(
				   ("z10/sound-on@2x.png"),
				   ("z10sound-on@2x.png"),
		   	   			                                        this,
		   	   			                                        menu_selector(HelloWorld::audio));
		   pCloseItem->setPosition(ccp(size.width - 40, size.height-40));


}
		   CCMenu *plymenu=CCMenu::create(paly,pCloseItem,NULL);
		   plymenu->setPosition(CCPointZero);
		   plymenu->setTag(668);
		   this->addChild(plymenu,200);
	}
	else
	{
		 paly=CCMenuItemImage::create("q10/2.png","q10/2.png",this,menu_selector(HelloWorld::background1));
				   paly->setPosition(ccp(size.width-65,65));
		if(audioicon==0)
		{
				   pCloseItem = CCMenuItemImage::create(
				   	   			                                        "q10/sound-off@2x.png",
				   	   			                                        "q10/sound-off@2x.png",
				   	   			                                        this,
				   	   			                                        menu_selector(HelloWorld::audio));
				   pCloseItem->setPosition(ccp(size.width - 40, size.height-40));


		}
		else if(audioicon==1)
		{
				   pCloseItem = CCMenuItemImage::create(
				   	   			                                        "q10/sound-on@2x.png",
				   	   			                                        "q10/sound-on@2x.png",
				   	   			                                        this,
				   	   			                                        menu_selector(HelloWorld::audio));
				   pCloseItem->setPosition(ccp(size.width - 40, size.height-40));


		}
				   CCMenu *plymenu=CCMenu::create(paly,pCloseItem,NULL);
				   plymenu->setPosition(CCPointZero);
				   plymenu->setTag(668);
				   this->addChild(plymenu,200);

	}

}
void HelloWorld::audio()
{

	if(size.width>1000)
	{
		CCSprite *off,*on;
	off=CCSprite::create("z10/sound-on@2x.png");
	on=CCSprite::create("z10/sound-on@2x.png");
	if(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume()>0.0)
		{
			if(audioicon==0)
			{
			pCloseItem->setNormalImage(on);
			pCloseItem->setSelectedImage(on);
			SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.0);
			audioicon=1;
			}
		}
		else
		{
			if(audioicon==1)
			{
			pCloseItem->setNormalImage(off);
			pCloseItem->setSelectedImage(off);
			SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.7);
			audioicon=0;
			}

		}
	}
	else
	{
		CCSprite *off=CCSprite::create("q10/sound-on@2x.png");
			CCSprite *on=CCSprite::create("q10/sound-on@2x.png");
			if(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume()>0.0)
				{
					if(audioicon==0)
					{
					pCloseItem->setNormalImage(on);
					pCloseItem->setSelectedImage(on);
					SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.0);
					audioicon=1;
					}
				}
				else
				{
					if(audioicon==1)
					{
					pCloseItem->setNormalImage(off);
					pCloseItem->setSelectedImage(off);
					SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.7);
					audioicon=0;
					}

				}
	}

}

void HelloWorld::enteranme()
{
	this->removeAllChildren();
	if(size.width>1000)
	{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCSprite *sprite=CCSprite::create((path1+"enterback.png").c_str());
	sprite->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(sprite,17);
	CCLabelTTF *label=CCLabelTTF::create("Enter Name: ","Arial",35.0);
	label->setPosition(ccp(size.width/2-label->getContentSize().width-125,size.height/2+170));
	//label->setPosition(ccp(size.width/2-label->getContentSize().width-50,size.height/2));
	label->setColor(ccc3(225,225,225));
	this->addChild(label,18);
	ga=CCTextFieldTTF::textFieldWithPlaceHolder("",CCSize(400,50),kCCTextAlignmentLeft,"Arial",35.0);
		//ga->setPosition(ccp(size.width/2+50,size.height/2-10));
	ga->setPosition(ccp(size.width/2-20,size.height/2-10+170));
		ga->setColor(ccc3(225,225,225));
		ga->attachWithIME();
		ga->setTag(5897);
		this->addChild(ga,18);
		CCMenuItemImage *ok=CCMenuItemImage::create((path1+"ok.png").c_str(),(path1+"ok.png").c_str(),this,menu_selector(HelloWorld::initia));
	//	ok->setPosition(ccp(800,250));
		ok->setPosition(ccp(900,450));
		CCMenuItemImage *cancle=CCMenuItemImage::create((path1+"cancle.png").c_str(),(path1+"cancle.png").c_str(),this,menu_selector(HelloWorld::mainscene));
				//cancle->setPosition(ccp(450,250));
		cancle->setPosition(ccp(650,450));
		CCMenu *menu=CCMenu::create(ok,cancle,NULL);
		menu->setPosition(CCPointZero);
		this->addChild(menu,18);
		//fprintf(stderr,ga->getPlaceHolder());
		this->schedule(schedule_selector(HelloWorld::cht));
	}
	else
	{
		CCSize size=CCDirector::sharedDirector()->getWinSize();
		CCSprite *sprite=CCSprite::create((path1+"enterback.png").c_str());
			sprite->setPosition(ccp(size.width/2,size.height/2));
			this->addChild(sprite,17);
			CCLabelTTF *label=CCLabelTTF::create("Enter Name: ","Arial",35.0);
			label->setPosition(ccp(size.width/2-label->getContentSize().width-125,size.height/2+170));
			//label->setPosition(ccp(size.width/2-label->getContentSize().width-50,size.height/2));
			label->setColor(ccc3(225,225,225));
			this->addChild(label,18);
			ga=CCTextFieldTTF::textFieldWithPlaceHolder("",CCSize(400,50),kCCTextAlignmentLeft,"Arial",35.0);
				//ga->setPosition(ccp(size.width/2+50,size.height/2-10));
			ga->setPosition(ccp(size.width/2-20,size.height/2-10+170));
				ga->setColor(ccc3(225,225,225));
				ga->attachWithIME();
				ga->setTag(5897);
				this->addChild(ga,18);
				CCMenuItemImage *ok=CCMenuItemImage::create((path1+"ok.png").c_str(),(path1+"ok.png").c_str(),this,menu_selector(HelloWorld::initia));
			//	ok->setPosition(ccp(800,250));
				ok->setPosition(ccp(210,384));
				CCMenuItemImage *cancle=CCMenuItemImage::create((path1+"cancle.png").c_str(),(path1+"cancle.png").c_str(),this,menu_selector(HelloWorld::mainscene));
						//cancle->setPosition(ccp(450,250));
				cancle->setPosition(ccp(466,384));
				CCMenu *menu=CCMenu::create(ok,cancle,NULL);
				menu->setPosition(CCPointZero);
				this->addChild(menu,18);
				//fprintf(stderr,ga->getPlaceHolder());
				this->schedule(schedule_selector(HelloWorld::cht));

	}

}

//void HelloWorld::cht()
//{
//	if(ga->getString()!=NULL)
//	{
//	string str=(string)(ga->getString());
//	if(str.length()==10)
//	{
//		nale=(string)(ga->getString());
//	}
//	if(str.length()>10)
//	{
//
//		//str.push_back('\b');
//		ga->setString(nale.c_str());
//
//	}
//	else
//	{
//		//ga->attachWithIME();
//	}
//
//	}
//}
void HelloWorld::initia()
{
	const char *name=ga->getString();

			name123=(string)name;
			if(name123.length()!=0)
					{
				ga->detachWithIME();
			HelloWorld::initiate();
					}
}
void HelloWorld::initiate()
{

this->setTouchEnabled(true);
	this->unscheduleAllSelectors();
	m4=0;


			fprintf(stderr,"hai 4");
this->removeAllChildren();
fprintf(stderr,"hai 5");
timeer=31;
if(size.width>1000)
{
CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(("z10/background.wav"),true);
	timer=CCLabelTTF::create("","Arial",45.0);
		timer->setPosition(ccp(150,715));
		this->addChild(timer,900);
		timer->setColor(ccc3(0,0,225));
		timer->setTag(1453);
	HelloWorld::backtime();
	this->schedule(schedule_selector(HelloWorld::backtime),1.0);

	background=CCSprite::create(("z10/back.png"));
	background->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(background,0);
	background->setTag(7);
	character=CCSprite::create(("z10/norch.png"));
	character->setPosition(ccp(size.width/2,size.height/2-270));
	this->addChild(character,3);
	character->setTag(747474);
	eleleg=CCSprite::create(("z10/ele.png"));
	eleleg->setPosition(ccp(size.width/2,size.height/2+800));
	this->addChild(eleleg,3);
	eleleg->setTag(1);
	fprintf(stderr,"hai 6");
	meters=CCLabelTTF::create("0 score","Arial",55.0f);
									meters->setPosition(ccp(size.width/2,size.height-50));
									meters->setAnchorPoint(ccp(0.5,0.5));
									meters->setColor(ccc3(0,0,1));
									this->addChild(meters,44);

									HelloWorld::playpause();
	    this->schedule(schedule_selector(HelloWorld::antcheck));
	    this->schedule(schedule_selector(HelloWorld::collisions));
	    this->schedule(schedule_selector(HelloWorld::updatemeters),1.0);










	this->schedule(schedule_selector(HelloWorld::eleleg1),3.0);
	HelloWorld::partic();
	fprintf(stderr,"hai 7");
}
else
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("q10/background.wav",true);
		timer=CCLabelTTF::create("","Arial",25.0);
			timer->setPosition(ccp(150,size.height-50));
			this->addChild(timer,900);
			timer->setColor(ccc3(0,0,225));
			timer->setTag(1453);
		HelloWorld::backtime();
		this->schedule(schedule_selector(HelloWorld::backtime),1.0);

		background=CCSprite::create("q10/back.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(background,0);
		background->setTag(7);
		character=CCSprite::create("q10/norch.png");
		character->setPosition(ccp(size.width/2,size.height/2-270));
		this->addChild(character,3);
		character->setTag(747474);
		eleleg=CCSprite::create("q10/elelleg.png");
		eleleg->setPosition(ccp(size.width/2,size.height/2+800));
		this->addChild(eleleg,3);
		eleleg->setTag(1);

		meters=CCLabelTTF::create("0 score","Arial",25.0f);
										meters->setPosition(ccp(size.width/2,size.height-50));
										meters->setAnchorPoint(ccp(0.5,0.5));
										meters->setColor(ccc3(0,0,1));
										this->addChild(meters,44);

										HelloWorld::playpause();
		    this->schedule(schedule_selector(HelloWorld::antcheck));
		    this->schedule(schedule_selector(HelloWorld::collisions));
		    this->schedule(schedule_selector(HelloWorld::updatemeters),1.0);










		this->schedule(schedule_selector(HelloWorld::eleleg1),3.0);
		HelloWorld::partic();
}

}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::eleleg1(float dt)
{
	iflag=1;
	eleleg->runAction(CCSequence::create(CCMoveTo::create(1.0,ccp(x,size.height/2-10)),CCMoveTo::create(0.25,ccp(x,size.height/2+600)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::removeele)),NULL));
	HelloWorld::shake();
	//iflag=0;
}
void HelloWorld::eleleg2(float dt)
{
	iflag=1;
	eleleg->runAction(CCSequence::create(CCMoveTo::create(0.5,ccp(x,size.height/2-10)),CCMoveTo::create(0.25,ccp(x,size.height/2+600)),CCMoveTo::create(0.5,ccp(x,size.height/2-10)),CCMoveTo::create(0.25,ccp(x,size.height/2+600)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::removeele)),NULL));
	//HelloWorld::shake();
	//iflag=0;
}
void HelloWorld::eleleg3(float dt)
{
	iflag=1;
	eleleg->runAction(CCSequence::create(CCMoveTo::create(0.25,ccp(x,size.height/2-10)),CCMoveTo::create(0.25,ccp(x,size.height/2+600)),CCMoveTo::create(0.25,ccp(x,size.height/2-10)),CCMoveTo::create(0.25,ccp(x,size.height/2+600)),CCMoveTo::create(0.25,ccp(x,size.height/2-10)),CCMoveTo::create(0.25,ccp(x,size.height/2+600)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::removeele)),NULL));
	//HelloWorld::shake();
	//iflag=0;
}
void HelloWorld::elelegremove(float dt)
{
	if(eleleg)
	{
			//eleleg->runAction(CCSequence::create(CCMoveTo::create(0.25,ccp(x,size.height/2+400)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::removeele)),NULL));
	}
}
void HelloWorld::removeele(float dt)
{
	iflag=0;
	if(eleleg)
	{
		//this->removeChildByTag(1);
	}
}
void HelloWorld::ontouch()
{
	if(character->isRunning())
	{
		character->stopActionByTag(747474);
	}
this->setTouchEnabled(true);
}
void HelloWorld::offtouch()
{
this->setTouchEnabled(false);
}
void HelloWorld::ccTouchesBegan(cocos2d::CCSet *touches,cocos2d::CCEvent *event)
{
	fprintf(stderr,"touchedd....");
    CCSize visibleSize1 = CCDirector::sharedDirector()->getVisibleSize();
        CCTouch *touch=(CCTouch *)(touches->anyObject());
       CCPoint location=touch->getLocation();
      // character->runAction(CCMoveTo::create(0.5,ccp(location.x,size.height/2-270)));
       character->runAction(CCSequence::create(CCCallFuncN::create(this,callfuncN_selector(HelloWorld::offtouch)),CCJumpTo::create(0.5,ccp(location.x,character->getPosition().y),50.0,3),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::ontouch)),NULL));
}
void HelloWorld::antcheck(float dt)
{
if(character)
{
	m_emitter->setPosition(ccp(character->getPosition().x,size.height/2-270));
}
	if(iflag==0)
	{
     x=character->getPosition().x;
     eleleg->setPosition(ccp(x,size.height/2+600));
	}
	 if(character->getPositionX()>1270)
	 {
		 character->setPosition(ccp(1270,character->getPosition().y));
	 }
	 if(character->getPositionX()<36)
	 {
		 character->setPosition(ccp(36,character->getPosition().y));
	 }
}
void HelloWorld::shake()
{

	//this->runAction(CCMotionStreak::create()
}
void HelloWorld::collisions(float dt)
{
	if(m4==30)
	{
		HelloWorld::level2();
	}
	if(m4==130)
	{
		HelloWorld::level3();
	}
	CCRect mainrect,redrect,orgrect;
		if(character)
			{
				 mainrect=CCRectMake(character->getPositionX()-character->getContentSize().width/2-20,character->getPositionY()-character->getContentSize().height/2-20,character->getContentSize().width-50,character->getContentSize().height-50);
			}
		if(eleleg)
			{
				 redrect=CCRectMake(eleleg->getPositionX()-eleleg->getContentSize().width/2-20,eleleg->getPositionY()-eleleg->getContentSize().height/2-20,eleleg->getContentSize().width-50,eleleg->getContentSize().height-50);
			}
		if(mainrect.intersectsRect(redrect))
		{
		HelloWorld::Gameover();
		this->unschedule(schedule_selector(HelloWorld::updatemeters));
		}
}
void HelloWorld::Gameover()
{
	this->setTouchEnabled(false);
	this->unschedule(schedule_selector(HelloWorld::backtime));
	if(size.width>1000)
	{
	CCSprite *kol=CCSprite::create(("z10/go.png"));
	kol->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(kol,4);
	this->unschedule(schedule_selector(HelloWorld::collisions));
	this->runAction(CCSequence::create(CCDelayTime::create(1.5),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::getscore)),NULL));
	  if(this->getChildByTag(668))
				    		     {
				    		    	 this->removeChildByTag(668);
				    		     }
	}
	else
	{
		CCSprite *kol=CCSprite::create("q10/go.png");
			kol->setPosition(ccp(size.width/2,size.height/2));
			this->addChild(kol,4);
			this->unschedule(schedule_selector(HelloWorld::collisions));
			this->runAction(CCSequence::create(CCDelayTime::create(1.5),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::getscore)),NULL));
			  if(this->getChildByTag(668))
						    		     {
						    		    	 this->removeChildByTag(668);
						    		     }

	}

}
void HelloWorld::scoreall()
{CCSize size = CCDirector::sharedDirector()->getWinSize();
if(size.width>1000)
{
	 int rc7=	sqlite3_open_v2("data/database.db",&m_db,SQLITE_OPEN_READONLY,NULL);
			    		     if(rc7==SQLITE_OK)
			    		     {
			    		    	 fprintf(stderr,"\ndatabase is opened succesfully");
			    		     }
			    		     static const char* selectSql = "SELECT * FROM store order by score DESC limit 5";
			    		     sqlite3_stmt* selectStmt;
			    		     int rc10 = sqlite3_prepare_v2(m_db, selectSql, strlen(selectSql), &selectStmt, NULL);
			    		     if (rc10 == SQLITE_OK) {
			    		     fprintf(stderr, "Sqlite select %d\n", rc10);

			    		     }

			    		     rc10 = sqlite3_step(selectStmt);
			    	//	     for(int r=0;r<sqlite3_last_insert_rowid(m_db);r++)
			    	//	     {
			    	//	    	 fprintf(stderr,"%d",(sqlite3_column_int(selectStmt, 0)));
			    	//	     }
			    		     fprintf(stderr,"\nvalue of sqlite_row rc10 tagore:%d",rc10);

			    		     CCSprite *bah=CCSprite::create("z10/enterback.png");
			    		     bah->setPosition(ccp(size.width/2,size.height/2));
			    		     this->addChild(bah,100000000);
			    		     bah->setTag(9877);

			    		     CCLabelTTF *score=CCLabelTTF::create("  Rank     NAME                       SCORE       ","Arial",45.0);
			    		     score->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-100+50,CCDirector::sharedDirector()->getWinSize().height-300));
			    		     this->addChild(score,100000001);
			    		     score->setTag(9877);
			    		     CCLabelTTF *ansscore,*ansscore1,*ansscore2,*ansscore3;
			    		    char ar1[100],ar2[100],ar3[100],ar4[100];
			    		    int i=1;
			    		     while (rc10 == SQLITE_ROW) {

			    		    	 fprintf(stderr,"\nentering into it");
			    		    	 fprintf(stderr,"\n%d",rc10);
			    		    	 sprintf(ar1,"%d",i);
			    		    	 sprintf(ar2,"%s",(const char *)sqlite3_column_text(selectStmt,0));
			    		    	 sprintf(ar3,"%d",sqlite3_column_int(selectStmt, 1));

			    		    	 ansscore=CCLabelTTF::create("","Arial",35.0);
			    		    	 ansscore->setString(ar1);
			    		    	 ansscore->setPosition(ccp(170,(CCDirector::sharedDirector()->getWinSize().height-300)-(i*60)));
			    		    	 ansscore->setTag(9877);
			    		    	 this->addChild(ansscore,100000001);
			    		    	 ansscore1=CCLabelTTF::create("","Arial",35.0,CCSize(500,50),kCCTextAlignmentLeft);
			    		    				    		    	 ansscore1->setString(ar2);
			    		    				    		    	 ansscore1->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-90,(CCDirector::sharedDirector()->getWinSize().height-300)-(i*60)));
			    		    				    		    	 ansscore1->setTag(9877);
			    		    	 this->addChild(ansscore1,100000001);
			    		    	 ansscore2=CCLabelTTF::create("","Arial",35.0);
			    		    	 ansscore2->setString(ar3);
			    		    	 ansscore2->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2+240,(CCDirector::sharedDirector()->getWinSize().height-300)-(i*60)));
			    		    	 ansscore2->setTag(9877);

			    		    	 this->addChild(ansscore2,100000001);

			    		    	 fprintf(stderr,"\t%d\n",(sqlite3_column_int(selectStmt, 1)));
			    		    	 const unsigned char *st=sqlite3_column_text(selectStmt,0);

			    		    	 i++;

			    		   //  const char* user = reinterpret_cast<const char*>(sqlite3_column_int(selectStmt, 0));
			    		     //Score score(rank, user, sqlite3_column_int(selectStmt, 1));
			    		     //scores.push_back(score);
			    		    // rank++;
			    		     rc10 = sqlite3_step(selectStmt);
			    		     }
			    		     sqlite3_finalize(selectStmt);
			    		     sqlite3_close_v2(m_db);

			    		     CCMenuItemImage *close=CCMenuItemImage::create("z10/tryagain.png","z10tryagain.png",this,menu_selector(HelloWorld::initiate));
			    		     CCMenuItemImage *close1=CCMenuItemImage::create("z10/quit.png","zz10/quit.png",this,menu_selector(HelloWorld::mainscene));
this->setTouchEnabled(false);
			    		     close->setPosition(ccp(size.width/2,50));
			    		     close1->setPosition(ccp(close->getPosition().x+close->getContentSize().width/2+200,50));
			    		     CCMenu *clsmenu=CCMenu::create(close,close1,NULL);
			    		     clsmenu->setPosition(CCPointZero);
			    		     clsmenu->setTag(9877);
			    		     this->addChild(clsmenu,100000001);

			    		     if(this->getChildByTag(668))
			    		     {
			    		    	 this->removeChildByTag(668);
			    		     }
			    		     CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
else
{
	int rc7=	sqlite3_open_v2("data/database.db",&m_db,SQLITE_OPEN_READONLY,NULL);
				    		     if(rc7==SQLITE_OK)
				    		     {
				    		    	 fprintf(stderr,"\ndatabase is opened succesfully");
				    		     }
				    		     static const char* selectSql = "SELECT * FROM store order by score DESC limit 5";
				    		     sqlite3_stmt* selectStmt;
				    		     int rc10 = sqlite3_prepare_v2(m_db, selectSql, strlen(selectSql), &selectStmt, NULL);
				    		     if (rc10 == SQLITE_OK) {
				    		     fprintf(stderr, "Sqlite select %d\n", rc10);

				    		     }

				    		     rc10 = sqlite3_step(selectStmt);
				    	//	     for(int r=0;r<sqlite3_last_insert_rowid(m_db);r++)
				    	//	     {
				    	//	    	 fprintf(stderr,"%d",(sqlite3_column_int(selectStmt, 0)));
				    	//	     }
				    		     fprintf(stderr,"\nvalue of sqlite_row rc10 tagore:%d",rc10);
				    		     CCSprite *bah=CCSprite::create("q10/enterback.png");
				    		     bah->setPosition(ccp(size.width/2,size.height/2));
				    		     this->addChild(bah,100000000);
				    		     bah->setTag(9877);
	//			    		     CCLabelTTF *score=CCLabelTTF::create("  Rank     NAME                       SCORE       ","Arial",25.0);
	//			    		     score->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-100+50,CCDirector::sharedDirector()->getWinSize().height-300));
				    		     CCLabelTTF *score=CCLabelTTF::create("    Rank    NAME        SCORE          ","Arial",35.0);
				    		     	score->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-100+50,CCDirector::sharedDirector()->getWinSize().height-200));
				    		     this->addChild(score,100000001);
				    		     score->setTag(9877);
				    		     CCLabelTTF *ansscore,*ansscore1,*ansscore2,*ansscore3;
				    		    char ar1[100],ar2[100],ar3[100],ar4[100];
				    		    int i=1;
				    		     while (rc10 == SQLITE_ROW) {

				    		    	 fprintf(stderr,"\nentering into it");
				    		    	 fprintf(stderr,"\n%d",rc10);
				    		    	 sprintf(ar1,"%d",i);
				    		    	 sprintf(ar2,"%s",(const char *)sqlite3_column_text(selectStmt,0));
				    		    	 sprintf(ar3,"%d",sqlite3_column_int(selectStmt, 1));

	//			    		    	 ansscore=CCLabelTTF::create("","Arial",25.0);
	//			    		    	 ansscore->setString(ar1);
	//			    		    	 ansscore->setPosition(ccp(170,(CCDirector::sharedDirector()->getWinSize().height-300)-(i*60)));
	//			    		    	 ansscore->setTag(9877);
	//			    		    	 this->addChild(ansscore,100000001);
	//			    		    	 ansscore1=CCLabelTTF::create("","Arial",25.0,CCSize(500,50),kCCTextAlignmentLeft);
	//			    		    				    		    	 ansscore1->setString(ar2);
	//			    		    				    		    	 ansscore1->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-90,(CCDirector::sharedDirector()->getWinSize().height-300)-(i*60)));
	//			    		    				    		    	 ansscore1->setTag(9877);
	//			    		    	 this->addChild(ansscore1,100000001);
	//			    		    	 ansscore2=CCLabelTTF::create("","Arial",25.0);
	//			    		    	 ansscore2->setString(ar3);
	//			    		    	 ansscore2->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2+240,(CCDirector::sharedDirector()->getWinSize().height-300)-(i*60)));
	//			    		    	 ansscore2->setTag(9877);
	//
	//			    		    	 this->addChild(ansscore2,100000001);
				    		    	 ansscore=CCLabelTTF::create("","Arial",30.0);
				    		    	 		ansscore->setString(ar1);
				    		    	 		ansscore->setPosition(ccp(70,(CCDirector::sharedDirector()->getWinSize().height-200)-(i*60)));
				    		    	 		ansscore->setTag(9877);
				    		    	 		this->addChild(ansscore,100000001);
				    		    	 		ansscore1=CCLabelTTF::create("","Arial",30.0,CCSize(250,50),kCCTextAlignmentLeft);
				    		    	 		ansscore1->setString(ar2);
				    		    	 		ansscore1->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2-60,(CCDirector::sharedDirector()->getWinSize().height-200)-(i*60)));
				    		    	 		ansscore1->setTag(9877);
				    		    	 		this->addChild(ansscore1,100000001);
				    		    	 		ansscore2=CCLabelTTF::create("","Arial",30.0);
				    		    	 		ansscore2->setString(ar3);
				    		    	 		ansscore2->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2+65,(CCDirector::sharedDirector()->getWinSize().height-200)-(i*60)));
				    		    	 		ansscore2->setTag(9877);
				    		    	 		this->addChild(ansscore2,100000001);
				    		    	 fprintf(stderr,"\t%d\n",(sqlite3_column_int(selectStmt, 1)));
				    		    	 const unsigned char *st=sqlite3_column_text(selectStmt,0);

				    		    	 i++;

				    		   //  const char* user = reinterpret_cast<const char*>(sqlite3_column_int(selectStmt, 0));
				    		     //Score score(rank, user, sqlite3_column_int(selectStmt, 1));
				    		     //scores.push_back(score);
				    		    // rank++;
				    		     rc10 = sqlite3_step(selectStmt);
				    		     }
				    		     sqlite3_finalize(selectStmt);
				    		     sqlite3_close_v2(m_db);
				    		     CCMenuItemImage *close=CCMenuItemImage::create("q10/tryagain.png","q10/tryagain.png",this,menu_selector(HelloWorld::initiate));
				    		     CCMenuItemImage *close1=CCMenuItemImage::create("q10/quit.png","q10/quit.png",this,menu_selector(HelloWorld::mainscene));
	this->setTouchEnabled(false);
				    		     close->setPosition(ccp(size.width/2-150,50));
				    		     close1->setPosition(ccp(close->getPosition().x+close->getContentSize().width+10,50));
				    		     CCMenu *clsmenu=CCMenu::create(close,close1,NULL);
				    		     clsmenu->setPosition(CCPointZero);
				    		     clsmenu->setTag(9877);
				    		     this->addChild(clsmenu,100000001);
				    		     if(this->getChildByTag(668))
				    		     {
				    		    	 this->removeChildByTag(668);
				    		     }
				    		     CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
}
void HelloWorld::clo()
{
	for(int i=1;i<=18;i++)
	{
		this->removeChildByTag(9877);
	}
}

void HelloWorld::getscore()
{
	fprintf(stderr,name123.c_str());

			     int rc7=	sqlite3_open_v2("data/database.db",&m_db,SQLITE_OPEN_READONLY,NULL);
			    		     if(rc7==SQLITE_OK)
			    		     {
			    		    	 fprintf(stderr,"\ndatabase is opened succesfully");
			    		     }
			    		     static const char* selectSql = "SELECT * FROM store";
			    		     sqlite3_stmt* selectStmt;
			    		     int rc10 = sqlite3_prepare_v2(m_db, selectSql, strlen(selectSql), &selectStmt, NULL);
			    		     if (rc10 == SQLITE_OK) {
			    		     fprintf(stderr, "Sqlite select %d\n", rc10);

			    		     }

			    		     rc10 = sqlite3_step(selectStmt);
			    	//	     for(int r=0;r<sqlite3_last_insert_rowid(m_db);r++)
			    	//	     {
			    	//	    	 fprintf(stderr,"%d",(sqlite3_column_int(selectStmt, 0)));
			    	//	     }
			    		     fprintf(stderr,"\nvalue of sqlite_row rc10 tagore:%d",rc10);
			    		     while (rc10 == SQLITE_ROW) {
			    		    	 fprintf(stderr,"\nentering into it");
			    		    	 fprintf(stderr,"\n%d",rc10);
			    		    	 fprintf(stderr,"\t%d\n",(sqlite3_column_int(selectStmt, 1)));
			    		    	 const unsigned char *st=sqlite3_column_text(selectStmt,0);
			    		    	 if((const char*)st==name123)
			    		    	 {
			    		    		 newentry=0;
			    		    	 }
			    		    	 scores.push_back(sqlite3_column_int(selectStmt, 1));
			    		   //  const char* user = reinterpret_cast<const char*>(sqlite3_column_int(selectStmt, 0));
			    		     //Score score(rank, user, sqlite3_column_int(selectStmt, 1));
			    		     //scores.push_back(score);
			    		    // rank++;
			    		     rc10 = sqlite3_step(selectStmt);
			    		     }
			    		     sqlite3_finalize(selectStmt);
			    		     sqlite3_close_v2(m_db);
			    		     int highscore=0;
			    		     	for(std::vector<int>::iterator scr=scores.begin();scr!=scores.end();scr++)
			    		     	{
			    		     		fprintf(stderr,"\n from vector scores:%d",*scr);
			    		     		if(*scr>highscore)
			    		     		{
			    		     			highscore=*scr;
			    		     		}
			    		     	}
			    		     fprintf(stderr,"the largest value is :%d",highscore);
			    		     char strhigh[100]={0};
			    		     sprintf(strhigh,"High Score : %d",highscore);
			    		     char displaystr[100];
			    		     		     	          	     	         	  	            	    	    	    sprintf(displaystr,"Total Eggs : %d",m4);
	if(newentry==1)
	{
		fprintf(stderr,"\n Inserting new entery\n");
			    		     		     rc = sqlite3_open_v2("data/database.db", &m_db, SQLITE_OPEN_READWRITE, NULL);
			    		     		     fprintf(stderr,"\ncreating database 1");
			    		     		     if (rc != SQLITE_OK) {
			    		     		     fprintf(stderr,"\nentering 27");
			    		     		     fprintf(stderr, "Could not open scores db. %d\n", rc);
			    		     		     fprintf(stderr,"\nentering 28");
			    		     		     //fprintf(stderr,"\nentering 29");
			    		     		     }
			    		     		     if(rc==SQLITE_OK)
			    		     		     {
			    		     		     fprintf(stderr, "created databse %d", rc);
			    		     		     fprintf(stderr,"entering into database");
			    		     		     }
		char str3[1000]={0};

	std::string st((char *)name123.c_str());
	fprintf(stderr,name123.c_str());
	fprintf(stderr,"\n%s",st.c_str());

		sprintf(str3,"INSERT INTO store(name,score) values('%s',%d)",st.c_str(),m4);
			     	    static const char* insertSql =str3;//"INSERT INTO store(name,score) values('sai',10)" ;
			     	          	     	         	  	            	    	      	   sqlite3_stmt* insertStmt;
			     	          	     	         	  	            	    	      	      fprintf(stderr,"\n submitscore 3");
			     	          	     	         	  	            	    	      	      int rc = sqlite3_prepare_v2(m_db, insertSql, strlen(insertSql), &insertStmt, NULL);
			     	          	     	         	  	            	    	      	      fprintf(stderr,"\n submitscore 4");
			     	          	     	         	  	            	    	      	      if (rc == SQLITE_OK) {
			     	          	     	         	  	            	    	      	      	fprintf(stderr,"\n submitscore 5");
			     	          	     	         	  	            	    	      	          fprintf(stderr, "\n insertion executed %d\n", rc);

			     	          	     	         	  	            	    	      	      }

			     	          	     	         	  	            	    	      	   int   rc5 = sqlite3_bind_text(insertStmt,1,name123.c_str(),st.length(),NULL);
			     	          	     	         	  	            	    	      	      if (rc5 == SQLITE_OK) {
			     	          	     	         	  	            	    	      	      	fprintf(stderr,"\n submitscore 6");
			     	          	     	         	  	            	    	      	          fprintf(stderr, "\n from Sqlite bind  %d\n", rc5);
			     	          	     	         	  	            	    	      	          sqlite3_finalize(insertStmt);

			     	          	     	         	  	            	    	      	      }
			     	          	     	         	  	            	    	       int   rc0 = sqlite3_bind_int(insertStmt,2,m4);
			     	          	     	         	  	            	    	      	if (rc0 == SQLITE_OK) {
			     	          	     	         	  	            	    	      	fprintf(stderr,"\n submitscore 6");
			     	          	     	         	  	            	    	      	fprintf(stderr, "\n from Sqlite bind  %d\n", rc5);
			     	          	     	         	  	            	    	      	sqlite3_finalize(insertStmt);
			     	          	     	         	  	            	    	      	}

			     	          	     	         	  	            	    	      	     int rc6 = sqlite3_step(insertStmt);
			     	          	     	         	  	            	    	      	      if (rc6 == SQLITE_DONE) {
			     	          	     	         	  	            	    	      	      	fprintf(stderr,"\n submitscore 7");
			     	          	     	         	  	            	    	      	          fprintf(stderr, "\nfrom Sqlite insert %d\n", rc6);
			     	          	     	         	  	            	    	      	         sqlite3_finalize(insertStmt);

			     	          	     	         	  	            	    	      	      }
			     	          	     	         	  	            	    	      	      if(rc6 !=SQLITE_DONE)
			     	          	     	         	  	            	    	      	      {
			     	          	     	         	  	            	    	      	    	  fprintf(stderr,"\n error in rc6\n \n");
			     	          	     	         	  	            	    	      	    	fprintf(stderr,sqlite3_errmsg(m_db));
			     	          	     	         	  	            	    	      	    	fprintf(stderr,"\n%d",rc6);
			     	          	     	         	  	            	    	      	    	  	          //sqlite3_finalize(insertStmt);

			     	          	     	         	  	            	    	      	      }

			     	          	     	         	  	            	    	      	      sqlite3_finalize(insertStmt);
			     	          	     	         	  	            	    	      	     sqlite3_close_v2(m_db);

	}
	else if(newentry==0)
	{
		fprintf(stderr,"\n updating old entery");
			     int rc14=	sqlite3_open_v2("data/database.db",&m_db,SQLITE_OPEN_READWRITE,NULL);
			     	     if(rc14==SQLITE_OK)
			     	     {

			     	    	 fprintf(stderr,"\ndatabase is opened succesfully");
			     	     }

	 char str14[1000]={0};
			     	   sprintf(str14,"UPDATE store SET score=%d WHERE name='%s'",m4,name123.c_str());
	//
			     	    static const char* updateSql =str14;
			     	    	     sqlite3_stmt* updateStmt;
			     	    	     int rc15 = sqlite3_prepare_v2(m_db, updateSql, strlen(updateSql), &updateStmt, NULL);
			     	    	     if (rc15 == SQLITE_OK) {
			     	    	     fprintf(stderr, "Sqlite updated successfully %d\n", rc);

			     	    	     }
			     	    	    sqlite3_bind_int(updateStmt,2,m4);
			     	    	    if(sqlite3_bind_int(updateStmt,2,m4)==SQLITE_OK)
			     	    	    {
			     	    	    	fprintf(stderr,"\nit is not possible 1");
			     	    	   sqlite3_finalize(updateStmt);
			     	    	    }
			     	    	   sqlite3_step(updateStmt);
			     	    	   if( sqlite3_step(updateStmt)==SQLITE_DONE)
			     	    	   {
			     	    		  fprintf(stderr,"\nit is not possible 1");
			     	    	    sqlite3_finalize(updateStmt);
			     	    	   }
			     	    	  sqlite3_finalize(updateStmt);
			     	    	  sqlite3_close_v2(m_db);
			     	    	  newentry=1;
	}
	HelloWorld::scoreall();

}
void HelloWorld::partic()
{
    m_emitter = CCParticleFlower::create();
    m_emitter->retain();
    this->addChild(m_emitter, 0);
    m_emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage(s_stars1) );
    m_emitter->setLife(2.0);
}
void HelloWorld::level2()
{
	 if(this->getChildByTag(668))
				    		     {
				    		    	 this->removeChildByTag(668);
				    		     }
	m4++;
	m4=31;
	this->unschedule(schedule_selector(HelloWorld::backtime));
	this->unschedule(schedule_selector(HelloWorld::updatemeters));
	this->unschedule(schedule_selector(HelloWorld::collisions));
	if(size.width>1000)
	{
	sprite=CCSprite::create(("z10/leveltwo.png"));
	sprite->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(sprite,4);
	sprite->setTag(6);
	this->unschedule(schedule_selector(HelloWorld::eleleg1));
	this->runAction(CCSequence::create(CCDelayTime::create(2.0),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::level2start)),NULL));
	HelloWorld::playpause();
	}
	else
	{
		sprite=CCSprite::create("q10/leveltwo.png");
			sprite->setPosition(ccp(size.width/2,size.height/2));
			this->addChild(sprite,4);
			sprite->setTag(6);
			this->unschedule(schedule_selector(HelloWorld::eleleg1));
			this->runAction(CCSequence::create(CCDelayTime::create(2.0),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::level2start)),NULL));
			HelloWorld::playpause();

	}
}

void HelloWorld::updatemeters(float dt)
		{
		m4+=1;
		str[100];
		std::string m="score";
		sprintf(str,("%d "+m).c_str(),m4);
		meters->setString(str);
		meters->setPosition(ccp(size.width/2,size.height-50));
		}
void HelloWorld::level2start(float dt)
{
	if(size.width>1000)
	{
	timeer=101;
	HelloWorld::backtime();
	this->schedule(schedule_selector(HelloWorld::backtime),1.0);

if(background)
{
	this->removeChildByTag(7);
}
CCSprite *snow=CCSprite::create(("z10/snow.png"));
snow->setPosition(ccp(size.width/2,size.height/2));
this->addChild(snow,2);
	if(sprite)
	{
		this->removeChildByTag(6);
	}
	this->schedule(schedule_selector(HelloWorld::eleleg2),2.5);

	this->schedule(schedule_selector(HelloWorld::collisions));
	this->schedule(schedule_selector(HelloWorld::updatemeters),1.0);
	HelloWorld::snowcreation();
	}
	else
	{
		timeer=101;
			HelloWorld::backtime();
			this->schedule(schedule_selector(HelloWorld::backtime),1.0);

		if(background)
		{
			this->removeChildByTag(7);
		}
		CCSprite *snow=CCSprite::create("q10/snow.png");
		snow->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(snow,2);
			if(sprite)
			{
				this->removeChildByTag(6);
			}
			this->schedule(schedule_selector(HelloWorld::eleleg2),2.5);

			this->schedule(schedule_selector(HelloWorld::collisions));
			this->schedule(schedule_selector(HelloWorld::updatemeters),1.0);
			HelloWorld::snowcreation();

	}


}
void HelloWorld::snowcreation()
{
	  m_emitter1 = CCParticleSnow::create();
	    m_emitter1->retain();
	    this->addChild(m_emitter1, 2);

	    CCPoint p = m_emitter1->getPosition();
	    m_emitter1->setPosition( ccp( p.x, p.y-110) );
	    m_emitter1->setLife(3);
	    m_emitter1->setLifeVar(1);

	    // gravity
	    m_emitter1->setGravity(ccp(0,-10));

	    // speed of particles
	    m_emitter1->setSpeed(130);
	    m_emitter1->setSpeedVar(30);


	    ccColor4F startColor = m_emitter1->getStartColor();
	    startColor.r = 0.9f;
	    startColor.g = 0.9f;
	    startColor.b = 0.9f;
	    m_emitter1->setStartColor(startColor);

	    ccColor4F startColorVar = m_emitter1->getStartColorVar();
	    startColorVar.b = 0.1f;
	    m_emitter1->setStartColorVar(startColorVar);

	    m_emitter1->setEmissionRate(m_emitter1->getTotalParticles()/m_emitter1->getLife());

	    m_emitter1->setTexture( CCTextureCache::sharedTextureCache()->addImage(s_snow) );
	    m_emitter1->setPosition(ccp(size.width/2,size.height));
}


void HelloWorld::level3()
{
	 if(this->getChildByTag(668))
				    		     {
				    		    	 this->removeChildByTag(668);
				    		     }
	m4++;
	m4=131;
	this->unschedule(schedule_selector(HelloWorld::backtime));
	this->unschedule(schedule_selector(HelloWorld::updatemeters));
	this->unschedule(schedule_selector(HelloWorld::collisions));
	this->unschedule(schedule_selector(HelloWorld::eleleg2));
	sprite=CCSprite::create((path1+"cryb.png").c_str());
	sprite->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(sprite,4);
	sprite->setTag(6);
	this->unschedule(schedule_selector(HelloWorld::eleleg1));
	this->runAction(CCSequence::create(CCDelayTime::create(2.0),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::level3start)),NULL));

	HelloWorld::playpause();
}



void HelloWorld::level3start(float dt)
{

if(background)
{
	this->removeChildByTag(7);
}
CCSprite *snow=CCSprite::create((path1+"cryo.png").c_str());
snow->setPosition(ccp(size.width/2,size.height/2));
this->addChild(snow,2);
	if(sprite)
	{
		this->removeChildByTag(6);
	}
	this->schedule(schedule_selector(HelloWorld::eleleg3),2.5);
	this->schedule(schedule_selector(HelloWorld::collisions));
	this->schedule(schedule_selector(HelloWorld::updatemeters),1.0);
	this->removeChildByTag(1453);
}
void HelloWorld::background1()
{
	CCSprite *ply=CCSprite::create((path1+"1.png").c_str());
	CCSprite *pus=CCSprite::create((path1+"2.png").c_str());
	if(j==0)
	{
paly->setNormalImage(ply);
paly->setSelectedImage(ply);
	CCDirector::sharedDirector()->pause();
	this->setTouchEnabled(false);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	j=1;
	}
	else if(j==1)
	{
		paly->setNormalImage(pus);
		paly->setSelectedImage(pus);
		this->setTouchEnabled(true);
		CCDirector::sharedDirector()->resume();
		CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		j=0;
	}
}

void HelloWorld::foreground()
{
	CCDirector::sharedDirector()->resume();
}
void HelloWorld::creditss()
{
	this->removeAllChildren();
	CCSprite *sp=CCSprite::create((path1+"creitsscreen.png").c_str());
	sp->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(sp,10);
	this->runAction(CCSequence::create(CCDelayTime::create(2.0),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::mainscene)),NULL));
}
void HelloWorld::helpp()
{
	this->removeAllChildren();
	CCSprite *sp=CCSprite::create((path1+"instuctions.png").c_str());
		sp->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(sp,10);
		this->runAction(CCSequence::create(CCDelayTime::create(2.0),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::mainscene)),NULL));
}

void HelloWorld::backtime()
{

	char a[100];
	timeer--;
	sprintf(a,"%d sec to go",timeer);
	timer->setString(a);

}
