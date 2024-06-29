#ifndef TEST_SINGLETON_H
#define TEST_SINGLETON_H

// Одиночка — это порождающий паттерн, который гарантирует существование
// только одного объекта определённого класса, а также позволяет достучаться
// до этого объекта из любого места программы.

// Одиночка имеет такие же преимущества и недостатки, что и глобальные переменные.
// Его невероятно удобно использовать, но он нарушает модульность вашего кода.

// Топорно реализовать Одиночку очень просто — достаточно скрыть конструктор и
// предоставить статический создающий метод.

// Тот же класс ведёт себя неправильно в многопоточной среде.
// Несколько потоков могут одновременно вызвать метод получения Одиночки
// и создать сразу несколько экземпляров объекта.

#include <iostream>
#include <thread>
#include <mutex>

class Singleton {
public:
    Singleton(const Singleton& other) = delete;

    Singleton& operator=(const Singleton& other) = delete;

    Singleton& operator=(Singleton&& other);

    static Singleton* getInstance(const std::string& value);

    static void releaseInstance();

    void SomeBusinessLogic() {}

    std::string value() const { return m_value; }

    ~Singleton() {
        std::cout << "Destructor" << std::endl;
    }

protected:
    Singleton(const std::string value) : m_value(value) {}

    static Singleton* m_Singleton;

    std::string m_value;
};

class Singleton2 {
public:
    Singleton2(const Singleton2& other) = delete;

    Singleton2& operator=(const Singleton2& other) = delete;

    Singleton2& operator=(Singleton2&& other);

    static Singleton2& getInstance(const std::string& value);

    void SomeBusinessLogic() {}

    std::string value() const { return m_value; }

    ~Singleton2() {
        std::cout << "Destructor" << std::endl;
    }

protected:
    Singleton2(const std::string value) : m_value(value) {}

    std::string m_value;
};
#endif //TEST_SINGLETON_H
