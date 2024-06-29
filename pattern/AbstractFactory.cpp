#include "AbstractFactory.h"


void ClientCode(const AbstractFactory& factory) {
    const AbstractChair* chair = factory.creatChair();
    const AbstractSofa* sofa = factory.creatSofa();
    std::cout << chair->sitDown() << "\n";
    std::cout << sofa->lie() << "\n";
    delete chair;
    delete sofa;
}

void testAbstractFactory(){
    AbstractFactory* modernFactory = new ModernFactory();
    ClientCode(*modernFactory);
    delete modernFactory;

    AbstractFactory* victorianFactory = new VictorianFactory();
    ClientCode(*victorianFactory);
    delete victorianFactory;
}
