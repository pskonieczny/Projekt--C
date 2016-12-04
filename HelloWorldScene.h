#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#define ZiemiaP 15 
#define Przewwleft 0.3 
#define Dllotu 0.05 
#define Wys 50 
#define Dlot 0.5 
#define Wysspadania 127
#define TimePrzeszkody 2
#define Timeprzesz 80
#include "cocos2d.h"
#include "Ptak.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* Scena();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(HelloWorld);
    
    void DPrzeszkoda();
    bool GameOver;


private:
    
private:
    
    cocos2d::Size s;
    cocos2d::Sprite* land;
    Ptak* bird;
    
    cocos2d::ParallaxNode* layerMoveLeft;
    
    
	virtual bool onTouchBegan(cocos2d::Touch* touch,  cocos2d::Event* unused_event) override;
    
    void Tlo();
    void Ziemia();
    void DPtak();
    void Przewijanie();
    void Reset();

};

#endif
