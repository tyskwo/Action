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
            // set the reference to current
            this->current = current;
            
            // set the value of current
            *this->current = (this->start = start);
            
            this->end = end;
        }
        
        
        
        Value<T> (T *current, T end)
        {
            this->current = current;
            
            this->start = (*this->current = *current);
            
            this->end = end;
        }
        
        
        
        Value<T> (T start, T *current)
        {
            this->current = current;
            
            this->end = *current;
            
            *this->current = (this->start = start);
        }
        
        
        
        Value<T>() {}
    };

}

#endif
