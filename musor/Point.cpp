#include "Point.h"

double distanceFrom(const Point &p1, const Point &p2) {
    return sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "Point(" << point.m_x << ", " << point.m_y << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Point &point) {
    in >> point.m_x >> point.m_y;
    return in;
}
