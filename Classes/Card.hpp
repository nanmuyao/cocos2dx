//
//  Card.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/8/22.
//
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
using namespace cocos2d;

enum CardColr
{
    colorRed = 1,
    colorBlack = 2,
    colorFP = 3,
    colorHZ = 4
};

class Card : public CCLayer
{
public:
    CREATE_FUNC(Card);
    bool init() override;
    void setCard(int color,int num);

public:
    int cardNum;
    int cardColor;
};

#endif /* Card_hpp */
