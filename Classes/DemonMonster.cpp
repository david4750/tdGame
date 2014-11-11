#include "DemonMonster.h"
#include "cocos2d.h"
USING_NS_CC;
DemonMonster* DemonMonster::create()
{
	DemonMonster *monster = new DemonMonster();
	auto spriteFrameCache = SpriteFrameCache::getInstance();
	spriteFrameCache->addSpriteFramesWithFile("demon_monster_left.plist");
	monster->initWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("succubus_1.png"));
	monster->initAnimation();
	return monster;
}

void DemonMonster::initAnimation()
{
	this->leftSideAnimation = createAnimation("demon_monster_left.plist",7,0.5f);
}

Animation* DemonMonster::createAnimation(string plistFileName, int framesNum, float delay) 
{
	auto spriteFrameCache = SpriteFrameCache::getInstance();
	spriteFrameCache->addSpriteFramesWithFile(plistFileName);
	char buffer[20] = {0};
	Vector<SpriteFrame*> frames;
	for(int i = 1; i <= framesNum; i++)
	{
		sprintf(buffer,"succubus_%d.png",i);
		frames.pushBack(spriteFrameCache->getSpriteFrameByName(buffer));
	}
	return Animation::createWithSpriteFrames(frames,delay);
}