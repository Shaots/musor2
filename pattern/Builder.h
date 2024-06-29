#ifndef TEST_BUILDER_H
#define TEST_BUILDER_H

// Применимость: Паттерн можно часто встретить в C++ коде, особенно там,
// где требуется пошаговое создание продуктов или конфигурация сложных объектов.

// Имеет смысл использовать паттерн Строитель только тогда, когда ваши продукты
// достаточно сложны и требуют обширной конфигурации.

#include <iostream>
#include <vector>

class Product1 {
public:
    std::vector<std::string> parts_;

    void ListParts() const {
        std::cout << "Product parts: ";
        for (size_t i = 0; i < parts_.size(); i++) {
            if (parts_[i] == parts_.back()) {
                std::cout << parts_[i];
            } else {
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

class Builder {
public:
    virtual ~Builder() {}

    virtual void ProducePartA() const = 0;

    virtual void ProducePartB() const = 0;

    virtual void ProducePartC() const = 0;
};

class ConcreteBuilder1 : public Builder {
private:
    Product1* product{};

public:
    ConcreteBuilder1() {
        this->Reset();
    }

    ~ConcreteBuilder1() override {
        delete product;
    }

    void Reset() {
        this->product = new Product1();
    }

    void ProducePartA() const override {
        this->product->parts_.emplace_back("PartA1");
    }

    void ProducePartB() const override {
        this->product->parts_.emplace_back("PartB1");
    }

    void ProducePartC() const override {
        this->product->parts_.emplace_back("PartC1");
    }

    /**
     * Конкретные Строители должны предоставить свои собственные методы
     * получения результатов. Это связано с тем, что различные типы строителей
     * могут создавать совершенно разные продукты с разными интерфейсами.
     * Поэтому такие методы не могут быть объявлены в базовом интерфейсе
     * Строителя (по крайней мере, в статически типизированном языке
     * программирования). Обратите внимание, что PHP является динамически
     * типизированным языком, и этот метод может быть в базовом интерфейсе.
     * Однако мы не будем объявлять его здесь для ясности.
     *
     * Как правило, после возвращения конечного результата клиенту, экземпляр
     * строителя должен быть готов к началу производства следующего продукта.
     * Поэтому обычной практикой является вызов метода сброса в конце тела
     * метода getProduct. Однако такое поведение не является обязательным, вы
     * можете заставить своих строителей ждать явного запроса на сброс из кода
     * клиента, прежде чем избавиться от предыдущего результата.
     */

    /**
     * Please be careful here with the memory ownership. Once you call
     * GetProduct the user of this function is responsible to release this
     * memory. Here could be a better option to use smart pointers to avoid
     * memory leaks
     */

    Product1* GetProduct() {
        Product1* result = this->product;
        this->Reset();
        return result;
    }
};

class Director{
    /**
     * @var Builder
     */
private:
    Builder* builder;
    /**
     * Директор работает с любым экземпляром строителя, который передаётся ему
     * клиентским кодом. Таким образом, клиентский код может изменить конечный
     * тип вновь собираемого продукта.
     */

public:

    void set_builder(Builder* builder){
        this->builder=builder;
    }

    /**
     * Директор может строить несколько вариаций продукта, используя одинаковые
     * шаги построения.
     */

    void BuildMinimalViableProduct(){
        this->builder->ProducePartA();
    }

    void BuildFullFeaturedProduct(){
        this->builder->ProducePartA();
        this->builder->ProducePartB();
        this->builder->ProducePartC();
    }
};

void ClientCode(Director& director);

void testBuilder();

#endif //TEST_BUILDER_H
