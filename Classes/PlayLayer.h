#ifndef __PLAYLAYER_LAYER_H__
#define __PLAYLAYER_LAYER_H__
#include "cocos2d.h"
USING_NS_CC;
class PlayLayer : public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(PlayLayer);
private:
	TMXTiledMap *map;
	TMXObjectGroup *objects;
	void setMap();
	void initPointsVector();
	Vector<Node*> vectorPoint;
};
#endif