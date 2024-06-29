#ifndef TEST_INHERITANCE_H
#define TEST_INHERITANCE_H

#include <iostream>
#include <array>

class Creature {
public:
    Creature(const std::string& mName, char mSymbol, int mHealth, int mDamage, int mGold)
            : m_name(mName), m_symbol(mSymbol), m_health(mHealth), m_damage(mDamage), m_gold(mGold) {}

    const std::string& getName() const { return m_name; }

    char getSymbol() const { return m_symbol; }

    int getHealth() const { return m_health; }

    int getDamage() const { return m_damage; }

    int getGold() const { return m_gold; }

public:
    void reduceHealth(int count) { m_health -= count; }

    bool isDead() { return m_health <= 0; }

    void addGold(int count) { m_gold += count; }

protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;
};


class Player : public Creature {
public:
    Player(const std::string& name) : Creature(name, '@', 10, 1, 0) {}

    void levelUp() {
        ++level;
        ++m_damage;
    }

    int getLevel() const { return level; }

    bool hasWon() const { return level >= 20; }

private:
    int level = 1;
};


class Monster : public Creature {
public:
    enum Types {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

    struct MonsterData {
        std::string m_name;
        char m_symbol;
        int m_health;
        int m_damage;
        int m_gold;
    };

    static MonsterData monsterData[3];

private:
    explicit Monster(Types types)
            : Creature(monsterData[types].m_name, monsterData[types].m_symbol, monsterData[types].m_health,
                       monsterData[types].m_damage, monsterData[types].m_gold) {}

public:
    static int getRandomNumber(int min, int max);

    static Monster getRandomMonster() {
        return Monster(static_cast<Types>(getRandomNumber(0, MAX_TYPES - 1)));
    }
};


class Animal {
protected:
    std::string m_name;

    //char a;
    Animal(std::string name) : m_name(name) {}

public:
    virtual std::string& getName() {
        std::cout << "Animal" << std::endl;
        return m_name;
    }

    virtual Animal* getThis() {
        std::cout << "Animal gets this" << std::endl;
        return this;
    }

    virtual const char* speak() {
        return "???";
    };
};

class Cat : public Animal {
public:
    Cat(std::string name) : Animal(name) {}

    std::string& getName() override {
        std::cout << "Cat" << std::endl;
        return m_name;
    }

    Cat* getThis() override {
        std::cout << "Not pure virtual function" << std::endl;
        std::cout << "Cat gets this" << std::endl;
        return this;
    }

    const char* speak() override {
        //std::cout << "Not virtual function" << std::endl;
        return "mio";
    }
};

class Dog : public Animal {
public:
    Dog(std::string name) : Animal(name) {}

    Dog* getThis() override {
        std::cout << "Dog gets this" << std::endl;
        return this;
    }

    const char* speak() override {
        return "wonwon";
    }
};


class Parallelogram {
public:
    explicit Parallelogram(int side1 = 0, int side2 = 0, int angle = 0)
            : m_side1(side1), m_side2(side2), m_angle(angle) {
        std::cout << "Parallelogram" << std::endl;
    }

private:
    int m_side1;
    int m_side2;
    int m_angle;
};


class Rectangle : virtual public Parallelogram {
public:
    explicit Rectangle(int side1 = 0, int side2 = 0)
            : Parallelogram(side1, side2, 90) {
        std::cout << "Rectangle" << std::endl;
    }
};


class Rhombus : virtual public Parallelogram {
public:
    explicit Rhombus(int side = 0, int angle = 0)
            : Parallelogram(side, side, angle) {
        std::cout << "Rhombus" << std::endl;
    }
};


class Square : public Rectangle, public Rhombus {
public:
    explicit Square(int side)
            : Rectangle(side, side), Rhombus(side, 90), Parallelogram(side, side, 90) {
        std::cout << "Square" << std::endl;
    }
};


#endif //TEST_INHERITANCE_H
