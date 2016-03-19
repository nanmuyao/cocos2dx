//
//  FIghtScene.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/3/19.
//
//

#ifndef FIghtScene_hpp
#define FIghtScene_hpp
#include "cocos2d.h"
#include <stdio.h>

using namespace cocos2d;

class FightScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(FightScene);
};

#endif /* FIghtScene_hpp */
