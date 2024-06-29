#ifndef TEST_AUTOPTR_H
#define TEST_AUTOPTR_H

#include <iostream>

template<class T>
class autoPtr {
public:
    autoPtr(T* ptr = nullptr) : m_ptr(ptr) {}

    autoPtr(const autoPtr& ptr) {
        std::cout << "copy constructor\n";
        m_ptr = new T;
        *m_ptr = *ptr.m_ptr;
    }

    autoPtr(autoPtr&& ptr) {
        std::cout << "move constructor\n";
        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
    }

    autoPtr& operator=(const autoPtr& ptr) {
        std::cout << "copy assignment operator\n";
        if (&ptr == this) { return *this; }
        delete m_ptr;
        m_ptr = new T;
        *m_ptr = *ptr.m_ptr;
        return *this;
    }

    autoPtr& operator=(autoPtr&& ptr) {
        std::cout << "move assignment operator\n";
        if (&ptr == this) { return *this; }
        delete m_ptr;
        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
        return *this;
    }

    T* operator->() const { return m_ptr; }

    T& operator*() const { return *m_ptr; }

    bool isNull() const { return m_ptr == nullptr; }

    ~autoPtr() { delete m_ptr; }

private:
    T* m_ptr;
};

class myItem {
public:
    myItem() { std::cout << "Item acquired\n"; }

    ~myItem() { std::cout << "Item destroyed\n"; }
};

#endif //TEST_AUTOPTR_H
