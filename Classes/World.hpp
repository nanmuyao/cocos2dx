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
using namespace cocos2d;

class World : public Scene
{
public:
    World(){};
    ~World(){};
    CREATE_FUNC(World);
    
    bool init();
    virtual void update(float dt) override;
    void createBG();
    void setCard();
    void setPerson();
private:
    int sizeX;
    int sizeY;
    Layer* layer;
};

#endif /* World_hpp */


