//
// Created by Lenovo on 16.05.2024.
//

#include "sort.h"

namespace Shao {
    void printArray(int* array, int size) {
        for (int index = 0; index < size; ++index)
            std::cout << array[index] << " ";
        std::cout << '\n';
    }

    int find(const int arr[], int start, int size, validateFcn ptrFnc) {
        int idx = start;
        for (int i = start + 1; i < size; ++i) {
            if (ptrFnc(arr[idx], arr[i])) {
                idx = i;
            }
        }
        return idx;
    }

    bool ascending(int a, int b) {
        return a > b;
    }

    bool descending(int a, int b) {
        return a < b;
    }

    bool evensFirst(int a, int b) {
        // Если a - чётное число, а b - нечётное число, то a идет первым (никакого обмена местами не требуется)
        if ((a % 2 == 0) && b % 2 != 0)
            return false;

        // Если a - нечётное число, а b - чётное число, то b идет первым (здесь уже требуется обмен местами)
        if (a % 2 != 0 && (b % 2 == 0))
            return true;

        // В противном случае, сортируем в порядке возрастания
        return ascending(a, b);
    }


    void sort::selection(int arr[], int size, validateFcn ptrFnc) {
        int index = 0;
        for (int start = 0; start < size - 1; ++start) {
            index = find(arr, start, size, ptrFnc);
            std::swap(arr[start], arr[index]);
        }
    }

    void sort::bubble(int arr[], int size) {
        int end = size;
        for (int i = 0; i < size; ++i) {
            int counter = 0;
            for (int j = 0; j < end; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    ++counter;
                }
            }
            if (counter == 0)
                return;
            --end;
        }
    }
} // Shao