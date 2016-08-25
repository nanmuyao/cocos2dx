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
    for (int i = 1; i <= MaxCardNum; i++) {
        Card *card = Card::create();
        int index = i/13;
        if (index == 0)
            index +=1;
        switch (index) {
            case colorRed:
                color = colorRed;
                break;
            case colorBlack:
                color = colorBlack;
                break;
            case colorFP:
                color = colorFP;
                break;
            case colorHZ:
                color = colorHZ;
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

//        CCLOG("color=%d",color);
//        CCLOG("cardNum=%d",cardNum);
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
