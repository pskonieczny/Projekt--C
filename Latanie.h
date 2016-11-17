#ifndef __Flappy__Latanie__
#define __Flappy__Latanie__

#include <cocos2d.h>
#include "Ptak.h"

using namespace cocos2d;

class Latanie : public Component
{
public:
    Latanie();
    void AkcjaTap();
	void AkcjaHit();
    void StopAkcja();
private:
    Ptak* parent;
    virtual void update(float delta); 
    Action* curAction;
    float Dlugoscspadku(Point up, Point down);
};

#endif