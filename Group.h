//
//  Group.h
//  ActionTest
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef Group_h
#define Group_h



#include "GroupBase.h"





// A grouping of Actions
class Group : public GroupBase
{
    
public:
    
    Group(std::vector<SingleBase*> s) { singles = s; }
    
    
    
    void start()
    {
        for(auto&& s : singles)
        {
            s->setDelay(s->getDelay() + delay);
            
            if(looptype > LoopTypes::None) s->setLooptype(looptype);
            
            s->start();
        }
    }
    
    
    
    bool update()
    {
        for(int i = 0; i < singles.size(); i++)
        {
            singles.at(i)->update();
            
            if(singles.at(i)->isFinished() && looptype == LoopTypes::None)
            {
                delete singles.at(i); singles.at(i) = NULL;
                
                singles.erase(singles.begin() + i);
                ++i;
            }
            
            if(isFinished())
            {
                callback();
                
                return true;
            }
        }
        
        return false;
    }
};



#endif
