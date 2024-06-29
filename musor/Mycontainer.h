
#ifndef TEST_MYCONTAINER_H
#define TEST_MYCONTAINER_H

#include <iostream>
#include <cassert>
#include <initializer_list>

class ArrayInt {
public:
    ArrayInt() : m_length(0), m_data(nullptr) {}

    explicit ArrayInt(int len) : m_length(len) {
        assert(len >= 0);
        if (len > 0)
            m_data = new(std::nothrow) int[len];
        else
            m_data = nullptr;
    }

    ArrayInt(const std::initializer_list<int>& list) : ArrayInt(list.size()) {
        memcpy(m_data, list.begin(), m_length * sizeof(int));
    }

    ArrayInt& operator=(const std::initializer_list<int>& list) {
        if (list.size() != static_cast<size_t>(m_length)) {
            delete[] m_data;
            m_length = list.size();
            m_data = new(std::nothrow) int[m_length];
        }
        int count = 0;
        for (auto& element: list) {
            m_data[count] = element;
            ++count;
        }
        return *this;
    }

    ~ArrayInt() {
        delete[] m_data;
    }

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int idx) {
        assert(0 <= idx && idx <= m_length - 1);
        return m_data[idx];
    }

    int getLength() const { return m_length; }

    void reallocate(int newLength) {
        erase();
        if (newLength <= 0)
            return;
        m_data = new int[newLength];
        m_length = newLength;
    }

    void resize(int newLength) {
        if (newLength == m_length)
            return;
        if (newLength <= 0) {
            erase();
            return;
        }
        int* data = new int[newLength]{0};
        if (m_length > 0) {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            memcpy(data, m_data, elementsToCopy * sizeof(int));
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index) {
        assert(0 <= index && index <= m_length);
        int* data = new int[m_length + 1]{0};
        memcpy(data, m_data, index * sizeof(int));
        data[index] = value;
        int* ptr = &(data[index + 1]);
        memcpy(ptr, &(m_data[index]), (m_length - index) * sizeof(int));
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index) {
        assert(index >= 0 && index < m_length);
        if (m_length == 1) {
            erase();
            return;
        }
        int* data = new int[m_length - 1];
        memcpy(data, m_data, index * sizeof(int));
        int* ptr = &(data[index]);
        memcpy(ptr, &(m_data[index + 1]), (m_length - index) * sizeof(int));
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void insertAtBeginning(int value) { insertBefore(value, 0); }

    void insertAtEnd(int value) { insertBefore(value, m_length); }

private:
    int m_length;
    int* m_data;
};


#endif //TEST_MYCONTAINER_H
