#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Ptak.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* Stworzscene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(HelloWorld);

    bool GameOver;

private:
    
private:
    
    cocos2d::Size s;
    cocos2d::Sprite* land;
    Ptak* bird;
    
    cocos2d::ParallaxNode* layerMoveLeft;
    
    cocos2d::Label* lbscore;
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event) override;
    
    void Tlo();
    void Ziemia();
    void DodPtak();
    void Resetgry();

};

#endif
