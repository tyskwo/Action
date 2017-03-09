//
//  TimingFunctions.h
//  Action
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef TimingFunctions_h
#define TimingFunctions_h



#include <math.h>



namespace Action
{

    namespace TimingFunctions
    {

        #define PI 3.14159

        
        
        std::function<float(float t)> Linear = [](float t)
        {
            return t;
        };

        
        std::function<float(float t)> QuadraticEaseIn = [](float t)
        {
            return t * t;
        };
        
        std::function<float(float t)> QuadraticEaseOut = [](float t)
        {
            return t * (2.0f - t);
        };
        
        std::function<float(float t)> QuadraticEaseInOut = [](float t)
        {
            if (t < 0.5f)
            {
                return 2.0f * t * t;
            }
            else
            {
                float f = t - 1.0f;
                return 1.0f - 2.0f * f * f;
            }
        };
        
        std::function<float(float t)> CubicEaseIn = [](float t)
        {
            return t * t * t;
        };
        
        std::function<float(float t)> CubicEaseOut = [](float t)
        {
            float f = t - 1.0f;
            return 1.0f + f * f * f;
        };
        
        std::function<float(float t)> CubicEaseInOut = [](float t)
        {
            if (t < 0.5f)
            {
                return 4.0f * t * t * t;
            }
            else
            {
                float f = t - 1.0f;
                return 1.0f + 4.0f * f * f * f;
            }
        };
        
        std::function<float(float t)> QuarticEaseIn = [](float t)
        {
            return t * t * t * t;
        };
        
        std::function<float(float t)> QuarticEaseOut = [](float t)
        {
            float f = t - 1.0f;
            return 1.0f - f * f * f * f;
        };
        
        std::function<float(float t)> QuarticEaseInOut = [](float t)
        {
            if (t < 0.5f)
            {
                return 8.0f * t * t * t * t;
            }
            else
            {
                float f = t - 1.0f;
                return 1.0f - 8.0f * f * f * f * f;
            }
        };
        
        std::function<float(float t)> QuinticEaseIn = [](float t)
        {
            return t * t * t * t * t;
        };
        
        std::function<float(float t)> QuinticEaseOut = [](float t)
        {
            float f = t - 1.0f;
            return 1.0f + f * f * f * f * f;
        };
        
        std::function<float(float t)> QuinticEaseInOut = [](float t)
        {
            if (t < 0.5f)
            {
                return 16.0f * t * t * t * t * t;
            }
            else
            {
                float f = t - 1.0f;
                return 1.0f + 16.0f * f * f * f * f * f;
            }
        };
        
        std::function<float(float t)> SineEaseIn = [](float t)
        {
            return sin((t - 1.0f) * PI/2.0f) + 1.0f;
        };
        
        std::function<float(float t)> SineEaseOut = [](float t)
        {
            return sin(t * PI/2.0f);
        };
        
        std::function<float(float t)> SineEaseInOut = [](float t)
        {
            return 0.5f * (1.0f - cos(t * PI));
        };
        
        std::function<float(float t)> CircularEaseIn = [](float t)
        {
            return 1.0f - sqrt(1.0f - t * t);
        };
        
        std::function<float(float t)> CircularEaseOut = [](float t)
        {
            return sqrt((2.0f - t) * t);
        };
        
        std::function<float(float t)> CircularEaseInOut = [](float t)
        {
            if (t < 0.5f)
            {
                return 0.5f * (1.0f - sqrt(1.0f - 4.0f * t * t));
            }
            else
            {
                return 0.5f * sqrt(-4.0f * t * t + 8.0f * t - 3.0f) + 0.5f;
            }
        };
        
        std::function<float(float t)> ExponentialEaseIn = [](float t)
        {
            return (t == 0.0f) ? t : pow(2.0f, 10.0f * (t - 1.0f));
        };
        
        std::function<float(float t)> ExponentialEaseOut = [](float t)
        {
            return (t == 1.0f) ? t : 1.0f - pow(2.0f, -10.0f * t);
        };
        
        std::function<float(float t)> ExponentialEaseInOut = [](float t)
        {
            if (t == 0.0f || t == 1.0f)
            {
                return t;
            }
            else if (t < 0.5f)
            {
                return static_cast<float>(0.5f * pow(2.0f, 20.0f * t - 10.0f));
            }
            else
            {
                return static_cast<float>(1.0f - 0.5f * pow(2.0f, -20.0f * t + 10.0f));
            }
        };
        
        std::function<float(float t)> ElasticEaseIn = [](float t)
        {
            return sin(13 * M_PI_2 * t) * pow(2, 10 * (t - 1));
        };
        
        std::function<float(float t)> ElasticEaseOut = [](float t)
        {
            return sin(-13 * M_PI_2 * (t + 1)) * pow(2, -10 * t) + 1;
        };
        
        std::function<float(float t)> ElasticEaseInOut = [](float t)
        {
            if(t < 0.5)
            {
                return 0.5 * sin(13 * M_PI_2 * (2 * t)) * pow(2, 10 * ((2 * t) - 1));
            }
            else
            {
                return 0.5 * (sin(-13 * M_PI_2 * ((2 * t - 1) + 1)) * pow(2, -10 * (2 * t - 1)) + 2);
            }
        };
        
        std::function<float(float t)> BackEaseIn = [](float t)
        {
            return t * t * t - t * sin(t * M_PI);
        };
        
        std::function<float(float t)> BackEaseOut = [](float t)
        {
            float f = (1 - t);
            return 1 - (f * f * f - f * sin(f * M_PI));
        };

        std::function<float(float t)> BackEaseInOut = [](float t)
        {
            if(t < 0.5)
            {
                float f = 2 * t;
                return 0.5 * (f * f * f - f * sin(f * M_PI));
            }
            else
            {
                float f = (1 - (2*t - 1));
                return 0.5 * (1 - (f * f * f - f * sin(f * M_PI))) + 0.5;
            }
        };
        
        std::function<float(float t)> BounceEaseOut = [](float t)
        {
            if(t < 4/11.0)
            {
                return (121 * t * t)/16.0;
            }
            else if(t < 8/11.0)
            {
                return (363/40.0 * t * t) - (99/10.0 * t) + 17/5.0;
            }
            else if(t < 9/10.0)
            {
                return (4356/361.0 * t * t) - (35442/1805.0 * t) + 16061/1805.0;
            }
            else
            {
                return (54/5.0 * t * t) - (513/25.0 * t) + 268/25.0;
            }
        };

        std::function<float(float t)> BounceEaseIn = [](float t)
        {
            return 1 - BounceEaseOut(1 - t);
        };
        
        std::function<float(float t)> BounceEaseInOut = [](float t)
        {
            if(t < 0.5)
            {
                return 0.5 * BounceEaseIn(t*2);
            }
            else
            {
                return 0.5 * BounceEaseOut(t * 2 - 1) + 0.5;
            }
        };
        
        std::function<float(float t)> Smoothstep = [](float t)
        {
            return t * t * (3.0f - 2.0f * t);
        };
        
        std::function<float(float t)> Smootherstep = [](float t)
        {
            return 6.0f * pow(t, 5.0f) - 15.0f * pow(t, 4.0f) + 10.0f * pow(t, 3.0f);
        };
    }

}


#endif
