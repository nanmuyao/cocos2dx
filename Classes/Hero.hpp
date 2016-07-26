//
//  Hero.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/7/25.
//
//

#ifndef Hero_hpp
#define Hero_hpp

#include <stdio.h>
#include "LifeBody.hpp"

using namespace cocos2d;

class Hero : public Node , LifeBody
{
public:
    Hero()
    {
        
    };
    ~Hero()
    {
        
    };
    
    bool init();
    virtual void dead() override;
    virtual void born() override;
    CREATE_FUNC(Hero);

private:
    
};

#endif /* Hero_hpp */
