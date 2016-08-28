//
//  CardPool.cpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/8/23.
//
//

#include "CardPool.hpp"
#include "Card.hpp"

// 牌的出现 花色数字
#define MaxCardNum 52

bool CardPool::init()
{
    setPool();
    setXiPai();
    return true;
}

void CardPool::setPool()
{
    int color = 0;
    int index = 0;
    for (int i = 1; i <= 54; i++)
    {
        Card *card = Card::create();
        index = i/13 + 1; // 1/13 = 0; 13/13 = 0;  14/13 = 1;
        if (i == 13)
        {
            index = 1;
        }else if (i == 26)
        {
            index = 2;
        }else if (i == 39)
        {
            index = 3;
        }else if (i == 52)
        {
            index = 4;
        }
        
        switch (index)
        {
            case Card::colorRed:
                color = Card::colorRed;
                break;
            case Card::colorBlack:
                color = Card::colorBlack;
                break;
            case Card::colorFP:
                color = Card::colorFP;
                break;
            case Card::colorHZ:
                color = Card::colorHZ;
                break;
            default:
                CCLOG("set color error");
                break;
        }

        int cardNum = i%13;
        int tmpIndex = 0;
        if (cardNum == 0) {
            cardNum = 13;
        }
        
        if (i == 53) {
            color = Card::colorXW;
            cardNum = 53;
        }else if (i == 54){
            color = Card::colorDW;
            cardNum = 54;
        }
        
        CCLOG("color=%d",color);
        CCLOG("cardNum=%d",cardNum);
        card->setCard(color, cardNum);
        m_Vec_Card.pushBack(card);
    }

    
}

void CardPool::setXiPai()
{
    //洗牌实现随机
    int rand1 = 0;
    int rand2 = 0;
    
    for (int i = 0; i<120; i++) {
        rand1 = random(0, 51);
        rand2 = random(0, 50) + 1;
        if(rand1 != rand2)
            m_Vec_Card.swap(m_Vec_Card.at(rand1), m_Vec_Card.at(rand2));
    }
    
    for (Vector<Card* >::iterator iter = m_Vec_Card.begin(); iter != m_Vec_Card.end(); iter++) {
        Card *card = *iter;
//        CCLOG("num=%d",card->cardNum);
//        CCLOG("cardColor=%d",card->cardColor);
    }
}
