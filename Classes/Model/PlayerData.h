#ifndef __PLAYER_DATA_H__
#define __PLAYER_DATA_H__

#include "cocos2d.h"
#include "enumerate/EEventType.h"

struct PlayerData
{
public:
	cocos2d::Point	_speed;
	int				_speedCount;
	int				_life;

	CustomEvent		customEvent;
	PlayerData()
	{
		_life = 3;
	}

	void updateSpeed() 
	{
		_speed = cocos2d::Point(6, 8) + cocos2d::Point(2, 2) * _speedCount;
	}

	void updateLife()
	{
		customEvent(UPDATE_LIFE);
	}
};

#endif // __PLAYER_DATA_H__
