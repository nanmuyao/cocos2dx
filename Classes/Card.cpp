//
//  Card.cpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/8/22.
//
//

#include "Card.hpp"
Card::Card()
:layout(NULL)
,lableNum(NULL)
{
    
}
Card::~Card()
{
    
}
bool Card::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    layout = Layout::create();
    layout->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    layout->setColor(Color3B(0,255,0));
    //layout->addTouchEventListener(CC_CALLBACK_2(SignLayer::layoutTouchEvent,this));
    layout->setTouchEnabled(true);
    layout->setContentSize(Size(50, 200));
    this->setContentSize(Size(50,200));
    this->addChild(layout);
    
    lableNum = LabelTTF::create();
    lableNum->setString("12");
    lableNum->setFontSize(30);
    lableNum->setPosition(Vec2(0 + lableNum->getContentSize().width,layout->getContentSize().height - lableNum->getContentSize().height/2));
    lableNum->setColor(Color3B(0,0,255));
    layout->addChild(lableNum);
    return true;
}

void Card::setCard(int color,int num)
{
    cardNum = num;
    cardColor = color;
    std::string str = cocos2d::StringUtils::toString(num);
    lableNum->setString(str);
}

