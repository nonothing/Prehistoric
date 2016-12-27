#ifndef __CONTROL_JOYSTICK_H__
#define __CONTROL_JOYSTICK_H__

#include "cocos2d.h"
#include "Model/IControl.h"

class ControlJoystick : public IControl
{
private:
	std::vector<cocos2d::Sprite*>	_radioButtons;
	std::vector<cocos2d::Sprite*>	_createBombButtons;
	std::vector< cocos2d::Sprite*>	_borders;
	std::vector< cocos2d::Sprite*>	_joysticks;
	std::vector<Direction>			_directions;
	std::vector<Direction>			_oldDirs;
	float							_scale;

	bool touchButton(cocos2d::Sprite* button, const cocos2d::Point& point);
	void findDirection(float angle, int index);
	void setButtonParameters(cocos2d::Sprite* button, float scale, float opacity);

public:
	static ControlJoystick* create(bool single);
	virtual bool init(bool single);

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;

	virtual void TouchBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) override;
	virtual void TouchMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) override;
	virtual void TouchEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) override;

	void setJoystickPosition(float angle, int index);

	virtual void showRadioButton(bool var) override;
	virtual void showControlPlayer(bool isVisisble) override;

};

#endif // __CONTROL_JOYSTICK_H__
