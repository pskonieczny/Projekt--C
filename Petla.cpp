#include "Petla.h"
#include "config.h"
#include "HelloWorldScene.h"

Petla::Petla()
{
    setName("MoveLoop");
    
}

void Petla::Wejscie()
{
    AkcjaRuch();
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

void Petla::AkcjaRuch()
{
    Node* parent = (Node*)getOwner();
    if (parent == NULL) return;
    float w = parent->boundingBox().size.width / ZiemiaP;
    MoveBy* moveleft = MoveBy::create(Przewwleft, Point(-w, 0));
    MoveBy* moveright = MoveBy::create(0, Point(w, 0));
    RepeatForever* repeat = RepeatForever::create(Sequence::create(moveleft, moveright, NULL));
        parent->runAction(repeat);
    
}