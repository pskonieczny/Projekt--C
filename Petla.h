#ifndef __FlappyBird__MoveLoop__
#define __FlappyBird__MoveLoop__
#define ZiemiaP 15 
#define Przewwleft 0.3 
#define Dllotu 0.05 
#define Wys 50 
#define Dlot 0.5 
#define Wysspadania 127
#define TimePrzeszkody 2
#define Timeprzesz 80
#include <cocos2d.h>

using namespace cocos2d;

class Petla : public Component
{
public:
    Petla();
private:
    virtual void Wejscie();
    virtual void update(float delta);
    void AkcjaRuch();
};

#endif
