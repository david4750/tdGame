#include "MonsterBase.h"
#include "cocos2d.h"
#include "Direction.h"
USING_NS_CC;
Animation* MonsterBase::getMonsterAnimation(Direction direction)
{
	switch(direction)
	{
	case FRONT:
		return this->frontAnimation;
	case BACK:
		return this->backAnimation;
	case LEFT:
		return this->leftSideAnimation;
	case RIGHT:
		return this->rightSideAnimation;
	}
}

void MonsterBase::setMonsterAnimation(Animation *ani ,Direction direction)
{
	switch(direction)
	{
	case FRONT:
		this->frontAnimation = ani;
		break;
	case BACK:
		this->backAnimation = ani;
		break;
	case LEFT:
		this->leftSideAnimation = ani;
		break;
	case RIGHT:
		this->rightSideAnimation = ani;
		break;
	}
}
