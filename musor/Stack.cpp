//
// Created by Lenovo on 30.05.2024.
//

#include "Stack.h"




void Stack::reset() {
    m_depth = 0;
    for (int i = 0; i < 10; ++i)
        m_arr[i] = 0;
}

bool Stack::push(int value) {
    if (m_depth == m_maxDepth)
        return false;
    else {
        m_arr[m_depth++] = value;
        return true;
    }
}

int Stack::pop() {
    assert (m_depth > 0);
    return m_arr[--m_depth];

}

void Stack::print() {
    std::cout << "( ";
    for (int i = 0; i < m_depth; ++i)
        std::cout << m_arr[i] << ' ';
    std::cout << ")\n";
}
