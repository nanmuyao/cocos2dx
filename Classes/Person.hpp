//
//  Person.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/8/22.
//
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <Card.hpp>

using namespace cocos2d;
using namespace std;

class Person : public Node
{
public:
    typedef enum _cardType
    {
        cadType_None = 0,
        cardType_Dan = 1,
        cardType_Shuang = 2,
        cardType_San = 3,
        cardType_Si_SanDaiYi = 4,
        cardType_Si_WangZha = 5,
        cardType_Wu_Lian = 6,
        cardType_Wu_SanDaiEr = 7,
        cardType_Liu_Lian = 8,
        cardType_Liu_FeiJi = 9,
        cardType_Liu_SiDaiEr = 10,
        cardType_Qi_Lian = 11,
        cardType_Ba_Lian = 12,
        cardType_Jiu_Lian = 13,
        cardType_Ten_Lian = 14,
        cardType_Eleven_Lian = 15,
        cardType_Twelve_Lian = 16,
        cardType_Thirteen_Lian = 17
    }CardType;
    Person();
    ~Person();
    CREATE_FUNC(Person);
    bool init() override;
    void showResult();
    
    void setCard(Card* card);
    void playCard();
    
    void setData();
    void getChuPai();
    bool isValid();

    void layoutButtonTouchEvent(Ref *pSender, Widget::TouchEventType type);
private:
    Vector<Card *> m_Vec_Card;
    Vector<Card *> m_Vec_Card_ChuPai;
    CardType cardType;
};

#endif /* Person_hpp */
