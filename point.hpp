#pragma once
#include <iostream>
#include <memory>

struct Point {
    int x;
    int y;

    // Constructor implicit
    Point(int _x = 0, int _y = 0);
    
    // Constructor de copiere
    Point(const Point& other);
    
    // Operator de copiere
    Point& operator=(const Point& other);
    
    // Operator de comparație
    bool operator==(const Point& other) const;
};

// Operator de citire
std::istream& operator>>(std::istream& in, Point& point);

// Operator de afișare
std::ostream& operator<<(std::ostream& out, const Point& point);
