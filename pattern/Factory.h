#ifndef TEST_FACTORY_H
#define TEST_FACTORY_H

// Паттерн можно часто встретить в любом C++ коде, где требуется гибкость при создании продуктов.

// Фабричный метод — это порождающий паттерн проектирования, который определяет общий интерфейс
// для создания объектов в суперклассе, позволяя подклассам изменять тип создаваемых объектов.

#include <iostream>

class Product {
public:
    virtual ~Product() {}

    virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteProduct2}";
    }
};

class Creator {
public:
    virtual ~Creator() {};

    virtual Product* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        // Вызываем фабричный метод, чтобы получить объект-продукт.
        Product* product = this->FactoryMethod();
        // Далее, работаем с этим продуктом.
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creator {
    /**
     * Обратите внимание, что сигнатура метода по-прежнему использует тип
     * абстрактного продукта, хотя фактически из метода возвращается конкретный
     * продукт. Таким образом, Создатель может оставаться независимым от
     * конкретных классов продуктов.
     */
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct2();
    }
};


void ClientCode(const Creator& creator);


void testFactory();

#endif //TEST_FACTORY_H
