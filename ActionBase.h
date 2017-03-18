//
//  ActionBase.h
//  ActionTest
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef ActionBase_h
#define ActionBase_h



#include "Bezier.h"
#include "LoopTypes.h"
#include "Search.h"
#include "Timer.h"
#include "TimingFunctions.h"





namespace Action
{
    
    // typedefs for what is a TimingFunction and a Callback
    typedef std::function<float(float t)> TimingFunction;
    typedef std::function<void()>         Callback;
    
    
    class ActionBase
    {
        
    protected:
        
        float           delay;
        bool            finished;
        Callback        callback;
        LoopTypes::Type looptype;
        
        
        
    public:
        
        virtual ~ActionBase() {};
        
        
        
        virtual bool update() = 0;
        
        
        
        virtual inline bool isFinished() { return finished; };
        
        
        
        inline void setCallback(Callback        cb)    { this->callback = cb;    }
        inline void setLooptype(LoopTypes::Type loop)  { this->looptype = loop;  }
        inline void setDelay   (float           delay) { this->delay    = delay; }
        
        
        
        inline float           getDelay()    { return delay;    }
        inline LoopTypes::Type getLooptype() { return looptype; }
        
        
        
        
        
        virtual void start() = 0;
        
        void start(float delay)
        {
            this->delay = delay;
            
            this->start();
        }
        
        void start(Callback callback)
        {
            this->callback = callback;
            
            this->start();
        }
        
        void start(LoopTypes::Type loop)
        {
            this->looptype = loop;
            
            this->start();
        }
        
        void start(float delay, Callback callback)
        {
            this->callback = callback;
            
            this->start(delay);
        }
        
        void start(float delay, LoopTypes::Type loop)
        {
            this->looptype = loop;
            
            this->start(delay);
        }
        
        void start(Callback callback, LoopTypes::Type loop)
        {
            this->callback = callback;
            
            this->start(loop);
        }
        
        void start(float delay, Callback callback, LoopTypes::Type loop)
        {
            this->delay    = delay;
            this->callback = callback;
            
            this->start(loop);
        }
        
        
        
        
        
        void restart()
        {
            finished = false;
            this->start();
        }
        
        virtual void pause()  = 0;
        virtual void resume() = 0;
        virtual void stop() { delete this; }
    };
    
}



#endif
