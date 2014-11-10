#include "DemonEnemy.h"
USING_NS_CC;
Animation* DemonEnemy::enemyAnimation(Direction direction)
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

