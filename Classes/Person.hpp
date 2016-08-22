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
#include <vector>
#include <Card.hpp>

using namespace cocos2d;

class Person : public Layer
{
public:
    CREATE_FUNC(Person);
    bool init();
    void showResult();
    
    void setCard(const Vector<Card*> &v_card);
    
    void playCard();
private:
    std::vector<Card *> m_Vec_Card;
};

#endif /* Person_hpp */
