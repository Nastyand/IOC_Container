#include <iostream>
#include "ioccontainer.h"
#include "computer.h"
#include "iprocessor.h"


using namespace std;

// инициализируем ненулевым числом
int IOCContainer::s_nextTypeId = 115094801;


int main()
{
    IOCContainer injector;

    //------Example #1----------------

    // Регистрируем IProcessor с классом AMDProcessor, т.о. каждый раз запрашивая IProcessor получаем объект AMDProcessor.
    injector.RegisterInstance<IProcessor, AMDProcessor>();
    injector.GetObject<IProcessor>()->SetProcessor("AMD",x64,4.1);
    Computer computer1(injector.GetObject<IProcessor>().get());
    cout<<computer1.GetProcessor()<<endl;

    //------Example #2----------------

    injector.RegisterInstance<IProcessor, IntelProcessor>();
    injector.GetObject<IProcessor>()->SetProcessor("Intel",x86,3.5);
    Computer computer2(injector.GetObject<IProcessor>().get());
    cout<<computer2.GetProcessor()<<endl;

    return 0;
}
