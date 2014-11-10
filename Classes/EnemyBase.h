#include "cocos2d.h"
USING_NS_CC;
class EnemyBase : Sprite
{
protected:
	Animation* rightSideAnimation;
	Animation* leftSideAnimation;
	Animation* backAnimation;
	Animation* frontAnimation;
};