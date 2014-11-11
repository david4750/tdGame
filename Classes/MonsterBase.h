#include "cocos2d.h"
#include "Direction.h"
USING_NS_CC;
class MonsterBase : Sprite
{
public:
	Animation* getMonsterAnimation(Direction direction);
	void setMonsterAnimation(Animation *ani, Direction direction);
protected:
	Animation* rightSideAnimation;
	Animation* leftSideAnimation;
	Animation* backAnimation;
	Animation* frontAnimation;
};