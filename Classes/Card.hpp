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

class Card : public CCLayer
{
public:
    
    enum CardColr
    {
        colorRed = 1,
        colorBlack = 2,
        colorFP = 3,
        colorHZ = 4,
        colorXW = 5,
        colorDW = 6
    };
    
    typedef enum _CardStatus
    {
        card_status_None = 1,
        card_status_chuPai = 2,
        card_status_noChuPai = 3
    }CardStatus;
    
    Card();
    ~Card();
    CREATE_FUNC(Card);
    bool init() override;
    void setCard(int color,int num);

    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void layoutTouchEvent(Ref *pSender, Widget::TouchEventType type);
public:
    int cardNum;
    int cardColor;
    Layout *layout;
    LabelTTF *lableNum;
    LabelTTF *lableColor;
    CardStatus status;
};

#endif /* Card_hpp */
