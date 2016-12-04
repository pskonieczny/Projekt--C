#include "Ptak.h"
#include "config.h"
#include "HelloWorldScene.h"

Ptak::Ptak()
{
    initWithSpriteFrameName("bird1.png");
    this->runAction(Latanie());
	status = Bezczyn;
    
}

RepeatForever* Ptak::Latanie()
{
    int a = 3;
    Vector<SpriteFrame*> animFrames;
    char str[100] = {0};
    for(int i = 0; i < a; i++)
    {
        sprintf(str, "bird%d.png", i+1);
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.05);
    Animate* animate = Animate::create(animation);
    return RepeatForever::create(animate);
}

void Ptak::Skok() {

    status = Jump;
   
}

void Ptak::hitMe()
{
    status = Uderz;
    
    ((HelloWorld*)getParent())->GameOver = true;
    
}

