#include "HelloWorldScene.h"
#include "Petla.h"
#include "Latanie.h"

USING_NS_CC;

Scene* HelloWorld::Stworzscene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    _eventDispatcher->removeAllEventListeners();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(_swallowsTouches);
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    s = Director::getInstance()->getWinSize();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("flappy.plist");
    bird = NULL;
    Resetgry();
    return true;
}

void HelloWorld::Resetgry()
{
    this->unscheduleUpdate();
    if (bird != NULL) bird->unscheduleUpdate();
    this->removeAllChildrenWithCleanup(true);
    GameOver = false;
    Tlo();
    Ziemia();
    DodPtak();
    this->scheduleUpdate();
    bird->scheduleUpdate(); 
}
void HelloWorld::Tlo()
{
    Sprite* bg = Sprite::createWithSpriteFrameName("background.png");
    bg->setPosition(s.width/2, s.height/2);
    this->addChild(bg);
    
}

void HelloWorld::Ziemia()
{
    land = Sprite::createWithSpriteFrameName("land.png");
    land->setAnchorPoint(Point(0, 0.5));
    land->setPosition(0, land->boundingBox().size.height/2 - 4);
    land->addComponent(new Petla());
    this->addChild(land);
}

void HelloWorld::DodPtak()
{
    bird = new Ptak();
    bird->setZOrder(1000);
    bird->setPosition(s.width/2, s.height/2);
    bird->addComponent(new Latanie());
    this->addChild(bird);
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
    if (GameOver)
    {
        Resetgry();
    }
    else
    {
        bird->tap();
    }
    
    return true;
}
