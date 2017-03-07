//
//  GroupBase.h
//  ActionTest
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef GroupBase_h
#define GroupBase_h



#include "ActionBase.h"





class GroupBase : public ActionBase
{
    
protected:
    
    std::vector<SingleBase*> singles {};
    
    
    
public:
    
    virtual ~GroupBase() {};
    
    
    
    inline bool isFinished()
    {
        if(singles.size() == 0) return true;
        
        
        // this loop checks for looptypes of each Single, because a Single will never be finished if it loops
        bool returnValue = true;
        
        for(auto&& s : singles)
        {
            if(!s->isFinished()) { returnValue = false; break; }
        }
        
        return returnValue;
    };
    
    
    
    void stop()
    {
        for(auto&& s : singles)
        {
            s->stop();
        }
        
        delete this;
    }
};



#endif