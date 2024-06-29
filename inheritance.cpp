//
// Created by Lenovo on 07.06.2024.
//

#include "inheritance.h"


Monster::MonsterData Monster::monsterData[3]{
        {"dragon", 'D', 20, 4, 100},
        {"orc",    'o', 4,  2, 25},
        {"slime",  's', 1,  1, 10},
};

int Monster::getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

// Равномерно распределяем генерацию значения из диапазона
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

