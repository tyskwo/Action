//
//  Sequence.h
//  ActionTest
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef Sequence_h
#define Sequence_h



#include "Value.h"
#include "Timer.h"
#include "TimingFunctions.h"





namespace Action
{

    // A sequence of Actions
    class Sequence : public GroupBase
    {
        
    private:
        
        std::vector<float> delays; // we need to keep track of the individual delays for Yoyo purposes.
        
        
        bool heads; // a bool to keep track of which side of the Yoyo we're on.
        
        
        
    public:
        
        Sequence(std::vector<SingleBase*> s) { heads = true; singles = s; }
        
        void start()
        {
            for(int i = (int)singles.size() - 1; i >= 0; i--)
            {
                auto&& s = singles.at(i);
                
                float delayForS = delay + s->getDelay();
                
                for(int j = i - 1; j >= 0; j--)
                {
                    delayForS += singles.at(j)->getDelay() + singles.at(j)->getDuration();
                }
                
                delays.push_back(delayForS);
                s->setDelay(delayForS);
                
                if(looptype > LoopTypes::None) s->setLooptype(looptype);
                
                s->start();
            }
        }
        
        
        bool update()
        {
            for(int i = 0; i < singles.size(); i++)
            {
                bool didFinish = singles.at(i)->update();
                
                if(didFinish)
                {
                    if(looptype == LoopTypes::None)
                    {
                        delete singles.at(i); singles.at(i) = NULL;
                        
                        singles.erase(singles.begin() + i);
                        ++i;
                    }
                    else if(looptype == LoopTypes::Normal)
                    {
                        singles.at(i)->setDelay(delays.at(0));
                    }
                    else if(looptype == LoopTypes::Yoyo)
                    {
                        float delay = this->getDelay();

                        if(heads)
                        {
                            for(int j = i + 1; j < singles.size(); j++)
                            {
                                delay += (singles.at(j)->getDuration() * 2.0f);
                            }
                        }
                        else
                        {
                            for(int j = i - 1; j >= 0; j--)
                            {
                                delay += (singles.at(j)->getDuration() * 2.0f);
                            }
                        }
                        singles.at(i)->setDelay(delay);
                    }
                    
                    if((i == singles.size() - 1 && heads) || (i == 0 && !heads)) heads = !heads;
                }
                
                if(isFinished())
                {
                    callback();
                    
                    return true;
                }
            }
            
            return false;
        }
    };
    
}




#endif
