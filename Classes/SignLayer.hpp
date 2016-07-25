//
//  SignLayer.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/7/16.
//
//

#ifndef SignLayer_hpp
#define SignLayer_hpp

#include <stdio.h>
#include "ui/UIScrollView.h"


using namespace cocos2d;
using namespace cocos2d::ui;

class SignLayer : public Node
{
public:
    void test();
    SignLayer(){};
    ~SignLayer(){};
    CREATE_FUNC(SignLayer);
    
    bool init();
    void setSCV();
    
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void layoutTouchEvent(Ref *pSender, Widget::TouchEventType type);
    
    Layout* createItem();
    void setData();
private:
    ScrollView *m_Scv;
    //    TableView tableView;
    
};

#endif /* SignLayer_hpp */


