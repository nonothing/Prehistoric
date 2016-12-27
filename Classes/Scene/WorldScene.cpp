#include "WorldScene.h"
#include "SimpleAudioEngine.h"
#include "Model/ControlKeyBoard.h"
#include "Model/ControlButton.h"
#include "Model/ControlJoystick.h"
USING_NS_CC;

Scene* WorldScene::createScene()
{
    auto scene = Scene::create();
    auto layer = WorldScene::create();
    scene->addChild(layer);
    return scene;
}

bool WorldScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	initMap();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("plists/human.plist", "atlas/human.png");
//	AnimationCache::getInstance()->addAnimationsWithFile("animation/players.plist");

	_mapLayer = Layer::create();
	_player = Player::create(_mapLayer);
	_player->setPosition(Director::getInstance()->getWinSize() / 2);

	addChild(_mapLayer);
	addChild(_player);

	createControll(EKEYBOARD);
    
    return true;
}

void WorldScene::initMap()
{
	auto map = CSLoader::createNode("Level_1.csb");
	addChild(map);
}

void WorldScene::createControll(EControl type)
{
	if (type == EJOYSTICK)
	{
		_control = ControlJoystick::create();
	}
	else if (type == EBUTTON)
	{
		_control = ControlButton::create();
	}
	else
	{
		_control = ControlKeyBoard::create();
	}

	_directionMoveListener.set(_control->_eventMoveDirection, std::bind(&WorldScene::updateMoveDirection, this, std::placeholders::_1));
	_directionStopListener.set(_control->_eventStopDirection, std::bind(&WorldScene::updateStopDirection, this, std::placeholders::_1));
	_customListener.set(std::bind(&WorldScene::updateCustomEvent, this, std::placeholders::_1));
	_customListener += _control->_eventCustom;


	_customListener += _player->getEvent();
	

	addChild(_control, 11);
}

void WorldScene::updateMoveDirection(Direction dir)
{
	if (dir != NONE)
	{
		_player->setDirection(dir);
	}
}

void WorldScene::updateStopDirection(Direction dir)
{
	if (_player->getDirection() == dir)
	{
		_player->setDirection(NONE);
	}
}

void WorldScene::updateCustomEvent(EEventType type)
{
		switch (type)
		{
// 		case ECREATEBOMB:	createBomb(player);			break;
// 		case EEXPLODE:		explodeBomb(player);		break;
// 		case EPAUSE:		onPause();					break;
// 		case EQUIT:			backMenu();					break;
// 		case UPDATE_LIFE:	updateLifeLabel();			break;
		default:
			break;
		}
}



