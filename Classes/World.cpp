
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

vector<int> getRandom(int total)
{
    srand((int)time(NULL));
    std::vector<int> input = *new std::vector<int>();
    for (int i = 0; i < total; i++) {
        input.push_back(i);
    }
    vector<int> output = *new vector<int>();
    
    int end = total;
    for (int i = 0; i < total; i++) {
        vector<int>::iterator iter = input.begin();
        int num = rand()%end;
        iter = iter+num;
        output.push_back(*iter);
        input.erase(iter);
        end--;
    }
    
    return output;
}

void World::setPerson()
{

    
    Person *personA = Person::create();
    Person *personB = Person::create();
    Person *personC = Person::create();
}

void World::update(float t)
{
    //CCLOG("%s","fuck you");
}

