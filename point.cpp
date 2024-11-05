#include "point.hpp"

// Constructor cu parametri
Point::Point(int _x, int _y) : x(_x), y(_y) {}

// Constructor de copiere
Point::Point(const Point& other) : x(other.x), y(other.y) {}

// Operator de copiere
Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Operator de comparație
bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

// Operator de citire
std::istream& operator>>(std::istream& in, Point& point) {
    in >> point.x >> point.y;
    return in;
}

// Operator de afișare
std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << point.x << " " << point.y;
    return out;
}

