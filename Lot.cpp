#include "Lot.h"
#include "config.h"

Lot::Lot()
{
    setName("Flying");
    curAction = NULL;
}

void Lot::update(float delta)
{
    parent = (Ptak*)getOwner();
    if (parent == NULL) return;
    
    if (parent->status == Dead)
    {
        return;
    }
    else if (parent->status == Jump)
    {
        parent->status = Jump;
        Sko();
    }
    else if (parent->status == Uderz)
    {
        parent->status = Dead;
        Zderz();
    }
}

void Lot::Sko()
{
    Przerwij();
    Point uppos = parent->getPosition();
    uppos.y += Wys;
    Point downpos = Point(uppos.x, Wysspadania);
    float duraDown = DlSpadku(uppos, downpos);
    MoveTo* moveup = MoveTo::create(Dlot, uppos);
    RotateTo* faceup = RotateTo::create(Dlot, -30);
    Spawn* fly = Spawn::create(faceup, EaseSineOut::create(moveup), NULL);
    MoveTo* movedown = MoveTo::create(duraDown, downpos);
    RotateTo* facedown = RotateTo::create(duraDown, 90);
    Spawn* fall = Spawn::create(facedown, EaseSineIn::create(movedown), NULL);
    Sequence* tap = Sequence::create(fly, fall, NULL);
    curAction = tap;
    parent->runAction(tap);
    
}

float Lot::DlSpadku(Point up, Point down)
{
    float dy = up.y - down.y;
    float Dlsp;
    if (dy <= Wys) Dlsp = Dlot * 1/2;
    else
    {
        Dlsp = dy * (Dlot * 1/2) / Wys;
    }
    
    return Dlsp;
}

void Lot::Zderz()
{
    Point upPos = parent->getPosition();
    parent->stopAllActions();
    Point downPos = Point(upPos.x, Wysspadania);
    float duraDown = DlSpadku(upPos, downPos) * 1/2;
    MoveTo* movedown = MoveTo::create(duraDown, downPos);
    RotateTo* facedown = RotateTo::create(duraDown, 90);
    Spawn* fall = Spawn::create(facedown, EaseSineIn::create(movedown), NULL);
    curAction = fall;
    parent->runAction(fall);
}

void Lot::Przerwij()
{
    if (curAction != NULL)
    {
        parent->stopAction(curAction);
        curAction = NULL;
    }
}



