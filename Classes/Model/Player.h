#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "enumerate/Direction.h"
#include "Model/WorldObject.h"
#include "Model/PlayerData.h"
#include "utils/Events.h"

class Player : public WorldObject
{
private:
	PlayerData			_data;

	Direction			_dir;
	Direction			_animDir;
	
	bool				_isDead;
	bool				_isDestroy;
	bool				_isStop;
	cocos2d::Layer*		_mapLayer;

	cocos2d::Point		getOffsetToDir();
	void move();
	bool nextMove();
	void animate(Direction dir);
	bool isCollision(const cocos2d::Point& point);
	void moveMap(const cocos2d::Point& point);
	bool isMapMove(const cocos2d::Point& point);
	void destroy();
public:
	cocos2d::Vector<Node*> _collisions;
    virtual bool init(cocos2d::Layer* layer);

	void loadParametrs();

	static Player* create(cocos2d::Layer* layer);
	void setDirection(Direction dir);
	Direction getDirection();
	Direction getAnimDirection();
	virtual void update(float dt) override;
	int  getLife();
	bool isDestroy();
	void dead();
	void stopMove();
	bool isStop();
	PlayerData getData();
	CustomEvent& getEvent();
	virtual cocos2d::Rect getRect() override;
};

#endif // __PLAYER_H__
