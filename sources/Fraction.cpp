#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <string>

#include "Fraction.hpp"
using namespace std;
namespace ariel
{
    void Fraction::gcd()
    {
        int a = this->numerator;
        int b = this->denominator;
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = abs(a);
        if(gcd != 0)
        {
            this->numerator/=gcd;
            this->denominator/=gcd;
        }
    }
    //Note this will be numerator/denominator
    // constructor
    Fraction::Fraction(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->gcd();
    }
    /*
        1/3 in float is translated to 0.333
        witch is 0.333*1000/1000
    */
    Fraction::Fraction(float num)
    {
        this->numerator = num*1000;
        this->denominator = 1000;

    }
    // destructor
    Fraction::~Fraction() {}
    // overloaded operators
    // Fraction Fraction +-*/
    Fraction operator+ (const Fraction& fraction1, const Fraction& fraction2)
    {
        int new_numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
        int new_denominator = fraction1.denominator * fraction2.denominator;
        Fraction temp = Fraction(new_numerator, new_denominator);
        temp.gcd();
        return temp;
    }
    Fraction operator- (const Fraction& fraction1, const Fraction& fraction2)
    {
        int new_numerator = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
        int new_denominator = fraction1.denominator * fraction2.denominator;
        Fraction temp = Fraction(new_numerator, new_denominator);
        temp.gcd();
        return temp;
    }
    Fraction operator* (const Fraction& fraction1, const Fraction& fraction2)
    {
        int new_numerator = fraction1.numerator *  fraction2.numerator;
        int new_denominator = fraction1.denominator * fraction2.denominator;
        Fraction temp = Fraction(new_numerator, new_denominator);
        temp.gcd();
        return temp;
    }
    Fraction operator/ (const Fraction& fraction1, const Fraction& fraction2)
    {
        int new_numerator = fraction1.numerator *  fraction2.denominator;
        int new_denominator = fraction1.denominator * fraction2.numerator;
        Fraction temp = Fraction(new_numerator, new_denominator);
        temp.gcd();
        return temp;
    }
    // Fraction float +-*/
    Fraction operator+ (const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        return fraction1 + f_num;
    }
    Fraction operator- (const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        return fraction1 - f_num;
    }
    Fraction operator* (const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        return fraction1 * f_num;
    }
    Fraction operator/ (const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        return fraction1 / f_num;
    }
    // Fraction Fraction == != > < >= <=
    bool operator==(const Fraction& fraction1, const Fraction& fraction2)
    {
        Fraction temp1(fraction1.numerator,fraction1.denominator);
        temp1.gcd();
        Fraction temp2(fraction2.numerator,fraction2.denominator);
        temp2.gcd();

        if(temp1.numerator == temp2.numerator && temp1.denominator == temp2.denominator)// && (double)temp1 == (double)temp2)
        {
            return true;
        }
        return false;
    }
    bool operator!=(const Fraction& fraction1, const Fraction& fraction2)
    {
        Fraction temp1(fraction1.numerator,fraction1.denominator);
        temp1.gcd();
        Fraction temp2(fraction2.numerator,fraction2.denominator);
        temp2.gcd();

        if(temp1.numerator != temp2.numerator && temp1.denominator != temp2.denominator)// && (double)temp1 != (double)temp2)
        {
            return true;
        }
        return false;
    }
    bool operator>(const Fraction& fraction1, const Fraction& fraction2)
    {
        Fraction temp1(fraction1.numerator,fraction1.denominator);
        temp1.gcd();
        Fraction temp2(fraction2.numerator,fraction2.denominator);
        temp2.gcd();

        if(temp1.numerator > temp2.numerator && temp1.denominator > temp2.denominator)// && (double)temp1 > (double)temp2)
        {
            return true;
        }
        return false;
    }
    bool operator<(const Fraction& fraction1, const Fraction& fraction2)
    {
        Fraction temp1(fraction1.numerator,fraction1.denominator);
        temp1.gcd();
        Fraction temp2(fraction2.numerator,fraction2.denominator);
        temp2.gcd();

        if(temp1.numerator < temp2.numerator && temp1.denominator < temp2.denominator)// && (double)temp1 < (double)temp2)
        {
            return true;
        }
        return false;
    }
    bool operator>=(const Fraction& fraction1, const Fraction& fraction2)
    {
        Fraction temp1(fraction1.numerator,fraction1.denominator);
        temp1.gcd();
        Fraction temp2(fraction2.numerator,fraction2.denominator);
        temp2.gcd();

        if(temp1.numerator >= temp2.numerator && temp1.denominator >= temp2.denominator)// && (double)temp1 >= (double)temp2)
        {
            return true;
        }
        return false;
    }
    bool operator<=(const Fraction& fraction1, const Fraction& fraction2)
    {
        Fraction temp1(fraction1.numerator,fraction1.denominator);
        temp1.gcd();
        Fraction temp2(fraction2.numerator,fraction2.denominator);
        temp2.gcd();

        if(temp1.numerator <= temp2.numerator && temp1.denominator <= temp2.denominator)// && (double)temp1 <= (double)temp2)
        {
            return true;
        }
        return false;
    }
    // Fraction float == != > < >= <=
    bool operator==(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        f_num.gcd();
        Fraction temp(fraction1.numerator,fraction1.denominator);
        temp.gcd();
        if(temp.numerator == f_num.numerator && temp.denominator == f_num.denominator)// && (double)temp == (double)f_num)
        {
            return true;
        }
        return false;
    }
    bool operator!=(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        f_num.gcd();
        Fraction temp(fraction1.numerator,fraction1.denominator);
        temp.gcd();
        if(temp.numerator != f_num.numerator && temp.denominator != f_num.denominator)// && (double)temp != (double)f_num)
        {
            return true;
        }
        return false;
    }
    bool operator>(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        f_num.gcd();
        Fraction temp(fraction1.numerator,fraction1.denominator);
        temp.gcd();
        if(temp.numerator > f_num.numerator && temp.denominator > f_num.denominator)// && (double)temp > (double)f_num)
        {
            return true;
        }
        return false;
    }
    bool operator<(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        f_num.gcd();
        Fraction temp(fraction1.numerator,fraction1.denominator);
        temp.gcd();
        if(temp.numerator < f_num.numerator && temp.denominator < f_num.denominator)// && (double)temp < (double)f_num)
        {
            return true;
        }
        return false;
    }
    bool operator>=(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        f_num.gcd();
        Fraction temp(fraction1.numerator,fraction1.denominator);
        temp.gcd();
        if(temp.numerator >= f_num.numerator && temp.denominator >= f_num.denominator)// && (double)temp >= (double)f_num)
        {
            return true;
        }
        return false;
    }
    bool operator<=(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        f_num.gcd();
        Fraction temp(fraction1.numerator,fraction1.denominator);
        temp.gcd();
        if(temp.numerator <= f_num.numerator && temp.denominator <= f_num.denominator)// && (double)temp <= (double)f_num)
        {
            return true;
        }
        return false;
    }
    // prefix //++this
    Fraction& Fraction::operator++()
    {
        this->numerator += this->denominator;
        this->gcd();
        return *this;
    }
    // postfix //this++
    Fraction Fraction::operator++(int)
    {
        Fraction temp = *this;
        this->numerator += this->denominator;
        this->gcd();
        return temp;
    }
    // prefix //++this
    Fraction& Fraction::operator--()
    {
        this->numerator -= this->denominator;
        this->gcd();
        return *this;
    }
    // postfix //this++
    Fraction Fraction::operator--(int)
    {
        Fraction temp = *this;
        this->numerator -= this->denominator;
        this->gcd();
        return temp;
    }
    istream& operator>>(istream& is, Fraction& fraction)
    {
        is >> fraction.numerator >> fraction.denominator;
        return is;
    }
    ostream& operator<<(ostream& os, const Fraction& fraction)
    {
	    return os << fraction.numerator << '/' << fraction.denominator;
    }
}