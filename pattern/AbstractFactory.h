#ifndef TEST_ABSTRACTFACTORY_H
#define TEST_ABSTRACTFACTORY_H

// Абстрактная фабрика — это порождающий паттерн проектирования,
// который позволяет создавать семейства связанных объектов,
// не привязываясь к конкретным классам создаваемых объектов.

// Применимость: Паттерн можно часто встретить в C++ коде,
// особенно там, где требуется создание семейств продуктов (например, внутри фреймворков).

// Гарантирует сочетаемость создаваемых продуктов.
// Избавляет клиентский код от привязки к конкретным классам продуктов.
// Выделяет код производства продуктов в одно место, упрощая поддержку кода.
// Упрощает добавление новых продуктов в программу.
// Реализует принцип открытости/закрытости.

// Усложняет код программы из-за введения множества дополнительных классов.
// Требует наличия всех типов продуктов в каждой вариации.
#include <iostream>

// Chair + Sofa

class AbstractChair {
public:
    virtual ~AbstractChair() {}

    virtual std::string sitDown() const = 0;
};

class ModernChair : public AbstractChair {
public:
    std::string sitDown() const override {
        return "You can sit down on the modern chair";
    }
};

class VictorianChair : public AbstractChair {
public:
    std::string sitDown() const override {
        return "You can sit down on the victorian chair";
    }
};


class AbstractSofa {
public:
    virtual ~AbstractSofa() {}

    virtual std::string lie() const = 0;
};

class ModernSofa : public AbstractSofa {
public:
    std::string lie() const override {
        return "You can lie on the modern sofa";
    }
};

class VictorianSofa : public AbstractSofa {
public:
    std::string lie() const override {
        return "You can lie on the victorian sofa";
    }
};


class AbstractFactory {
public:
    virtual AbstractSofa* creatSofa() const = 0;

    virtual AbstractChair* creatChair() const = 0;
};

class ModernFactory : public AbstractFactory {
public:
    AbstractChair* creatChair() const override {
        return new ModernChair();
    }

    AbstractSofa* creatSofa() const override {
        return new ModernSofa();
    }
};

class VictorianFactory : public AbstractFactory {
public:
    AbstractChair* creatChair() const override {
        return new VictorianChair();
    }

    AbstractSofa* creatSofa() const override {
        return new VictorianSofa();
    }
};


void ClientCode(const AbstractFactory& factory);


void testAbstractFactory();
#endif //TEST_ABSTRACTFACTORY_H
