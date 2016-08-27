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
    Person();
    ~Person();
    CREATE_FUNC(Person);
    bool init() override;
    void showResult();
    
    void setCard(Card* card);
    void playCard();
    
    void setData();
    void setChuPai(Card* card);
private:
    Vector<Card *> m_Vec_Card;
    Vector<Card *> m_Vec_Card_ChuPai;
};

#endif /* Person_hpp */
