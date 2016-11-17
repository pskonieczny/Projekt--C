#include "Ptak.h"
#include "HelloWorldScene.h"

Ptak::Ptak()
{
    initWithSpriteFrameName("bird1.png");
    this->runAction(Lot());
    status = Idle;
}

RepeatForever* Ptak::Lot()
{
    int numframe = 3;
    Vector<SpriteFrame*> animFrames;
    char str[100] = {0};
    for(int i = 0; i < numframe; i++)
    {
        sprintf(str, "bird%d.png", i+1);
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.05);
    Animate* animate = Animate::create(animation);
    
    return RepeatForever::create(animate);
}

void Ptak::tap() {

    status = Tap;  
}

void Ptak::hit()
{
	status = Hit;
	((HelloWorld*)getParent())->GameOver = true;
}