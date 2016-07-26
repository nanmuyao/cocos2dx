//
//  LifeBody.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/7/25.
//
//

#ifndef LifeBody_hpp
#define LifeBody_hpp

#include <stdio.h>
class LifeBody
{
public:
    LifeBody(){};
    virtual ~LifeBody(){};
    virtual void dead() = 0;
    virtual void born() = 0;

private:
    int HP;
    int speed;
};
#endif /* LifeBody_hpp */
