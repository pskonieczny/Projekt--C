#ifndef __FlappyBird__AddPipe__
#define __FlappyBird__AddPipe__
#define ZiemiaP 15 
#define Przewwleft 0.3 
#define Dllotu 0.05 
#define Wys 50 
#define Dlot 0.5 
#define Wysspadania 127
#define TimePrzeszkody 2
#define Timeprzesz 80

#include <cocos2d.h>
#include "HelloWorldScene.h"

using namespace cocos2d;



class Przeszkoda : public Component
{
public:
    Przeszkoda();
private:   
    HelloWorld* parent; 
    float dl;
    virtual void update(float delta);
};

#endif
