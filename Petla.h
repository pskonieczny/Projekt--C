#ifndef __Flappy__Petla__
#define __Flappy__Petla__

#include <cocos2d.h>

using namespace cocos2d;

class Petla : public Component
{
public:
    Petla();
private:
    virtual void Wpisanie();
    virtual void update(float delta);
    
    void Ruch();
};

#endif
