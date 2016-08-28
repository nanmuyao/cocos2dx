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
    
    //添加出牌的按钮
    auto layoutButton = Layout::create();
    layoutButton->setContentSize(Size(Vec2(50,50)));
    layoutButton->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    layoutButton->setColor(Color3B(0,200,0));
    layoutButton->addTouchEventListener(CC_CALLBACK_2(Person::layoutButtonTouchEvent,this));
    layoutButton->setTouchEnabled(true);
    layoutButton->setPosition(Vec2(50, layout->getContentSize().height - layoutButton->getContentSize().height));
    layout->addChild(layoutButton);
    
    //create card
    int index = 0;
    for (Vector<Card* >::iterator iter = m_Vec_Card.begin(); iter != m_Vec_Card.end(); iter++) {
        layout->addChild(*iter);
        int width = (*iter)->getContentSize().width;
        (*iter)->setPosition(Vec2(index * 10 + width * index,
                                  (*iter)->getPositionY()));
        CCLOG("num=%d",(*iter)->cardNum);
        CCLOG("cardColor=%d",(*iter)->cardColor);
        index++;
    }
}

//玩家控制排好，还是在排中来模拟出牌呢
void Person::layoutButtonTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
    Layout* layout = static_cast<Layout*>(pSender);
    
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:
            CCLOG("%s:","BEGAN");
            break;
            
        case Widget::TouchEventType::MOVED:
            CCLOG("%s:","MOVED");
            break;
            
        case Widget::TouchEventType::ENDED:
            CCLOG("出牌");
            for (Vector<Card*>::iterator iter = m_Vec_Card.begin(); iter != m_Vec_Card.end(); iter++) {
                if ((*iter)->status == Card::card_status_chuPai) {
                    CCLOG("cardColor=%d",(*iter)->cardColor);
                    CCLOG("cardNum=%d",(*iter)->cardNum);
                    m_Vec_Card_ChuPai.pushBack(*iter);
                }
            }
            CCLOG("%s:","ENDED");
            break;
        case Widget::TouchEventType::CANCELED:
            CCLOG("%s:","MOVED");
            break;
        default:
            break;
    }

}

//玩家选牌打牌的规则
void Person::setChuPai(Card *card)
{
    m_Vec_Card_ChuPai.pushBack(card);
}

void Person::setCard(Card* card)
{
    m_Vec_Card.pushBack(card);
}

