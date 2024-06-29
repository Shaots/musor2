//
// Created by Lenovo on 24.05.2024.
//

#ifndef TEST_LAMBDA_T_H
#define TEST_LAMBDA_T_H

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <array>

struct Student {
    std::string name;
    int ball;
};

struct Season {
    std::string_view name{};
    double averageTemperature{};
};


void testLambda1();

void testLambda2();

void testLambda3();

void testLambda4();

auto makeWalrus(const std::string_view& name);

void testLambda5();

#endif //TEST_LAMBDA_T_H
