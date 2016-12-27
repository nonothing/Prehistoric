#ifndef __WORLD_SCENE_H__
#define __WORLD_SCENE_H__

#include "cocos2d.h"
#include "Model/Player.h"
#include "enumerate/EControl.h"
#include "enumerate/Direction.h"
#include "Model/IControl.h"
#include "ui/UIText.h"
#include "editor-support/cocostudio/CocoStudio.h"

class WorldScene : public cocos2d::Layer
{
private:
	IControl*				_control;
	Player*					_player;
	cocos2d::Layer*			_mapLayer;

	DirectionEvent::Listener			_directionMoveListener;
	DirectionEvent::Listener			_directionStopListener;
	CustomEvent::Listener				_customListener;

	void updateMoveDirection(Direction dir);
	void updateStopDirection(Direction dir);
	void updateCustomEvent(EEventType type);
	void initMap();
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(WorldScene);
	void createControll(EControl type);
};

#endif // __WORLD_SCENE_H__
