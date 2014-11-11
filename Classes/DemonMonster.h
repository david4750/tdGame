#include "MonsterBase.h"
#include "DirectionEnum.h"
#include "string.h"

using namespace std;
USING_NS_CC;

class DemonMonster : public MonsterBase
{
public:
	void initAnimation();
	Animation* createAnimation(string plistFileName, int framesNum, float delay);
	static DemonMonster *create();
};

