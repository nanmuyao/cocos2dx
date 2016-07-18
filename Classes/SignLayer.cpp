//
//  SignLayer.cpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/7/16.
//
//

#include "SignLayer.hpp"
#include "CCLayer.h"
using namespace cocos2d::ui;

bool SignLayer::init()
{
    this->setSCV();
    this->setData();
    return true;
}

Layout* SignLayer::createItem()
{
    auto layout = Layout::create();
    layout->setContentSize(Size(Vec2(100,100)));
    layout->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    layout->setColor(Color3B(255,0,0));
    layout->addTouchEventListener(CC_CALLBACK_2(SignLayer::layoutTouchEvent,this));
    layout->setTouchEnabled(true);
    return layout;
}

void SignLayer::setSCV()
{
    Size widgetSize = this->getContentSize();
    m_Scv= ui::ScrollView::create();
    m_Scv->setContentSize(Size(400.0f, 400.0f));
    Size backgroundSize = widgetSize;
    m_Scv->setPosition(Vec2((widgetSize.width - backgroundSize.width) / 2.0f +
                                 (backgroundSize.width - m_Scv->getContentSize().width) / 2.0f,
                                 (widgetSize.height - backgroundSize.height) / 2.0f +
                                 (backgroundSize.height - m_Scv->getContentSize().height) / 2.0f));
    m_Scv->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    m_Scv->setBackGroundColor(Color3B(0,255,0));
    m_Scv->setBounceEnabled(true);
    m_Scv->setTouchEnabled(true);
    m_Scv->setInnerContainerSize(Size(800,400));
    m_Scv->setDirection(cocos2d::ui::ScrollView::Direction::HORIZONTAL);
    m_Scv->addTouchEventListener(CC_CALLBACK_2(SignLayer::touchEvent, this));
    this->addChild(m_Scv);
}


void SignLayer::layoutTouchEvent(Ref *pSender, Widget::TouchEventType type)
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
            layout->setVisible(false);
            CCLOG("%s:","ENDED");
            
            break;
        case Widget::TouchEventType::CANCELED:
            CCLOG("%s:","MOVED");
            break;
        default:
            break;
    }
}

void SignLayer::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
    ScrollView* scv = static_cast<ScrollView*>(pSender);
    
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:
            CCLOG("%s:","BEGAN");
            break;
            
        case Widget::TouchEventType::MOVED:
            CCLOG("%s:","MOVED");
            break;
            
        case Widget::TouchEventType::ENDED:
            
            CCLOG("%s:","ENDED");
        
            break;
        case Widget::TouchEventType::CANCELED:
            CCLOG("%s:","MOVED");
            break;
        default:
            break;
    }
}

void SignLayer::setData()
{
    if(m_Scv != NULL)
    {
        for (int i = 0; i<10; i++) {
            Layout *layout = this->createItem();
            layout->setPosition(Vec2(layout->getContentSize().width * i + 10 * i, layout->getPositionY()));
//            CCLOG("POSX%d:",layout->getPositionX() * i);
            m_Scv->addChild(layout);
            //free(layout);
        }
        Layout *layout = this->createItem();
        m_Scv->setInnerContainerSize(Size(layout->getContentSize().width * 20 + 10 * 10, layout->getPositionY()));
    }
}

