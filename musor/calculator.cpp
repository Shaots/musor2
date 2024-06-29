//
// Created by Lenovo on 20.05.2024.
//

#include "calculator.h"

int getInteger() {
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;
    return a;
}

char getOperation() {
    char op;

    do {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

arithmeticFcn getArithmeticFcn(char op) {
    for (auto &arith: arithmeticArray) {
        if (arith.op == op)
            return arith.fcn;
    }
    return add; // функцией по умолчанию будет add()
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}





