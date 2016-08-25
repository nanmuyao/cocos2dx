//
//  World.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/7/25.
//
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include "CardPool.hpp"
#include "Person.hpp"

using namespace cocos2d;

class World : public Scene
{
public:
    World();
    ~World();
    CREATE_FUNC(World);
    
    bool init() override;
    virtual void update(float dt) override;
    void createBG();
    void setCard();
    void setPerson();
    std::vector<int> getRandom(int total);
    
private:
    int sizeX;
    int sizeY;
    Layer* layer;
    CardPool *cardPool;
    Person *personA;
    Person *personB;
    Person *personC;
};

#endif /* World_hpp */


