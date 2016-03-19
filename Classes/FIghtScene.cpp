//
//  FIghtScene.cpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/3/19.
//
//

#include "FIghtScene.hpp"

Scene* FightScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = FightScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

