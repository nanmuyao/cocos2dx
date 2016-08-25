//
//  Person.cpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/8/22.
//
//

#include "Person.hpp"
#include "Card.hpp"
#include "ui/UIlayout.h"

using namespace cocos2d::ui;

Person::Person()
{
    
}

Person::~Person()
{
    
}

bool Person::init()
{
    
    return true;
}

void Person::playCard()
{
    
}

void Person::setData()
{
    //background
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto layout = Layout::create();
    layout->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    layout->setColor(Color3B(0,100,0));
    //layout->addTouchEventListener(CC_CALLBACK_2(SignLayer::layoutTouchEvent,this));
    layout->setTouchEnabled(true);
    layout->setContentSize(Size(visibleSize.width , visibleSize.height/2));
    this->addChild(layout);
    
    //create card
    int index = 0;
    for (Vector<Card* >::iterator iter = m_Vec_Card.begin(); iter != m_Vec_Card.end(); iter++) {
        layout->addChild(*iter);
        int width = (*iter)->getContentSize().width;
        (*iter)->setPosition(Vec2(width + width * index,
                                  (*iter)->getPositionY()));
        CCLOG("num=%d",(*iter)->cardNum);
        CCLOG("cardColor=%d",(*iter)->cardColor);
        index++;
    }
}

void Person::setCard(Card* card)
{
    m_Vec_Card.pushBack(card);
}

