#include "Factory.h"


void ClientCode(const Creator& creator) {
    std::cout << "sClient: I'm not aware of the creator' class, but it still works.\n"
              << creator.SomeOperation() << std::endl;
}

void testFactory() {
    Creator* creator = new ConcreteCreator1();
    ClientCode(*creator);
    Creator* creator2 = new ConcreteCreator2();
    ClientCode(*creator2);
    delete creator;
    delete creator2;
}