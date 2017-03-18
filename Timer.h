//
//  Timer.h
//  Action
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef Timer_h
#define Timer_h



#include <chrono>






namespace Action
{

    class Timer
    {
        
    private:
        
        std::chrono::time_point<std::chrono::high_resolution_clock> previousTime, currentTime;
        
        std::chrono::duration<double, std::milli> elapsed;
        
        
    public:
        
        bool isPaused = false;

        
        inline void start()
        {
            previousTime = std::chrono::high_resolution_clock::now();
        }
        
        
        
        
        
        double getElapsedMS()
        {
            if(!isPaused)
            {
                currentTime = std::chrono::high_resolution_clock::now();
                
                elapsed += currentTime - previousTime;
                
                previousTime = currentTime;
            }
            
            return elapsed.count();
        }
        
        
        
        
        void pause()  { isPaused = true; }
        void resume()
        {
            isPaused = false;
            previousTime = std::chrono::high_resolution_clock::now();
        }
    };
    
}



#endif
