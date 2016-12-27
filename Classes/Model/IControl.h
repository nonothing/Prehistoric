#ifndef __ICONTROL_H__
#define __ICONTROL_H__

#include "cocos2d.h"
#include "utils/Events.h"
#include "enumerate/Direction.h"
#include "enumerate/EControl.h"
#include "enumerate/EEventType.h"

typedef EventTempl<Direction, int>					DirectionEvent;

class IControl : public cocos2d::Node
{
protected:
	cocos2d::EventListenerTouchAllAtOnce*	_touchListener = nullptr;
	cocos2d::EventListenerKeyboard*			_keyboardListener = nullptr;

	virtual bool initTouch()
	{
		if (!cocos2d::Node::init()) return false;
		_touchListener = cocos2d::EventListenerTouchAllAtOnce::create();
		_touchListener->onTouchesBegan = CC_CALLBACK_2(IControl::TouchBegan, this);
		_touchListener->onTouchesEnded = CC_CALLBACK_2(IControl::TouchEnded, this);
		_touchListener->onTouchesMoved = CC_CALLBACK_2(IControl::TouchMoved, this);

		getEventDispatcher()->addEventListenerWithSceneGraphPriority(_touchListener, this);
		return true;
	}

	virtual bool initKeyBoard()
	{
		if (!cocos2d::Node::init()) return false;
		_keyboardListener = cocos2d::EventListenerKeyboard::create();
		_keyboardListener->onKeyPressed = CC_CALLBACK_2(IControl::onKeyPressed, this);
		_keyboardListener->onKeyReleased = CC_CALLBACK_2(IControl::onKeyReleased, this);
		getEventDispatcher()->addEventListenerWithSceneGraphPriority(_keyboardListener, this);

		return true;
	}

public:

	DirectionEvent		_eventMoveDirection;
	DirectionEvent		_eventStopDirection;
	CustomEvent			_eventCustom;

	void removeListeners()
	{
		if (_keyboardListener)	getEventDispatcher()->removeEventListener(_keyboardListener);
		if (_touchListener)		getEventDispatcher()->removeEventListener(_touchListener);
	}

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) = 0;
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) = 0;

	virtual void TouchBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) = 0;
	virtual void TouchMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) = 0;
	virtual void TouchEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) = 0;

	virtual void showRadioButton(bool var) = 0;
	virtual void showControlPlayer(bool isVisisble) = 0;

};

#endif // __ICONTROL_H__
