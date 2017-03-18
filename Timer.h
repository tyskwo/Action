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
        
        bool isPaused = false;
        
    #if defined(__MACH__)
        
        clock_serv_t    system_clock;
        mach_timespec_t time1, time2, pauseStart, pauseDuration;
        
     
        
    #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
        
        struct timespec time1, time2, pauseStart, pauseDuration;

        
        
    #elif defined(_WIN32)
        
        LARGE_INTEGER ticks1, ticks2, pauseStart, pauseDuration;
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
            pauseDuration.tv_sec  = 0;
            pauseDuration.tv_nsec = 0;
            

            
    #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
            
            clock_gettime(CLOCK_MONOTONIC, &time1);
            pauseDuration.tv_sec  = 0;
            pauseDuration.tv_nsec = 0;
            
            
    #elif _WIN32
            
            QueryPerformanceCounter(&ticks1);
            pauseDuration.QuadPart = 0;
            
    #endif
        }
        
        
        
        
        
        double getElapsedMS()
        {
            if(!isPaused)
            {
                #if defined(__MACH__)
                        
                    clock_get_time(system_clock, &time2);
                    return ((1000.0 * static_cast<double>(time2.tv_sec - time1.tv_sec - pauseDuration.tv_sec)) + static_cast<double>((time2.tv_nsec - time1.tv_nsec - pauseDuration.tv_nsec) / 1000000.0));


                        
                #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
                        
                    clock_gettime(CLOCK_MONOTONIC, &time2);
                    return ((1000.0 * static_cast<double>(time2.tv_sec - time1.tv_sec - pauseDuration.tv_sec)) + static_cast<double>(time2.tv_nsec - time1.tv_nsec - pauseDuration.tv_nsec) / 1000000.0);

                        
                        
                #elif _WIN32
                        
                    QueryPerformanceCounter(&ticks2);
                    return (static_cast<double>(ticks2.QuadPart - ticks1.QuadPart - pauseDuration.QuadPart) * 1000.0) / frequency;
                        
                #endif
            }
            
            else
            {
                #if defined(__MACH__)
                
                    return ((1000.0 * static_cast<double>(pauseStart.tv_sec - time1.tv_sec - pauseDuration.tv_sec)) + static_cast<double>((pauseStart.tv_nsec - time1.tv_nsec - pauseDuration.tv_nsec) / 1000000.0));
                
                
                
                #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
                
                    return ((1000.0 * static_cast<double>(pauseStart.tv_sec - time1.tv_sec - pauseDuration.tv_sec)) + static_cast<double>(pauseStart.tv_nsec - time1.tv_nsec - pauseDuration.tv_nsec) / 1000000.0);
                
                
                
                #elif _WIN32
                
                    return (static_cast<double>(pauseStart.QuadPart - ticks1.QuadPart - pauseDuration.QuadPart) * 1000.0) / frequency;
                
                #endif
            }
            
            return 0;
        }
        
        
        
        
        void pause()
        {
            isPaused = true;
            
            #if defined(__MACH__)
            
                clock_get_time(system_clock, &pauseStart);
            
            
            #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
            
                clock_gettime(CLOCK_MONOTONIC, &pauseStart);
            
            
            #elif _WIN32
            
                QueryPerformanceCounter(&pauseStart);
            
            #endif
        }
        
        
        
        
        
        void resume()
        {
            isPaused = false;
            
            #if defined(__MACH__)
            
                clock_get_time(system_clock, &pauseDuration);
            
                pauseDuration.tv_nsec -= pauseStart.tv_nsec;
                pauseDuration.tv_sec  -= pauseStart.tv_sec;

            
            #elif (defined(linux) || defined(__linux__) || defined(__linux)) || (defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
            
                clock_gettime(CLOCK_MONOTONIC, &pauseDuration);
            
                pauseDuration.tv_nsec -= pauseStart.tv_nsec;
                pauseDuration.tv_sec  -= pauseStart.tv_sec;
            
            
            #elif _WIN32
            
                QueryPerformanceCounter(&pauseDuration);
            
                pauseDuration.QuadPart -= pauseStart.QuadPart;

            #endif
        }
    };
    
}



#endif
