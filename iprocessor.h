#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include <iostream>
#include <sstream>

using namespace std;

enum ProcessorType
{ x86=86,
  x64=64
};

class IProcessor

{
public:
     IProcessor(){}

//get,set????
     virtual string GetProcessorInfo()=0;

     virtual void SetProcessor(std::string version, ProcessorType type, double speed)=0;

     virtual ~IProcessor(){}

 };
class IntelProcessor:public IProcessor
{
    string Version;
    ProcessorType Type;
    double Speed;
public:
    string GetProcessorInfo()
    {
        ostringstream speed;
        speed<<Speed;
        string type = to_string(Type);
        return "Processor for " + Version + " speed: " + speed.str() + " type: x" + type;
    }
    void SetProcessor(std::string version, ProcessorType type, double speed)
    {
        Version = version;
        Type = type;
        Speed = speed;
    }
    IntelProcessor(){}
    ~IntelProcessor(){}
};

class AMDProcessor:public IProcessor
{
    string Version;
    ProcessorType Type;
    double Speed;
public:
    string GetProcessorInfo()
    {
        ostringstream speed;
        speed<<Speed;
        string type = to_string(Type);
        return "Processor for " + Version + " speed: " + speed.str() + " type: x" + type;
    }
    void SetProcessor(std::string version, ProcessorType type, double speed)
    {
        Version = version;
        Type = type;
        Speed = speed;
    }
    AMDProcessor(){}
    ~AMDProcessor(){}
};

#endif // IPROCESSOR_H
