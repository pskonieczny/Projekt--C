#ifndef __Flappy__Ptak__
#define __Flappy__Ptak__

#include <cocos2d.h>

using namespace cocos2d;
typedef enum {
 
    Tap,  
    Hit, 
    Idle,
}BirdStatus;

class Ptak : public Sprite
{
public:
    Ptak();
    
    BirdStatus status;
    void tap();
    void hit();
private:
        RepeatForever* Lot();
    
};


#endif
