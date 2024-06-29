//
// Created by Lenovo on 30.05.2024.
//

#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <iostream>
#include <array>
#include <cassert>

class Stack {
private:
    static int a;

public:
    void reset();

    bool push(int value);

    int pop();

    void print();

private:
    int m_depth;
    static const int m_maxDepth = 10;
    std::array<int, m_maxDepth> m_arr;
};
#endif //TEST_STACK_H
