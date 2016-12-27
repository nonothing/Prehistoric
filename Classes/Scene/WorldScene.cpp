#include "WorldScene.h"
#include "SimpleAudioEngine.h"

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
    
    return true;
}

