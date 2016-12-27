#include "Model/GameSettings.h"
#include "utils/Utils.h"

#define RECORD_KEY "record"
#define PLAYER_LIFE_KEY "playerLife"
#define SPEED_KEY "speed"
#define CONTROL_KEY "control"
#define SCALE_BUTTON_KEY "buttonScale"
#define OPACITY_BUTTON_KEY "buttonOpacity"
#define MUSIC_KEY "music"
#define BUTTON_POS_SINGLE_KEY "button_single_id_"
#define BUTTON_POS_KEY "button_id_"

USING_NS_CC;

GameSettings::GameSettings()
{
}

GameSettings::~GameSettings()
{
}

void GameSettings::saveRecord(int value)
{
	UserDefault::getInstance()->setIntegerForKey(RECORD_KEY, value);
	UserDefault::getInstance()->flush();
}

int GameSettings::getRecord() const
{
	return UserDefault::getInstance()->getIntegerForKey(RECORD_KEY, 0);
}

void GameSettings::setScaleButtons(float scale)
{
	UserDefault::getInstance()->setFloatForKey(SCALE_BUTTON_KEY, scale);
	UserDefault::getInstance()->flush();
}

float GameSettings::getScaleButtons()
{
	return UserDefault::getInstance()->getFloatForKey(SCALE_BUTTON_KEY, 2.f);
}

void GameSettings::setOpacityButtons(float opacity)
{
	UserDefault::getInstance()->setFloatForKey(OPACITY_BUTTON_KEY, opacity);
	UserDefault::getInstance()->flush();
}

float GameSettings::getOpacityButtons()
{
	return UserDefault::getInstance()->getFloatForKey(OPACITY_BUTTON_KEY, 255.f);
}

bool GameSettings::isMusic()
{
	return UserDefault::getInstance()->getBoolForKey(MUSIC_KEY, true);
}

void GameSettings::setMusic(bool value)
{
	UserDefault::getInstance()->setBoolForKey(MUSIC_KEY, value);
	UserDefault::getInstance()->flush();
}

void GameSettings::saveButtonPosition(cocos2d::Sprite* button)
{
	std::string value = myUtils::to_string(button->getPositionX()) + "@" + myUtils::to_string(button->getPositionY());
	std::string key = BUTTON_POS_KEY + myUtils::to_string(button->getTag());
	UserDefault::getInstance()->setStringForKey(key.c_str(), value);
	UserDefault::getInstance()->flush();
}

Point GameSettings::getPosition(size_t tag)
{
	std::string key = BUTTON_POS_KEY + myUtils::to_string(tag);
	std::string result = UserDefault::getInstance()->getStringForKey(key.c_str(), "");
	if (result.empty())
	{
		return Point::ZERO;
	}
	else
	{
		std::vector<std::string> vec = myUtils::split(result, '@');
		return Point(atof(vec.at(0).c_str()), atof(vec.at(1).c_str()));
	}
}

EControl GameSettings::getControlType()
{
	int result = UserDefault::getInstance()->getIntegerForKey(CONTROL_KEY, 0);
	if(result == 0)
	{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		result = (int)EBUTTON;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        result = (int)EJOYSTICK;
#else
		result = (int)EKEYBOARD;
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
}
	return EControl(result);
}

void GameSettings::saveControlType(EControl type)
{
	UserDefault::getInstance()->setIntegerForKey(CONTROL_KEY, (int)type);
	UserDefault::getInstance()->flush();
}

void GameSettings::savePlayer(const PlayerData& data)
{
	UserDefault::getInstance()->setIntegerForKey(PLAYER_LIFE_KEY, data._life);
	UserDefault::getInstance()->setIntegerForKey(SPEED_KEY, data._speedCount);
	UserDefault::getInstance()->flush();
}

void GameSettings::loadPlayerData(PlayerData& data)
{
	data._speedCount = UserDefault::getInstance()->getIntegerForKey(SPEED_KEY, 0);
	data._life = UserDefault::getInstance()->getIntegerForKey(PLAYER_LIFE_KEY, 0);
	data.updateSpeed();
}

void GameSettings::setPlayerLife(int value)
{
	UserDefault::getInstance()->setIntegerForKey(PLAYER_LIFE_KEY, value);
	UserDefault::getInstance()->flush();
}

void GameSettings::setDefaulPlayer()
{
	UserDefault::getInstance()->setIntegerForKey(PLAYER_LIFE_KEY, 3);
	UserDefault::getInstance()->setIntegerForKey(SPEED_KEY, 0);
	UserDefault::getInstance()->flush();
}

void GameSettings::setParametersPlayer(int sizeBomb, int countBomb, int speed)
{
	setDefaulPlayer();
	UserDefault::getInstance()->setIntegerForKey(SPEED_KEY, speed);
}

int GameSettings::getPlayerLife()
{
	return UserDefault::getInstance()->getIntegerForKey(PLAYER_LIFE_KEY, 0);
}
