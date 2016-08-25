//
//  CardPool.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/8/23.
//
//

#ifndef CardPool_hpp
#define CardPool_hpp

#include <stdio.h>
#include "Card.hpp"

using namespace cocos2d;

class CardPool : public Node
{
public:
    CREATE_FUNC(CardPool);
    bool init();
    void setPool();
    void setXiPai();
    Vector<Card *>& getVecCard()
    {
        return m_Vec_Card;
    }
private:
    Vector<Card *> m_Vec_Card;
};

#endif /* CardPool_hpp */
