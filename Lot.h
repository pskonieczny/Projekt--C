#ifndef __FlappyBird__Flying__
#define __FlappyBird__Flying__
#define ZiemiaP 15 
#define Przewwleft 0.3 
#define Dllotu 0.05 
#define Wys 50 
#define Dlot 0.5 
#define Wysspadania 127
#define TimePrzeszkody 2
#define Timeprzesz 80
#include <cocos2d.h>
#include "Ptak.h"

using namespace cocos2d;

class Lot : public Component
{
public:
    Lot();
    void Sko();
    void Zderz();
    void Przerwij();
    
private:
    Ptak* parent;
    virtual void update(float delta);
    Action* curAction;  
    float DlSpadku(Point up, Point down);  
};

#endif
