//
// Created by Lenovo on 05.06.2024.
//

#ifndef TEST_OPERATOR_T_H
#define TEST_OPERATOR_T_H

#include <iostream>

class Dollars {
public:
    Dollars(int dollar) : m_dollars(dollar) {}

    Dollars(Dollars const& dollars);

    Dollars& operator=(const Dollars& dollars);

public:
    friend Dollars operator+(const Dollars& d1, const Dollars& d2);

    friend Dollars operator+(const Dollars& d1, int value);

    friend Dollars operator+(int value, const Dollars& d1);

    friend Dollars operator-(const Dollars& d1, const Dollars& d2);

    friend Dollars operator*(const Dollars& d1, const Dollars& d2);

    Dollars operator-() const;

    Dollars operator+(int value) const;

    operator int() { return m_dollars; }

    friend bool operator<(const Dollars& d1, const Dollars& d2);

    friend bool operator<=(const Dollars& d1, const Dollars& d2);

    friend bool operator>(const Dollars& d1, const Dollars& d2);

    friend bool operator>=(const Dollars& d1, const Dollars& d2);

    int getDollars() const { return m_dollars; }

    Dollars& operator++();

    Dollars& operator--();

    Dollars operator++(int);

    Dollars operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Dollars& dollars);

private:
    int m_dollars;
};


#endif //TEST_OPERATOR_T_H
