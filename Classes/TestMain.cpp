#include "TestMain.h"
#include <sstream>
#include <string>
#include "time.h"
USING_NS_CC;
using namespace std;
Scene* TestMain::createScene()
{
	auto scene = Scene::create();
	auto layer = TestMain::create();
	scene->addChild(layer);
	return scene;
}

bool TestMain::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	schedule(schedule_selector(TestMain::updateCustom),1.0f,kRepeatForever,0);
	playAni();
	setMillions();
	setMap();
	//setHero();
	//heroMoveTo(0);
	//setMenuItem();
	return true;
}

void TestMain::setMap()
{
	TMXTiledMap *map = TMXTiledMap::create("taohuayuan.tmx");
	this->addChild(map,0);
}

void TestMain::toOtherScene()
{
	auto otherScene = Scene::create();
	auto label = LabelTTF::create();
	label->setString("the sceond scene!!");
	label->setPosition(300,300);
	otherScene->addChild(label);

	auto transition = TransitionMoveInB::create(0.5f,otherScene);
	Director::getInstance()->replaceScene(transition);
}

void TestMain::updateCustom(float dt)
{
	log("Custom");
}


void TestMain::setMenuItem()
{
	auto menuFont = MenuItemFont::create("wanwan",[&](Ref *sender){log("wanwan Callback called!"); toOtherScene();});
	auto menuImage = MenuItemImage::create("CloseNormal.png","CloseSelected.png",[&](Ref *sender){Director::getInstance()->end();});
	auto menuToggle = MenuItemToggle::createWithCallback([&](Ref*){log("toggle touched!");},MenuItemFont::create("on"),MenuItemFont::create("off"),NULL);

	auto color_action = TintBy::create(0.5f,0,-255,-255);
	auto color_back = color_action->reverse();
	auto blink = Blink::create(0.2,100000);
	auto sequ = Sequence::create(color_action,blink,color_back,NULL);
	menuFont->runAction(RepeatForever::create(sequ));
	MenuItemFont::setFontName("Marker Felt");
	MenuItemFont::setFontSize(40);
	menuFont->setFontSize(30);
	auto menu = Menu::create(menuFont,menuImage,menuToggle,NULL);
	menu->alignItemsHorizontally();
	this->addChild(menu);
}

void TestMain::setHero()
{
	Size winsize =  Director::getInstance()->getWinSize();
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ssx.plist");
	hero = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName("daiji3_0001.png"));
	hero->setPosition(winsize.width/2,winsize.height/2);
	this->addChild(hero);
}


void TestMain::heroMoveTo(int d)
{
	float x = 200;
	// d == 0 is left , d == 1 is right
	if(d == 0)
	{
		x = -200;
	}
	auto moveby = MoveBy::create(1,Vec2(x,0));
	auto flipx = FlipX::create(true);
	auto flipy = FlipY::create(true);
	auto actionCallfunc = CallFunc::create([&](){CCLOG("actionCall");});
	hero->runAction(Repeat::create(Sequence::create(moveby,flipx,moveby->reverse(),flipx->reverse(),actionCallfunc,NULL),100));
}

void TestMain::setMillions()
{
	Size winsize =  Director::sharedDirector()->getWinSize();
	LabelTTF *timeLabel = LabelTTF::create();
	stringstream ss;
	ss << MilliSecondNow();
	printf("%s",ss.str());
	timeLabel->setString(ss.str());
	this->addChild(timeLabel,2);
	timeLabel->setPosition(winsize.width/2,winsize.height/3);
}

int TestMain::MilliSecondNow()
{
	time_t lt;
	lt = time(NULL);
	return localtime(&lt)->tm_sec;
}

void TestMain::playAni()
{
	Size winsize =  Director::getInstance()->getWinSize();
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ssx.plist");

	Vector<SpriteFrame*> frames;
	for(int i = 1; i <= 9; i++)
	{
		stringstream index;
		index << i;
		string frameName = "daiji3_000"+index.str()+".png";
		if(i >= 10) {
			frameName = "daiji3_00"+index.str()+".png";
		}
		SpriteFrame* spriteFrame = cache->getSpriteFrameByName(frameName);
		frames.pushBack(spriteFrame);
	}
	Animation *animation = Animation::createWithSpriteFrames(frames,0.1f,1);
	Sprite *sprite = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName("daiji3_0001.png"));
	sprite->setPosition(winsize.width/2,winsize.height/2);
	sprite->runAction(Speed::create(RepeatForever::create(Animate::create(animation)),9.0f));
	this->addChild(sprite,1);
}