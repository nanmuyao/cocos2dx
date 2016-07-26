//
//  Command.hpp
//  MyAngryBird
//
//  Created by hanzhiqiang on 16/7/26.
//
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>
#include <stack>

class  Command
{
public:
    virtual void excute() = 0;
    
    virtual void moveUp() = 0;
    
    virtual void moveDown() = 0;
    
    virtual void moveLeft() = 0;
    
    virtual void moveRight() = 0;
    
    virtual void moveTo(int x, int y) = 0;
    
private:
    int x, y;
    std::stack<Command*> m_stackCommand;
};

#endif /* Command_hpp */
