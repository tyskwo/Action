//
//  Value.h
//  Action
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef Value_h
#define Value_h


namespace Action
{

    /// Value is a representation of what we want to interpolate, with values for the start and end values of that interpolation.
    template <typename T>
    struct Value
    {
        // values for the start and end of the interpolation
        // reference to the value we're interpolating, which also acts as the 'current' value
        T start, end, *current;
        
        
        
        Value<T> (T *current, T start, T end)
        {
            this->start = start;
            this->end   = end;
            
            // set the reference to current
            this->current = current;
            
            // set the value of current
            *this->current = start;
        }
        
        
        
        Value<T> (T start, T end)
        {
            this->start = start;
            this->end   = end;
            *this->current = start;
        }
        
        
        
        Value<T>() { *this->current = this->start; }
    };

}

#endif
