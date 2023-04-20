#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/Fraction.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_CASE("ALL + OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    CHECK_NOTHROW(Fraction temp(a+b));
    CHECK_NOTHROW(Fraction temp(b+a));

    CHECK_NOTHROW(Fraction temp(a+num));
    CHECK_NOTHROW(Fraction temp(num+a));

    CHECK_NOTHROW(Fraction temp(b+num));
    CHECK_NOTHROW(Fraction temp(num+b));
}
TEST_CASE("ALL - OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    CHECK_NOTHROW(Fraction temp(a-b));
    CHECK_NOTHROW(Fraction temp(b-a));

    CHECK_NOTHROW(Fraction temp(a-num));
    CHECK_NOTHROW(Fraction temp(num-a));

    CHECK_NOTHROW(Fraction temp(b-num));
    CHECK_NOTHROW(Fraction temp(num-b));
}
TEST_CASE("ALL * OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    CHECK_NOTHROW(Fraction temp(a*b));
    CHECK_NOTHROW(Fraction temp(b*a));

    CHECK_NOTHROW(Fraction temp(a*num));
    CHECK_NOTHROW(Fraction temp(num*a));

    CHECK_NOTHROW(Fraction temp(b*num));
    CHECK_NOTHROW(Fraction temp(num*b));
}
TEST_CASE("ALL / OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    CHECK_NOTHROW(Fraction temp(a/b));
    CHECK_NOTHROW(Fraction temp(b/a));

    CHECK_NOTHROW(Fraction temp(a/num));
    CHECK_NOTHROW(Fraction temp(num/a));

    CHECK_NOTHROW(Fraction temp(b/num));
    CHECK_NOTHROW(Fraction temp(num/b));
}
TEST_CASE("ALL == OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    CHECK_NOTHROW(bool temp = a == b);
    CHECK_NOTHROW(bool temp = b == a);

    CHECK_NOTHROW(bool temp = a == num);
    CHECK_NOTHROW(bool temp = num == a);

    CHECK_NOTHROW(bool temp = b == num);
    CHECK_NOTHROW(bool temp = num == b);
}
TEST_CASE("ALL != OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    bool test;
    CHECK_NOTHROW(test = (a != b));
    CHECK_NOTHROW(test = (b != a));

    CHECK_NOTHROW(test = (a != num));
    CHECK_NOTHROW(test = (num != a));

    CHECK_NOTHROW(test = (b != num));
    CHECK_NOTHROW(test = (num != b));
}
TEST_CASE("ALL > OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    bool test;
    CHECK_NOTHROW(test = (a > b));
    CHECK_NOTHROW(test = (b > a));

    CHECK_NOTHROW(test = (a > num));
    CHECK_NOTHROW(test = (num > a));

    CHECK_NOTHROW(test = (b > num));
    CHECK_NOTHROW(test = (num > b));
}
TEST_CASE("ALL < OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    bool test;
    CHECK_NOTHROW(test = (a < b));
    CHECK_NOTHROW(test = (b < a));

    CHECK_NOTHROW(test = (a < num));
    CHECK_NOTHROW(test = (num < a));

    CHECK_NOTHROW(test = (b < num));
    CHECK_NOTHROW(test = (num < b));
}
TEST_CASE("ALL >= OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    bool test;
    CHECK_NOTHROW(test = (a >= b));
    CHECK_NOTHROW(test = (b >= a));

    CHECK_NOTHROW(test = (a >= num));
    CHECK_NOTHROW(test = (num >= a));

    CHECK_NOTHROW(test = (b >= num));
    CHECK_NOTHROW(test = (num >= b));
}
TEST_CASE("ALL <= OPERATORS")
{
    Fraction a(5,3);
    Fraction b(8,7);
    float num = 3.141; //pi

    // CHECK_THROWS();
    bool test;
    CHECK_NOTHROW(test = (a <= b));
    CHECK_NOTHROW(test = (b <= a));

    CHECK_NOTHROW(test = (a <= num));
    CHECK_NOTHROW(test = (num <= a));

    CHECK_NOTHROW(test = (b <= num));
    CHECK_NOTHROW(test = (num <= b));
}
TEST_CASE("ZERO")
{
    Fraction a(0,1);
    Fraction b(3,4);
    CHECK_THROWS(b/a);

    CHECK_THROWS(Fraction(1,0));
}