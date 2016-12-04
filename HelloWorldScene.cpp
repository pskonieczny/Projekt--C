#include "HelloWorldScene.h"
#include "config.h"
#include "Petla.h"
#include "Lot.h"
#include "Przewijanie.h"
#include "Przeszkody.h"

USING_NS_CC;

Scene* HelloWorld::Scena()
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
    Reset();
    this->addComponent(new Przeszkoda());
    return true;
}

void HelloWorld::Reset()
{
    this->unscheduleUpdate();
    if (bird != NULL) bird->unscheduleUpdate();
    this->removeAllChildrenWithCleanup(true);
    GameOver = false;
    Tlo();
    Ziemia();
    DPtak();
    Przewijanie();
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
    land->setZOrder(2);
	land->setAnchorPoint(Point(0, 0.5));
    land->setPosition(0, land->boundingBox().size.height/2 - 4);
    land->addComponent(new Petla());
    this->addChild(land);
}

void HelloWorld::DPtak()
{
    bird = new Ptak();
    bird->setZOrder(1000);
    bird->setPosition(s.width/2, s.height/2);
    bird->addComponent(new Lot());
    this->addChild(bird);
}

void HelloWorld::Przewijanie()
{
    layerMoveLeft = ParallaxNode::create();
    layerMoveLeft->addComponent(new PrzewLewo(land->boundingBox().size.width) );
    this->addChild(layerMoveLeft);
}

void HelloWorld::DPrzeszkoda()
{
    int r = rand();
    r = r%5;
    float dy = r * 10; 
    r = rand();
    r = r%2;
    if (r==0) dy = -dy;
    Sprite* pipe1 = Sprite::createWithSpriteFrameName("pipe1.png");
    Point pos = Point(s.width + pipe1->boundingBox().size.width/2,
                      s.height/2 + pipe1->boundingBox().size.height/2
                      + Timeprzesz/2 + Wysspadania/2 + dy
                      );
    Point pospipe1 = (layerMoveLeft->convertToNodeSpace(pos));
    Sprite* pipe2 = Sprite::createWithSpriteFrameName("pipe2.png");
    pos.y = s.height/2 - pipe2->boundingBox().size.height/2 - Timeprzesz + Wysspadania/2 + dy;
    Point pospipe2 = (layerMoveLeft->convertToNodeSpace(pos));
    int zOrder = land->getZOrder() - 1;
    layerMoveLeft->addChild(pipe1, zOrder, Point(1, 0), pospipe1);
    layerMoveLeft->addChild(pipe2, zOrder, Point(1, 0), pospipe2);
    pipe1->scheduleUpdate();
    pipe2->scheduleUpdate();
    
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
    if (GameOver)
    {
        Reset();
    }
    else
    {
        bird->Skok();
    }
    
    return true;
}
