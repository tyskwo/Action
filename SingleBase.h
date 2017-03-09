//
//  SingleBase.h
//  ActionTest
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef SingleBase_h
#define SingleBase_h



#include "ActionBase.h"




namespace Action
{

    // a base that doesn't deal with templates so that we can hold all Singles in one container
    class SingleBase : public ActionBase
    {
        
    protected:
        
        float duration, elapsed;
        
        
        TimingFunction timingFunction;
        
        
        Timer timer;
        
        
        
        
        
    public:
        
        virtual ~SingleBase() {};
        
        inline bool isFinished() { return finished; };
        
        
        inline void setTimingFunction(TimingFunction tf      ) { this->timingFunction = tf;       }
        inline void setDuration      (float          duration) { this->duration       = duration; }
        
        
        inline float getDuration() { return duration; }
        
        
        void start() { this->timer.start(); }
        void stop()  { delete this;         }
    };
    
}



#endif /* SingleBase_h */
