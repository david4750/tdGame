#include "MonsterBase.h"
#include "cocos2d.h"
#include "DirectionEnum.h"
USING_NS_CC;

Animation* MonsterBase::getMonsterAnimation(DirectionEnum direction)
{
	switch(direction)
	{
	case 0:
		return this->frontAnimation;
	case 1:
		return this->backAnimation;
	case 2:
		return this->leftSideAnimation;
	case 3:
		return this->rightSideAnimation;
	}
}

void MonsterBase::setMonsterAnimation(Animation *ani ,DirectionEnum direction)
{
	switch(direction)
	{
	case 0:
		this->frontAnimation = ani;
		break;
	case 1:
		this->backAnimation = ani;
		break;
	case 2:
		this->leftSideAnimation = ani;
		break;
	case 3:
		this->rightSideAnimation = ani;
		break;
	}
}

void MonsterBase::runLeft()
{
	Animate *animate = Animate::create(this->leftSideAnimation);
	this->runAction(RepeatForever::create(animate));
}
