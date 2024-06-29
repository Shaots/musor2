#ifndef TEST_SHABLON_H
#define TEST_SHABLON_H

#include <iostream>

template<class T>
class Pair1 {
public:
    Pair1(T& first, T& second) : m_first(first), m_second(second) {}

    T first() const { return m_first; }

    T second() const { return m_second; }

private:
    T m_first;
    T m_second;
};


template<class T, class S>
class Pair {
public:
    Pair(T&& first, S&& second) : m_first(first), m_second(second) {}

    T first() const { return m_first; }

    S second() const { return m_second; }

private:
    T m_first;
    S m_second;
};


template<class S>
class StringValuePair : public Pair<std::string, S> {
public:
    StringValuePair(const std::string& key, const S& value)
            : Pair<std::string, S>(key, value) {
    }
};

#endif //TEST_SHABLON_H

