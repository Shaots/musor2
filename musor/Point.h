//
// Created by Lenovo on 04.06.2024.
//

#ifndef TEST_POINT_H
#define TEST_POINT_H

#include <iostream>
#include <cmath>

class Point {
public:
    Point(double x = 0.0, double y = 0.0)
            : m_x(x), m_y(y) {}

    void print() const {
        std::cout << "Point(" << m_x << " , " << m_y << ")\n";
    }

    double distanceTo(Point &p) {
        return sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
    }

    friend std::ostream &operator<<(std::ostream &out, const Point &point);

    friend std::istream& operator>> (std::istream &in, Point &point);

    friend double distanceFrom(const Point &p1, const Point &p2);

private:
    double m_x;
    double m_y;
};


#endif