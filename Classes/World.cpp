
//
//  World.cpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/7/25.
//
//

#include "World.hpp"
#include "CCLayer.h"
#include "ui/UIlayout.h"

using namespace cocos2d::ui;

bool World::init()
{
    createBG();
    scheduleUpdate();
    return true;
}

void World::createBG()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto layout = Layout::create();
    layout->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    layout->setColor(Color3B(255,0,0));
    //layout->addTouchEventListener(CC_CALLBACK_2(SignLayer::layoutTouchEvent,this));
    layout->setTouchEnabled(true);
    layout->setContentSize(Size(visibleSize.width - 20, visibleSize.height - 20));
    this->addChild(layout);
}

void World::update(float t)
{
    CCLOG("%s","fuck you");
}

