#include "cocos2d.h";
#include "string.h"
USING_NS_CC;
class TestMain : public cocos2d::Layer
{
public:
	Sprite *hero;
	static cocos2d::Scene* createScene();
	virtual bool init();
	void playAni();
	int MilliSecondNow();
	void setMillions();
	void heroMoveTo(int);
	void setHero();
	void setMenuItem();
	void updateCustom(float dt);
	void toOtherScene();
	void setMap();
	CREATE_FUNC(TestMain);
};


