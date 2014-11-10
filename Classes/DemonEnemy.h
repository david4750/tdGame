#include "EnemyBase.h"
#include "Direction.h"

USING_NS_CC;
class DemonEnemy : EnemyBase
{
public:
	Animation* enemyAnimation(Direction direction);
	void setAnimation(Animation *ani, Direction direction);
};