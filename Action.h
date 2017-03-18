//
//  Action.h
//  ActionTest
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#ifndef Action_h
#define Action_h



#include <iostream>
#include <vector>
#include "Single.h"
#include "Group.h"
#include "Sequence.h"





namespace Action
{
    
    // list of all of the Actions
    static std::vector<SingleBase*> singles   {};
    static std::vector<Group*>      groups    {};
    static std::vector<Sequence*>   sequences {};

    
    
    
    
    inline static bool isEmpty() { return sequences.size() == 0 && groups.size() == 0 && singles.size() == 0; }
    
    
    
    
    
    // methods for adding Singles of various parameters
    inline static void addSingle(SingleBase* s) { singles.push_back(s); s->start(); };
    
    
    template <typename T>
    static void addSingle(Value<T>* value)
    {
        Single<T>* s = new Single<T>(value);
        
        addSingle(s);
    };
    
    
    template <typename T>
    static void addSingle(Value<T>* value, float duration)
    {
        Single<T>* s = new Single<T>(value, duration);
        
        addSingle(s);
    };
    
    
    template <typename T>
    static void addSingle(Value<T>* value, float duration, Callback cb)
    {
        Single<T>* s = new Single<T>(value, duration);
        
        s->setCallback(cb);
        
        addSingle(s);
    };
    
    
    template <typename T>
    static void addSingle(Value<T>* value, float duration, TimingFunction tf)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        addSingle(s);
    };
    
    
    template <typename T>
    static void addSingle(Value<T>* value, float duration, float delay, TimingFunction tf)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        s->setDelay(delay);
        
        addSingle(s);
    };
    
    
    template <typename T>
    static void addSingle(Value<T>* value, float duration, float delay, TimingFunction tf, Callback cb, LoopTypes::Type loop = LoopTypes::None)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        s->setDelay(delay);
        s->setCallback(cb);
        s->setLooptype(loop);
        
        addSingle(s);
    };
    
    
    template <typename T>
    static void addSingle(Value<T>* value, float duration, TimingFunction tf, Callback cb)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        s->setCallback(cb);
        
        addSingle(s);
    };
    
    
    template <typename T>
    static void addSingle(Value<T>* value, float duration, TimingFunction tf, Callback cb, LoopTypes::Type loop = LoopTypes::None)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        s->setCallback(cb);
        s->setLooptype(loop);
        
        addSingle(s);
    };
    
    
    
    
    
    
    
    
    
    
    // methods for creating Singles of various parameters
    inline static SingleBase* createSingle(SingleBase* s) { return s; };
    
    template <typename T>
    static SingleBase* createSingle(Value<T>* value, float duration)
    {
        Single<T>* s = new Single<T>(value, duration);
        
        return createSingle(s);
    };
    
    
    template <typename T>
    static SingleBase* createSingle(Value<T>* value, float duration, TimingFunction tf)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        return createSingle(s);
    };
    
    
    template <typename T>
    static SingleBase* createSingle(Value<T>* value, float duration, float delay, TimingFunction tf)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        s->setDelay(delay);
        
        return createSingle(s);
    };
    
    
    template <typename T>
    static SingleBase* createSingle(Value<T>* value, float duration, float delay, TimingFunction tf, Callback cb)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        s->setDelay(delay);
        s->setCallback(cb);
        
        return createSingle(s);
    };
    
    
    template <typename T>
    static SingleBase* createSingle(Value<T>* value, float duration, TimingFunction tf, Callback cb)
    {
        Single<T>* s = new Single<T>(value, duration, tf);
        
        s->setCallback(cb);
        
        return createSingle(s);
    };
    
    
    
    
    
    
    
    
    
    
    // methods for adding Groups of various parameters
    inline static void addGroup(Group* g) { groups.push_back(g); g->start(); };
    
    static void addGroupFrom(std::vector<SingleBase*> s)
    {
        Group* g = new Group(s);
        
        addGroup(g);
    };
    
    static void addGroupFrom(std::vector<SingleBase*> s, float delay)
    {
        Group* g = new Group(s);
        
        g->setDelay(delay);
        
        addGroup(g);
    };
    
    static void addGroupFrom(std::vector<SingleBase*> s, Callback cb)
    {
        Group* g = new Group(s);
        
        g->setCallback(cb);
        
        addGroup(g);
    };
    
    static void addGroupFrom(std::vector<SingleBase*> s, float delay, Callback cb)
    {
        Group* g = new Group(s);
        
        g->setDelay(delay);
        g->setCallback(cb);
        
        addGroup(g);
    };
    
    
    
    
    
    
    
    
    
    
    // methods for adding Sequences of various parameters
    inline static void addSequence(Sequence* seq) { sequences.push_back(seq); seq->start(); };
    
    static void addSequenceFrom(std::vector<SingleBase*> s)
    {
        Sequence* seq = new Sequence(s);
        
        addSequence(seq);
    };
    
    static void addSequenceFrom(std::vector<SingleBase*> s, float delay)
    {
        Sequence* seq = new Sequence(s);
        
        seq->setDelay(delay);
        
        addSequence(seq);
    };
    
    static void addSequenceFrom(std::vector<SingleBase*> s, Callback cb)
    {
        Sequence* seq = new Sequence(s);
        
        seq->setCallback(cb);
        
        addSequence(seq);
    };
    
    static void addSequenceFrom(std::vector<SingleBase*> s, float delay, Callback cb)
    {
        Sequence* seq = new Sequence(s);
        
        seq->setDelay(delay);
        seq->setCallback(cb);
        
        addSequence(seq);
    };
    
    static void addSequenceFrom(std::vector<SingleBase*> s, float delay, Callback cb, LoopTypes::Type loop = LoopTypes::None)
    {
        Sequence* seq = new Sequence(s);
        
        seq->setDelay(delay);
        seq->setCallback(cb);
        seq->setLooptype(loop);
        
        addSequence(seq);
    };
    
    
    
    
    
    
    
    
    
    
    
    // update all Actions
    static void update()
    {
        for(int i = 0; i < singles.size(); i++)
        {
            singles.at(i)->update();
            
            // if the Action is completed, delete it
            if(singles.at(i)->isFinished() && singles.at(i)->getLooptype() == LoopTypes::None)
            {
                delete singles.at(i); singles.at(i) = NULL;
                
                singles.erase(singles.begin() + i);
                ++i;
            }
        }
        
        
        for(int i = 0; i < groups.size(); i++)
        {
            groups.at(i)->update();
            
            if(groups.at(i)->isFinished() && sequences.at(i)->getLooptype() == LoopTypes::None)
            {
                delete groups.at(i); groups.at(i) = NULL;
                
                groups.erase(groups.begin() + i);
                ++i;
            }
        }
        
        for(int i = 0; i < sequences.size(); i++)
        {
            sequences.at(i)->update();
            
            if(sequences.at(i)->isFinished() && sequences.at(i)->getLooptype() == LoopTypes::None)
            {
                delete sequences.at(i); sequences.at(i) = NULL;
                
                sequences.erase(sequences.begin() + i);
                ++i;
            }
        }
    }
    
    
    
    
    
    
    
    
    namespace Search
    {
        template <typename T>
        void RemoveSingles(Value<T>* value)
        {
            for(int i = 0; i < singles.size(); i++)
            {
                if(&(static_cast<Single<T>*>(singles.at(i))->getValue()->current) == &value->current)
                {
                    singles.at(i)->stop();
                    
                    singles.at(i) = NULL;
                    singles.erase(singles.begin() + i);
                    ++i;
                }
            }
        }
        
    }
    
    
}



#endif
