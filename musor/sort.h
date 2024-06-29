//
// Created by Lenovo on 16.05.2024.
//

#ifndef TEST_SORT_H
#define TEST_SORT_H

#include <iostream>
#include <algorithm>

namespace Shao {
    using validateFcn = bool(*)(int, int);

    void printArray(int* array, int size);

    int find(const int arr[], int start, int size, validateFcn ptrFnc);

    bool ascending(int a, int b);

    bool descending(int a, int b);

    bool evensFirst(int a, int b);

    class sort {
    public:
        static void selection(int arr[], int size, validateFcn ptrFnc = ascending);

        static void bubble(int arr[], int size);
    };

} // Shao

#endif //TEST_SORT_H
