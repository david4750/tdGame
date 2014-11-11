#include "MonsterBase.h"
#include "Direction.h"

USING_NS_CC;
class DemonMonster : MonsterBase
{
public:
	Animation* enemyAnimation(Direction direction);
	void setAnimation(Animation *ani, Direction direction);
};