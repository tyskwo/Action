//
//  Single.h
//  Action
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef Single_h
#define Single_h



#include "SingleBase.h"
#include "Value.h"





// Single top layer that deals with the templated value.
template <typename T>
class Single : public SingleBase
{
    
private:
    
    Value<T>* value;
    
    
    
    void OnComplete()
    {
        finished = true;

        switch(looptype)
        {
            case LoopTypes::None: break;

            case LoopTypes::Normal:
                *value->current = value->start;
                
                this->restart();
                break;
                
            case LoopTypes::Yoyo:
                auto temp    = value->start; // simple swap
                value->start = value->end;
                value->end   = temp;
                
                this->restart();
                break;
        }
    }
    
    
    
    
    
public:
 
    bool update()
    {
        // get elapsed time
        elapsed = timer.getElapsedMS() / 1000.0f;
        
        if(elapsed > delay)
        {
            // get the current completion percentage
            float percent = (elapsed - delay) / duration;
            
            // we're finished
            if(percent >= 1.0f)
            {
                *value->current = value->end; // make sure we don't over-pass the end value
                
                callback(); // call our callback
                
                OnComplete(); //update our values based on if we're looping
                
                return true;
            }
            
            // otherwise interpolate our value
            else *value->current = (value->start + ((timingFunction)(percent))*(value->end - value->start));
        }
        
        return false;
    }
    
    
    
    Single(Value<T>* value)
    {
        delay = 0.0f;
        timingFunction = TimingFunctions::Linear;
        duration = 1.0f;
        
        this->value = value;
    }
    
    Single(Value<T>* value, float duration)
    {
        delay = 0.0f;
        timingFunction = TimingFunctions::Linear;
        
        this->value = value;
        this->duration = duration;
    }
    
    Single(Value<T>* value, float duration, TimingFunction tf)
    {
        delay = 0.0f;
        
        this->value = value;
        this->duration = duration;
        this->timingFunction = tf;
    }
    
    
    
    inline T getCurrentValue() { return value->current; }
};



#endif
