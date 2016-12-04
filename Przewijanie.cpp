#include "Przewijanie.h"
#include "config.h"
#include "HelloWorldScene.h"

PrzewLewo::PrzewLewo(float w)
{
    setName("MoveLeft");
    this->w = w / ZiemiaP;
}

void PrzewLewo::Wpis()
{
    Akcjaruchu();
}

void PrzewLewo::update(float delta)
{
    Node* parent = (Node*)getOwner();
    if (parent == NULL) return;
    
    if ( ((HelloWorld*)parent->getParent())->GameOver )
    {
        parent->stopAllActions();
    }
    Vector<Node*> children = ((ParallaxNode*)parent)->getChildren();
    if (children.size() == 0) return;
    for (int i = 0; i < children.size(); i++)
    {
        Node* child = (Node*)children.at(i);
        Point cpos = ((ParallaxNode*)parent)->convertToWorldSpace(child->getPosition());
        if (cpos.x < -child->boundingBox().size.width)
        {
            child->unscheduleUpdate();
            child->removeFromParentAndCleanup(true);
        }
    }

}

void PrzewLewo::Akcjaruchu()
{
    Node* parent = (Node*)getOwner();
    MoveBy* moveleft = MoveBy::create(Przewwleft, Point(-w, 0));
    parent->runAction(RepeatForever::create(moveleft));
}