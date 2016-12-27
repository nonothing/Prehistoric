#ifndef __CONTROL_BUTTON_H__
#define __CONTROL_BUTTON_H__

#include "cocos2d.h"
#include "Model/IControl.h"

class ControlButton : public IControl
{
private:
	std::vector<cocos2d::Sprite*>	_upButtons;
	std::vector<cocos2d::Sprite*>	_downButtons;
	std::vector<cocos2d::Sprite*>	_leftButtons;
	std::vector<cocos2d::Sprite*>	_rightButtons;
	std::vector<cocos2d::Sprite*>	_createBombButtons;
	std::vector<cocos2d::Sprite*>	_radioButtons;

	std::vector<Direction>			_directions;
	std::vector<Direction>			_oldDirs;

	bool touchButton(cocos2d::Sprite* button, const cocos2d::Point& point);
	void findDirection(const cocos2d::Point& point, int index);
	void setButtonParameters(cocos2d::Sprite* button, float scale, float opacity);

public:
	static ControlButton* create();
	virtual bool init();

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;

	virtual void TouchBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) override;
	virtual void TouchMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) override;
	virtual void TouchEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* e) override;

	virtual void showRadioButton(bool var) override;

	virtual void showControlPlayer(bool isVisisble) override;


};

#endif // __CONTROL_KEYBOARD_H__
