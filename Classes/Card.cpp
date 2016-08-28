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
,lableColor(NULL)
,status(card_status_noChuPai)
,cardColor(-1)
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
    
    lableColor = LabelTTF::create();
    lableColor->setString("12");
    lableColor->setFontSize(30);
    lableColor->setPosition(Vec2(0 + lableNum->getContentSize().width,layout->getContentSize().height - lableNum->getContentSize().height/2 - lableColor->getContentSize().height));
    lableColor->setColor(Color3B(0,0,255));
    layout->addChild(lableColor);
    
    layout->addTouchEventListener(CC_CALLBACK_2(Card::layoutTouchEvent,this));
    
    return true;
}

void Card::layoutTouchEvent(Ref *pSender, Widget::TouchEventType type)
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
            //layout->setVisible(false);
            if (status == card_status_noChuPai) {
                status = card_status_chuPai;
                layout->runAction(MoveBy::create(0.2f, Vec2(layout->getPositionX(), layout->getPositionY() + 30)));
            }else if (status == card_status_chuPai){
                layout->runAction(MoveBy::create(0.2f, Vec2(layout->getPositionX(), layout->getPositionY() - 60)));
                status = card_status_noChuPai;
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

void Card::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
//    ScrollView* scv = static_cast<ScrollView*>(pSender);
//    
//    switch (type)
//    {
//        case Widget::TouchEventType::BEGAN:
//            CCLOG("%s:","BEGAN");
//            break;
//            
//        case Widget::TouchEventType::MOVED:
//            CCLOG("%s:","MOVED");
//            break;
//            
//        case Widget::TouchEventType::ENDED:
//            
//            CCLOG("%s:","ENDED");
//            
//            break;
//        case Widget::TouchEventType::CANCELED:
//            CCLOG("%s:","MOVED");
//            break;
//        default:
//            break;
//    }
}

void Card::setCard(int color,int num)
{
    cardNum = num;
    cardColor = color;
    std::string strNum = cocos2d::StringUtils::toString(num);
    std::string strColor;
    if (color == colorRed) {
        strColor = "红";
    }else if (color == colorBlack){
        strColor = "黑";
    }else if (color == colorFP){
        strColor = "方";
    }else if(color == colorHZ){
        strColor = "花";
    }else{
        assert("color not exit");
    }
    
    lableNum->setString(strNum);
    lableColor->setString(strColor);
}

