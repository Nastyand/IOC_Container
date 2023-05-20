#ifndef COMPUTER_H
#define COMPUTER_H

#include "iprocessor.h"

class Computer
{
    IProcessor* processor;
public:
    Computer(IProcessor* p)
    {
        processor = p;
    }
    string GetProcessor()
    {
       return processor->GetProcessorInfo();
    }
};

#endif // COMPUTER_H
