//
//  main.cpp
//  Action
//
//  Copyright © 2017 tyskwo. All rights reserved.
//



#include "Action.h"




// test class just to show callback functionality.
class Test
{
    
public:
    
    int   testInt;
    float testFloat;
    char  testChar;
    
    void OnComplete(std::string type, int testParameter)
    {
        std::cout << type << " " << testParameter << " DONE\n";
    }
};





int main(int argc, const char * argv[])
{
    // instantiate test class.
    Test* t = new Test();
    
    
    
    
    
    // let's create some values.
    //                            variable to change, 'start' value, 'end' value
    Action::Value<int>   value1 { &t->testInt,          0,           100 };
    Action::Value<float> value2 { &t->testFloat,        0,           500 };
    Action::Value<char>  value3 { &t->testChar,       'A',           'Z' };
    
    
    TimingFunction tf = Action::Bezier::GetCurveFromPoints(std::make_pair (1.0f, 0.32f), std::make_pair (0.0f, 0.82f));
    
    Action::addSingle(&value1, 3.0f,     0.5f,  tf,  std::bind([&](){ t->OnComplete("SINGLE", 1); }), Action::LoopTypes::None);

    
/*
    // let's create two single Actions:
    
    //                value,   duration, delay, timing function,                             callback
    Action::addSingle(&value1, 3.0f,     0.5f,  Action::TimingFunctions::ExponentialEaseIn,  std::bind([&](){ t->OnComplete("SINGLE", 1); }), Action::LoopTypes::None);
    Action::addSingle(&value2, 3.0f,            Action::TimingFunctions::ExponentialEaseOut, std::bind([&](){ t->OnComplete("SINGLE", 2); }), Action::LoopTypes::None);
*/
 
    
    
    
    
/*
    // let's create a group Action:
    std::vector<SingleBase*> s = std::vector<SingleBase*>
    {
        Action::createSingle(&value1, 3.0f, 2.5f, Action::TimingFunctions::ExponentialEaseIn,  std::bind([&](){ t->OnComplete("GROUP", 1); })),
        Action::createSingle(&value2, 3.0f,       Action::TimingFunctions::ExponentialEaseOut, std::bind([&](){ t->OnComplete("GROUP", 2); }))
    };
    
    //                   vector of singles, delay, callback
    Action::addGroupFrom(s,                 1.0f,  std::bind([&](){ std::cout <<"GROUP COMPLETE\n"; }));
*/
    

    
    
/*
    // let's create a sequence Action:
    std::vector<SingleBase*> s = std::vector<SingleBase*>
    {
        Action::createSingle(&value1, 3.0f, Action::TimingFunctions::ExponentialEaseIn,    std::bind([&](){ t->OnComplete("SEQUENCE", 1); })),
        Action::createSingle(&value2, 3.0f, Action::TimingFunctions::ExponentialEaseOut,   std::bind([&](){ t->OnComplete("SEQUENCE", 2); })),
        Action::createSingle(&value3, 3.0f, Action::TimingFunctions::ExponentialEaseInOut, std::bind([&](){ t->OnComplete("SEQUENCE", 3); }))
    };
 
    //callbacks are lambdas, can be whatever you want.
    Callback cb = std::bind([&]()
    {
        int example = 0;
        
        while(example < 100) example += 5;
        
        std::cout << "SEQUENCE COMPLETE\n";
    });
    
    Action::addSequenceFrom(s, 1.0f, cb, Action::LoopTypes::Yoyo);
*/
    
    
    
    
    
    
    // so long as any Action is not finished...
    while(!Action::isEmpty())
    {
        Action::update();
        
        std::cout << t->testInt << "    " << t->testFloat << "    " << t->testChar << '\n'; // print out current value to see it in progress
    }
    
    
    
    
    
    
    
    // when finished, print out values to show it actually worked.
    std::cout << "INT: " << t->testInt << "   FLOAT: " << t->testFloat << "   CHAR: " << t->testChar << "\n";
    
    
    
    
    
    
    
    return 0;
}
