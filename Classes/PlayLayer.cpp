#include "cocos2d.h"
#include "PlayLayer.h"
#include <iostream>
USING_NS_CC;
using namespace std;
Scene* PlayLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayLayer::create();
	scene->addChild(layer);
	return scene;
}

bool PlayLayer::init()
{
	if(!Layer::init())
		return false;
	setMap();
	return true;
}

void PlayLayer::setMap()
{
	auto winsize = Director::getInstance()->getWinSize();
	this->map = TMXTiledMap::create("map.tmx");
	this->objects = map->getObjectGroup("obj");
	this->addChild(map,-1);
	initPointsVector();
}

void PlayLayer::initPointsVector()
{
	Node *runofPoint = NULL;
	for(int count = 0; count < objects->getObjects().size();count++)
	{
		ValueMap point =  objects->getObject(std::to_string(count));
		float x = point.at("x").asFloat();
		float y = point.at("y").asFloat();
		runofPoint = Node::create();
		runofPoint->setPosition(x,y);
		this->vectorPoint.pushBack(runofPoint);
	}	
}