#include "Latanie.h"

#define Dlugosclotu 0.05
#define Wysokoscskoku 50
#define Dlugoscskoku 0.5
#define Wysladowonia 127 

Latanie::Latanie()
{
    setName("Latanie");
    curAction = NULL;
    
}

void Latanie::update(float delta)
{
    parent = (Ptak*)getOwner();
    if (parent == NULL) return;
    
	if (parent->status == Tap)
    {
        parent->status = Idle;
        AkcjaTap();
    }
}

void Latanie::AkcjaTap()
{

    StopAkcja();
    Point uppos = parent->getPosition();
    uppos.y += Wysokoscskoku;
    Point downpos = Point(uppos.x, Wysladowonia);
    float duraDown = Dlugoscspadku(uppos, downpos);
    MoveTo* moveup = MoveTo::create(Dlugoscskoku, uppos);
    RotateTo* faceup = RotateTo::create(Dlugoscskoku, -30);
    Spawn* fly = Spawn::create(faceup, EaseSineOut::create(moveup), NULL);
    MoveTo* movedown = MoveTo::create(duraDown, downpos);
    RotateTo* facedown = RotateTo::create(duraDown, 90);
    Spawn* fall = Spawn::create(facedown, EaseSineIn::create(movedown), NULL);
    Sequence* tap = Sequence::create(fly, fall, NULL);
    curAction = tap;
    parent->runAction(tap);    
}

float Latanie::Dlugoscspadku(Point up, Point down)
{
    float dy = up.y - down.y;
    float duraDown;
    if (dy <= Wysokoscskoku) duraDown = Dlugoscskoku * 1/2;
    else 
	{
        duraDown = dy * (Dlugoscskoku * 1/2) / Wysokoscskoku;
    }
    return duraDown;
}

void Latanie::AkcjaHit()
{
    Point upPos = parent->getPosition();
    parent->stopAllActions();
    Point downPos = Point(upPos.x, Wysladowonia);
    float duraDown = Dlugoscspadku(upPos, downPos) * 1/2;
    MoveTo* movedown = MoveTo::create(duraDown, downPos);
    RotateTo* facedown = RotateTo::create(duraDown, 90);
    Spawn* fall = Spawn::create(facedown, EaseSineIn::create(movedown), NULL);
    curAction = fall;
    parent->runAction(fall);
}

void Latanie::StopAkcja()
{
    if (curAction != NULL)
    {
        parent->stopAction(curAction);
        curAction = NULL;
    }
}