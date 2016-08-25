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
#include "ui/UIlayout.h"
using namespace cocos2d;
using namespace cocos2d::ui;

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
    Card();
    ~Card();
    CREATE_FUNC(Card);
    bool init() override;
    void setCard(int color,int num);

public:
    int cardNum;
    int cardColor;
    Layout *layout;
    LabelTTF *lableNum;
};

#endif /* Card_hpp */
