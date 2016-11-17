#include "Petla.h"
#include "HelloWorldScene.h"

#define Szybkosc 15

Petla::Petla()
{
    setName("Petla");
    
}

void Petla::Wpisanie()
{
    Ruch();
}

void Petla::update(float delta)
{
    Node* parent = (Node*)getOwner();
    if (parent == NULL) return;
    
    if ( ((HelloWorld*)parent->getParent())->GameOver )
    {
        parent->stopAllActions();
    }
}

void Petla::Ruch()
{
    Node* parent = (Node*)getOwner();
    if (parent == NULL) return;
    float w = parent->boundingBox().size.width / Szybkosc;
    MoveBy* moveright = MoveBy::create(0, Point(w, 0));
    RepeatForever* repeat = RepeatForever::create(Sequence::create(moveright, NULL));
    
    parent->runAction(repeat);
    
}