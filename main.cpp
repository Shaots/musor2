#include <iostream>
#include <list>
#include <algorithm>
#include "pattern/Singleton.h"
#include "pattern/AbstractFactory.h"
#include "pattern/Factory.h"
#include "pattern/Prototype.h"
#include "pattern/Builder.h"
#include <iostream>

class A {
public:
    A() {
        std::cout << "A " << std::endl;
    }

    A(const A& a) {
        std::cout << "A+ " << std::endl;
    }

    ~A() {
        std::cout << "~ " << std::endl;
    }
};

int main() {
    std::cout << sizeof(A) << std::endl;
    std::vector<A> a;
    a.reserve(2);
    a.emplace_back();
    a.emplace_back();
    a.emplace_back();
    return 0;
}