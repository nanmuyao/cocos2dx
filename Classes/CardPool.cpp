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
    
    return true;
}

void CardPool::setPool()
{

    int color = 0;
    for (int i = 1; i <= MaxCardNum; i++) {
        auto *card = Card::create();
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
        if (card == 0) {
            cardNum = i;
        }
        card->setCard(color, cardNum);
        m_Vec_Card.pushBack(card);
    }
}
