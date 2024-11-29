#include "../include/point.hpp"
#include <cassert>

int main() {
    // Test constructor și operator==
    Point p1(0, 0), p2(1, 1);
    assert(!(p1 == p2));  // Punctele sunt diferite

    // Test operator=
    p1 = p2;
    assert(p1 == p2);  // Acum punctele sunt egale

    // Test constructor de copiere
    Point p3(p1);
    assert(p3 == p1);

    return 0;
}
