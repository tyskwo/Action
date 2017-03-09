//
//  Timer.h
//  Action
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef Timer_h
#define Timer_h



#if defined(__MACH__)
#include <mach/clock.h>
#include <mach/mach.h>



#elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
#include <time.h>
#include <sys/time.h>



#elif defined(_WIN32)
#if defined(_MSC_VER) && !defined(NOMINMAX)
#define NOMINMAX
#endif

#include <windows.h>
#endif





namespace Action
{

    class Timer
    {
        
    private:
        
    #if defined(__MACH__)
        
        clock_serv_t    system_clock;
        mach_timespec_t time1, time2;
        
     
        
    #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
        
        struct timespec time1, time2;

        
        
    #elif defined(_WIN32)
        
        LARGE_INTEGER ticks1, ticks2;
        double frequency;
        
    #endif
        
        
        
        
        
    public:
        
        Timer()
        {
            
    #if defined(__MACH__)
            
            host_get_clock_service(mach_host_self(), SYSTEM_CLOCK, &system_clock);
            
            
            
    #elif _WIN32

            LARGE_INTEGER freq;
            QueryPerformanceFrequency(&freq);
            frequency = static_cast<double>(freq.QuadPart);
            
    #endif
        }
        

        
        
        
        ~Timer()
        {
            
    #if defined(__MACH__)
            
            mach_port_deallocate(mach_task_self(), system_clock);
            
    #endif
        }
        
        
        
        
        
        inline void start()
        {
            
    #if defined(__MACH__)
            
            clock_get_time(system_clock, &time1);
            

            
    #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
            
            clock_gettime(CLOCK_MONOTONIC, &time1);
            
            
            
    #elif _WIN32
            
            QueryPerformanceCounter(&ticks1);
            
    #endif
        }
        
        
        
        
        
        double getElapsedMS()
        {
            
    #if defined(__MACH__)
            
            clock_get_time(system_clock, &time2);
            return ((1000.0 * static_cast<double>(time2.tv_sec - time1.tv_sec)) + static_cast<double>((time2.tv_nsec - time1.tv_nsec) / 1000000.0));


            
    #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
            
            clock_gettime(CLOCK_MONOTONIC, &time2);
            return ((1000.0 * static_cast<double>(time2.tv_sec - time1.tv_sec)) + static_cast<double>(time2.tv_nsec - time1.tv_nsec) / 1000000.0);

            
            
    #elif _WIN32
            
            QueryPerformanceCounter(&ticks2);
            return (static_cast<double>(ticks2.QuadPart - ticks1.QuadPart) * 1000.0) / frequency;
            
    #endif
        }
    };
    
}



#endif
