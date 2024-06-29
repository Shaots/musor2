#ifndef TEST_CALCULATOR_H
#define TEST_CALCULATOR_H

#include <iostream>

typedef int (* arithmeticFcn)(int, int);

int getInteger();

char getOperation();

int add(int a, int b);

int subtract(int a, int b);

int multiply(int a, int b);

int divide(int a, int b);

struct arithmeticStruct {
    char op;
    arithmeticFcn fcn;
};

static arithmeticStruct arithmeticArray[4] = {
        {'+', add},
        {'-', subtract},
        {'*', multiply},
        {'/', divide}
};

arithmeticFcn getArithmeticFcn(char op);

#endif //TEST_CALCULATOR_H
