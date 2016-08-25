
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
#include "Person.hpp"
#include "stdlib.h"

using namespace cocos2d::ui;

World::World()
:cardPool(NULL)
,personA(NULL)
,personB(NULL)
,personC(NULL)
{
    
}

World::~World()
{
    
}

bool World::init()
{
    createBG();
    scheduleUpdate();
    setCard();
    setPerson();
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

void World::setCard()
{
//    auto card = Card::create();
//    card->setAnchorPoint(Vec2(0.0f, 0.0f));
//    card->setPosition(100, 100);
//    this->addChild(card);
    cardPool = CardPool::create();
}

void World::setPerson()
{
    personA = Person::create();
    personB = Person::create();
    personC = Person::create();
    //发牌
    Vector<Card*> vecCard = cardPool->getVecCard();
    for (int i = 0; i < 52; i++) {
        if (i%3==0) {
            personA->setCard(vecCard.at(i));
        }else if (i%3 == 1)
        {
            personB->setCard(vecCard.at(i));
        }else if(i%3 == 2)
        {
            personC->setCard(vecCard.at(i));
        }
    }
    
    //显示扑克牌
    personA->setData();
    this->addChild(personA);
}

void World::update(float t)
{
    //CCLOG("%s","fuck you");
}

