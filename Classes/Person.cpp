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
:cardType(cadType_None)
{
    
}

Person::~Person()
{
    
}

bool Person::init()
{
    //background
    Size visibleSize = Director::getInstance()->getVisibleSize();
    layoutbg = Layout::create();
    layoutbg->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    layoutbg->setColor(Color3B(0,100,0));
    //layout->addTouchEventListener(CC_CALLBACK_2(SignLayer::layoutTouchEvent,this));
    layoutbg->setTouchEnabled(true);
    layoutbg->setContentSize(Size(visibleSize.width , visibleSize.height/2));
    this->addChild(layoutbg);
    
    //添加出牌的按钮
    auto layoutButton = Layout::create();
    layoutButton->setContentSize(Size(Vec2(50,50)));
    layoutButton->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    layoutButton->setColor(Color3B(0,200,0));
    layoutButton->addTouchEventListener(CC_CALLBACK_2(Person::layoutButtonTouchEvent,this));
    layoutButton->setTouchEnabled(true);
    layoutButton->setPosition(Vec2(50, layoutbg->getContentSize().height - layoutButton->getContentSize().height));
    this->addChild(layoutButton);
    return true;
}

bool Person::isValid()
{
    //check card type
    int cardNum1 = 0;
    int cardNum2 = 0;
    int cardNum3 = 0;
    int cardNum4 = 0;
    int cardNum5 = 0;
    int cardNum6 = 0;
    int cardNum7 = 0;
    int cardNum8 = 0;
    int cardNum9 = 0;
    int cardNum10 = 0;
    int cardNum11 = 0;
    int cardNum12 = 0;
    int cardNum13 = 0;

    int cardSize = m_Vec_Card_ChuPai.size();
//    for(Vector<Card *>::iterator iter = m_Vec_Card_ChuPai.begin();iter != m_Vec_Card_ChuPai.end();iter++)
//    {
//        cardSize++;
//    }
    if (cardSize==1) {
        cardType = cardType_Dan;
        return true;
    }
    
    if(cardSize == 2)
    {
        if (m_Vec_Card_ChuPai.at(0)->cardNum == m_Vec_Card_ChuPai.at(1)->cardNum) {
            cardType = cardType_Shuang;
            return true;
        }
    }
    //三张牌如果玩家手里已经没有牌了事可以出的
    if(cardSize == 3)
    {
        if (m_Vec_Card_ChuPai.at(0)->cardNum == m_Vec_Card_ChuPai.at(1)->cardNum == m_Vec_Card_ChuPai.at(2)->cardNum)
        {
            cardType = cardType_San;
            return true;
        }
    }
    
    //四张牌 王炸 三代一
    if(cardSize == 4)
    {
        if (m_Vec_Card_ChuPai.at(0)->cardNum == m_Vec_Card_ChuPai.at(1)->cardNum == m_Vec_Card_ChuPai.at(2)->cardNum)
        {
            cardType = cardType_Si_SanDaiYi;
            if (m_Vec_Card_ChuPai.at(4) == m_Vec_Card_ChuPai.at(0)) {
                cardType = cardType_Si_WangZha;
            }
            return true;
        }
        
    }
    
    //后续牌型的判断
    if(cardSize == 5)
    {
        cardNum1 = m_Vec_Card_ChuPai.at(0)->cardNum;
        cardNum2 = m_Vec_Card_ChuPai.at(1)->cardNum;
        cardNum3 = m_Vec_Card_ChuPai.at(2)->cardNum;
        cardNum4 = m_Vec_Card_ChuPai.at(3)->cardNum;
        cardNum5 = m_Vec_Card_ChuPai.at(4)->cardNum;
        
        if ((cardNum2 - cardNum1 ==1)&&(cardNum3 - cardNum2 ==1)&&(cardNum4 - cardNum3 ==1)&&(cardNum5 - cardNum4 ==1)) {
            
            return true;
        }
    }
    
    
    
    return false;
}

void Person::playCard()
{
    if (isValid())
    {

        for(Vector<Card *>::iterator iter = m_Vec_Card_ChuPai.begin(); iter != m_Vec_Card_ChuPai.end();iter++)
        {
            for(Vector<Card *>::iterator iterCard = m_Vec_Card.begin(); iterCard != m_Vec_Card.end();iterCard++)
            {
                if ((*iter)->cardNum == (*iterCard)->cardNum && (*iter)->cardColor == (*iterCard)->cardColor)
                {
                    m_Vec_Card.erase(iterCard);
                    break;
                }
            }
        }
        
    }else
    {
        CCLOG("no can play card");
    }
    setData();
}

void Person::setData()
{
    layoutbg->removeAllChildren();
    
    //对牌进行排序
    struct myclass {
        bool operator() (Card *card1, Card *card2) { return (card1->cardNum<card2->cardNum); }
    } myobject;
    
    // using object as comp
    std::sort(m_Vec_Card.begin(), m_Vec_Card.end(), myobject);
    
    //create card
    int index = 0;
    for (Vector<Card* >::iterator iter = m_Vec_Card.begin(); iter != m_Vec_Card.end(); iter++) {
        layoutbg->addChild(*iter);
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
    CCLOG("Test");
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
            CCLOG("出牌");
            
            getChuPai();
            playCard();
            
            break;
        case Widget::TouchEventType::CANCELED:
            CCLOG("%s:","MOVED");
            break;
        default:
            break;
    }
}

//玩家选牌打牌的规则
void Person::getChuPai()
{
    m_Vec_Card_ChuPai.clear();
    for (Vector<Card*>::iterator iter = m_Vec_Card.begin(); iter != m_Vec_Card.end(); iter++) {
        if ((*iter)->status == Card::card_status_chuPai) {
            CCLOG("cardColor=%d",(*iter)->cardColor);
            CCLOG("cardNum=%d",(*iter)->cardNum);
            m_Vec_Card_ChuPai.pushBack(*iter);
        }
    }
}

void Person::setCard(Card* card)
{
    m_Vec_Card.pushBack(card);
}

