#include <iostream>
#include "ioccontainer.h"
#include "computer.h"
#include "iprocessor.h"

using namespace std;

// инициализируем ненулевым числом
int IOCContainer::s_nextTypeId = 115094801;


int main(int argc, const char *argv[])
{
    //------Example #1----------------
    //Injector injector;
    IOCContainer injector;

    // Регистрируем IProcessor с классом AMDProcessor, т.о. каждый раз запрашивая IProcessor получаем объект AMDProcessor.
    injector.RegisterInstance<IProcessor, AMDProcessor>();
    injector.GetObject<IProcessor>()->SetProcessor("AMD",x64,4.1);
    Computer computer(injector.GetObject<IProcessor>().get());
    cout<<computer.GetProcessor();

    //------Example #2----------------

//    gContainer.RegisterInstance<IAmAThing, TheThing>();
//    gContainer.RegisterFactory<IAmTheOtherThing, TheOtherThing, IAmAThing>();

//    gContainer.GetObject<IAmAThing>()->TestThis();
//    gContainer.GetObject<IAmTheOtherThing>()->TheOtherTest();

//    //Опять запршиваем объект,после последней регистрации получим объект Privet
//    helloInstance = injector.GetObject<IHello>();
//    helloInstance->hello();
    return 0;
}
