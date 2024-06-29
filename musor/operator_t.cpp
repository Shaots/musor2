//
// Created by Lenovo on 05.06.2024.
//

#include "operator_t.h"

Dollars operator+(const Dollars &d1, const Dollars &d2) {
    return Dollars(d1.m_dollars + d2.m_dollars);
}

Dollars operator-(const Dollars &d1, const Dollars &d2) {
    return Dollars(d1.m_dollars - d2.m_dollars);
}

Dollars operator*(const Dollars &d1, const Dollars &d2) {
    return Dollars(d1.m_dollars * d2.m_dollars);
}

Dollars operator+(const Dollars &d1, int value) {
    return Dollars(d1.m_dollars + value);
}

Dollars operator+(int value, const Dollars &d1) {
    return Dollars(value + d1.m_dollars);
}

Dollars Dollars::operator+(int value) const {
    return Dollars(value + m_dollars);
}

Dollars Dollars::operator-() const {
    return Dollars(-m_dollars);
}

bool operator<(const Dollars &d1, const Dollars &d2) {
    return d1.m_dollars < d2.m_dollars;
}

bool operator<=(const Dollars &d1, const Dollars &d2) {
    return d1.m_dollars <= d2.m_dollars;
}

bool operator>(const Dollars &d1, const Dollars &d2) {
    return d1.m_dollars > d2.m_dollars;
}

bool operator>=(const Dollars &d1, const Dollars &d2) {
    return d1.m_dollars >= d2.m_dollars;
}

Dollars &Dollars::operator++() {
    ++m_dollars;
    return *this;
}

Dollars &Dollars::operator--() {
    --m_dollars;
    return *this;
}

Dollars Dollars::operator++(int) {
    Dollars dollars(m_dollars);
    ++(*this);
    return dollars;
}

Dollars Dollars::operator--(int) {
    Dollars dollars(m_dollars);
    --(*this);
    return dollars;
}

std::ostream &operator<<(std::ostream &out, const Dollars &dollars) {
    out << dollars.m_dollars;
    return out;
}

Dollars::Dollars(Dollars const &dollars) {
    std::cout << "copy constructor" << std::endl;
    m_dollars = dollars.m_dollars;
}

Dollars &Dollars::operator=(const Dollars &dollars) {
    if (&dollars == this)
        return *this;
    std::cout << "assignment operator" << std::endl;
    m_dollars = dollars.m_dollars;
    return *this;
}


