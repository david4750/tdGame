#include "cocos2d.h"
#include "DirectionEnum.h"
USING_NS_CC;
class MonsterBase : public Sprite
{
public:
	Animation* getMonsterAnimation(DirectionEnum direction);
	void setMonsterAnimation(Animation *ani, DirectionEnum direction);
	void runFront();
	void runBack();
	void runLeft();
	void runRight();
protected:
	Animation* rightSideAnimation;
	Animation* leftSideAnimation;
	Animation* backAnimation;
	Animation* frontAnimation;
};