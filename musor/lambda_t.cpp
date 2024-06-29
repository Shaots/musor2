//
// Created by Lenovo on 24.05.2024.
//


#include "lambda_t.h"

void testLambda1() {
    std::array<Student, 8> arr{
            {{"Albert", 3},
             {"Ben", 5},
             {"Christine", 2},
             {"Dan", 8}, // Dan имеет больше всего баллов (8)
             {"Enchilada", 4},
             {"Francis", 1},
             {"Greg", 3},
             {"Hagrid", 5}}
    };
    auto best{
            std::max_element(arr.begin(), arr.end(),
                             [](const Student &a, const Student &b) -> bool { return a.ball < b.ball; })};
    std::cout << best->name << " is the best student\n";
}

void testLambda2() {
    std::array<Season, 4> seasons{
            {{"Spring", 285.0},
             {"Summer", 296.0},
             {"Fall", 288.0},
             {"Winter", 263.0}}
    };

    auto compareSeason = [](const Season &s1, const Season &s2) -> bool {
        return s1.averageTemperature < s2.averageTemperature;
    };
    std::sort(seasons.begin(), seasons.end(), compareSeason);
    for (const auto &season: seasons) {
        std::cout << season.name << '\n';
    }
}

void testLambda3() {
    int ammo = 10;
    auto shoot{
            [&ammo]() -> void {
                --ammo;
                std::cout << "ammo = " << ammo << std::endl;
            }
    };
    shoot();
    std::cout << ammo << " shot(s) left\n";
}


void testLambda4() {
    std::string favoriteFruit{"grapes"};
    //favoriteFruit = "bananas with chocolate";
    auto print{[=]() {
        std::cout << "I like " << favoriteFruit << std::endl;
    }};
    print();
    favoriteFruit = "bananas with chocolate";
    print();
}


auto makeWalrus(const std::string_view& name) {
    return [&](){
        std::cout << "I am a walrus, my name is " << name << std::endl;
    };
}

void testLambda5(){
    auto sayName{ makeWalrus("Roofus") };
    sayName();
}