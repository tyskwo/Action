//
//  Bezier.h
//  ActionTest
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef Bezier_h
#define Bezier_h



namespace Action
{

    namespace Bezier
    {
        typedef std::function<float(float t)> TimingFunction;

        template <typename T>
        TimingFunction GetCurveFromPoints(T x1, T y1, T x2, T y2)
        {
            // clamp x values to [0,1]
            if(x1 > 1) x1 = 1; if(x1 < 0) x1 = 0;
            if(x2 > 1) x2 = 1; if(x2 < 0) x2 = 0;
            
            TimingFunction Curve = [x1, y1, x2, y2](float t) -> float
            {
                // get the x value for the given time
                float x = (3 * (1 - t) * (1 - t) * t * x1) + (3 * (1 - t) * t * t * x2) + t * t * t;
                
                // get the y value for the given x value
                float y = (3 * (1 - x) * (1 - x) * x * y1) + (3 * (1 - x) * x * x * y2) + x * x * x;
                
                return y;
            };

            
            return Curve;
        }
        
        template <typename T>
        TimingFunction GetCurveFromPoints(std::pair <T,T> p1, std::pair <T,T> p2)
        {
            return GetCurveFromPoints(p1.first, p1.second, p2.first, p2.second);
        }
        
        
        template <typename T>
        TimingFunction GetCurveFromPoint(T x1, T y1)
        {
            // clamp x values to [0,1]
            if(x1 > 1) x1 = 1; if(x1 < 0) x1 = 0;
            
            TimingFunction Curve = [x1, y1](float t) -> float
            {
                // get the x value for the given time
                float x = 2 * (1 - t) * t * x1 + t * t;
                float y = 2 * (1 - x) * x * y1 + x * x;
                            
                return y;
            };
            
            
            return Curve;
        }
        
        template <typename T>
        TimingFunction GetCurveFromPoint(std::pair <T,T> p)
        {
            return GetCurveFromPoint(p.first, p.second);
        }
    };
    
}



#endif
