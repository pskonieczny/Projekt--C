#ifndef __FlappyBird__Bird__
#define __FlappyBird__Bird__
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
typedef enum {
 
    Jump,
    Dead,
    Uderz,
    Bezczyn,
    
}BirdStatus;

class Ptak : public Sprite
{
public:
    Ptak();
    
    BirdStatus status;
    void Skok();
    void hitMe();
private:
    RepeatForever* Latanie();
    
};
#endif
