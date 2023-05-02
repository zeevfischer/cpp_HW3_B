#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <vector>
#include <string>
#include <numeric>

#include "Fraction.hpp"
using namespace std;
namespace ariel
{   //helper function
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
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
    float fraction_to_float(Fraction& fraction)
    {
        float num = fraction.getNumerator();
        float den = fraction.getDenominator();
        int temp = (num/den) * 1000;
        return float(temp)/1000;
    }
    //Note this will be numerator/denominator
    // constructor
    Fraction::Fraction()
    {
        this->negative = false;
        this->numerator = 0;
        this->denominator = 1;
    }
    Fraction::Fraction(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->gcd();

        if(numerator < 0)
        {
            this->negative = true;
        }
        else if(denominator < 0)
        {
            this->negative = true;
            //put the negative on the numerator
            this->numerator = this->numerator - (2 * this->numerator);
            this->denominator = (-2 * this->denominator) + this->denominator;
        }
        if(numerator < 0 && denominator < 0)
        {
            this->numerator = abs(this->numerator);
            this->denominator = abs(this->denominator);
            this->negative = false;
        }
        this->negative = false;
    }
    /*
        1/3 in float is translated to 0.333
        witch is 0.333*1000/1000
    */
    Fraction::Fraction(float num)
    {
        this->numerator = num*1000;
        this->denominator = 1000;
        if(this->numerator != 0)
        {
            this->gcd();
        }

    }
    // overloaded operators
    ////////////////////////////////////// Fraction Fraction +-*/
    void exeption(int a,int b,char c)
    {
        switch(c) {
        case '+':
            if((a > 0 && b > 0 && (a+b < 0)) || (a < 0 && b < 0 && (a+b > 0)))
            {
                throw overflow_error("overflow error");
            }
            break;
        case '*':
            if(a != 0 && b != 0)
            {
                int temp = a*b;
                if((a != temp / b) || (b != temp / a))
                {
                    throw overflow_error("overflow error");
                }
            }
            break;
        }
    }
    Fraction operator+ (const Fraction& fraction1, const Fraction& fraction2)
    {
        if(fraction1.denominator == fraction2.denominator)
        {
            int new_numerator = fraction1.numerator + fraction2.numerator;
            exeption(fraction1.numerator,fraction2.numerator,'+');
            Fraction temp(new_numerator , fraction1.denominator);
            temp.gcd();

            return temp;
        }
        else
        {
            int LCM = lcm(fraction1.denominator , fraction2.denominator);
            int part1 = (LCM / fraction1.denominator) * fraction1.numerator;
            exeption(LCM / fraction1.denominator,fraction1.numerator,'*');
            int part2 = (LCM / fraction2.denominator) * fraction2.numerator;
            exeption(LCM / fraction2.denominator,fraction2.numerator,'*');
            int new_numerator = part1 + part2;
            exeption(part1,part2,'+');
            Fraction temp(new_numerator , LCM);
            temp.gcd();
            
            return temp;
        }
    }
    Fraction operator- (const Fraction& fraction1, const Fraction& fraction2)
    {
        if(fraction2.numerator < 0)
        {
            int temp = fraction2.numerator * (-1);
            if(fraction2.numerator == min_int)
            {
                temp = max_int;
            }
            Fraction positive_f2(temp,fraction2.denominator);
            return fraction1 + positive_f2;
        }
        if(fraction1.denominator == fraction2.denominator)
        {
            int new_numerator = fraction1.numerator - fraction2.numerator;
            Fraction temp(new_numerator , fraction1.denominator);
            temp.gcd();

            return temp;
        }
        else
        {
            int LCM = lcm(fraction1.denominator , fraction2.denominator);
            int part1 = (LCM / fraction1.denominator) * fraction1.numerator;
            exeption(LCM / fraction1.denominator,fraction1.numerator,'*');
            int part2 = (LCM / fraction2.denominator) * fraction2.numerator;
            exeption(LCM / fraction2.denominator,fraction2.numerator,'*');
            int new_numerator = part1 - part2;
            exeption(part1,part2,'-');
            Fraction temp(new_numerator , LCM);
            temp.gcd();
            
            return temp;
        }
    }
    Fraction operator* (const Fraction& fraction1, const Fraction& fraction2)
    {
        int new_numerator = fraction1.numerator *  fraction2.numerator;
        exeption(fraction1.numerator,fraction2.numerator,'*');
        int new_denominator = fraction1.denominator * fraction2.denominator;
        exeption(fraction1.denominator,fraction2.denominator,'*');
        Fraction temp = Fraction(new_numerator, new_denominator);
        temp.gcd();

        return temp;
    }
    Fraction operator/ (const Fraction& fraction1, const Fraction& fraction2)
    {
        if(fraction2.numerator == 0)
        {
            throw runtime_error("fraction2 is zero and we cand devide by zero !!");
        }
        Fraction temp(fraction2.denominator ,fraction2.numerator);
        return fraction1 * temp;
    }
    ////////////////////////////////////// Fraction float +-*/
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
        // no need to check devision by zero the / operator for fraction fraction will check that
        Fraction f_num(num1);
        return fraction1 / f_num;
    }
    ////////////////////////////////////// Fraction Fraction == != > < >= <=
    bool operator==(const Fraction& fraction1, const Fraction& fraction2)
    {
        Fraction temp1(fraction1.numerator,fraction1.denominator);
        temp1.gcd();
        Fraction temp2(fraction2.numerator,fraction2.denominator);
        temp2.gcd();
        if(temp1.numerator == temp2.numerator && temp1.denominator == temp2.denominator)
        {
            return true;
        }
        else if(fraction_to_float(temp1) == fraction_to_float(temp2))
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

        if(temp1.numerator != temp2.numerator || temp1.denominator != temp2.denominator)// && (double)temp1 != (double)temp2)
        {
            return true;
        }
        return false;
    }
    bool operator>(const Fraction& fraction1, const Fraction& fraction2)
    {
        if(fraction1.denominator == fraction2.denominator)
        {
            if(fraction1.numerator > fraction2.numerator)
            {
                return true;
            }
        }
        else
        {
            int temp1_numerator = fraction1.numerator*fraction2.denominator;
            int temp2_numerator = fraction2.numerator*fraction1.denominator;

            if(temp1_numerator > temp2_numerator)
            {
                return true;
            }
        }
        return false;
    }
    bool operator<(const Fraction& fraction1, const Fraction& fraction2)
    {
        if(fraction1.denominator == fraction2.denominator)
        {
            if(fraction1.numerator < fraction2.numerator)
            {
                return true;
            }
        }
        else
        {
            int temp1_numerator = fraction1.numerator*fraction2.denominator;
            int temp2_numerator = fraction2.numerator*fraction1.denominator;

            if(temp1_numerator < temp2_numerator)
            {
                return true;
            }
        }
        return false;
    }
    bool operator>=(const Fraction& fraction1, const Fraction& fraction2)
    {
        if(fraction1.denominator == fraction2.denominator)
        {
            if(fraction1.numerator >= fraction2.numerator)
            {
                return true;
            }
        }
        else
        {
            int temp1_numerator = fraction1.numerator*fraction2.denominator;
            int temp2_numerator = fraction2.numerator*fraction1.denominator;

            if(temp1_numerator >= temp2_numerator)
            {
                return true;
            }
        }
        return false;
    }
    bool operator<=(const Fraction& fraction1, const Fraction& fraction2)
    {
       if(fraction1.denominator == fraction2.denominator)
        {
            if(fraction1.numerator <= fraction2.numerator)
            {
                return true;
            }
        }
        else
        {
            int temp1_numerator = fraction1.numerator*fraction2.denominator;
            int temp2_numerator = fraction2.numerator*fraction1.denominator;

            if(temp1_numerator <= temp2_numerator)
            {
                return true;
            }
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

        // cout << fraction_to_float(temp) << endl;
        if(temp.numerator == f_num.numerator && temp.denominator == f_num.denominator)
        {
            return true;
        }
        else if(fraction_to_float(temp) == num1)
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
        if(temp.numerator != f_num.numerator || temp.denominator != f_num.denominator)
        {
            return true;
        }
        return false;
    }
    bool operator>(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        if(fraction1.denominator == f_num.denominator)
        {
            if(fraction1.numerator > f_num.numerator)
            {
                return true;
            }
        }
        else
        {
            int temp1_numerator = fraction1.numerator*f_num.denominator;
            int temp2_numerator = f_num.numerator*fraction1.denominator;

            if(temp1_numerator > temp2_numerator)
            {
                return true;
            }
        }
        return false;

    }
    bool operator<(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        if(fraction1.denominator == f_num.denominator)
        {
            if(fraction1.numerator < f_num.numerator)
            {
                return true;
            }
        }
        else
        {
            int temp1_numerator = fraction1.numerator*f_num.denominator;
            int temp2_numerator = f_num.numerator*fraction1.denominator;

            if(temp1_numerator < temp2_numerator)
            {
                return true;
            }
        }
        return false;
    }
    bool operator>=(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        if(fraction1.denominator == f_num.denominator)
        {
            if(fraction1.numerator >= f_num.numerator)
            {
                return true;
            }
        }
        else
        {
            int temp1_numerator = fraction1.numerator*f_num.denominator;
            int temp2_numerator = f_num.numerator*fraction1.denominator;

            if(temp1_numerator >= temp2_numerator)
            {
                return true;
            }
        }
        return false;
    }
    bool operator<=(const Fraction& fraction1, const float num1)
    {
        Fraction f_num(num1);
        if(fraction1.denominator == f_num.denominator)
        {
            if(fraction1.numerator <= f_num.numerator)
            {
                return true;
            }
        }
        else
        {
            int temp1_numerator = fraction1.numerator*f_num.denominator;
            int temp2_numerator = f_num.numerator*fraction1.denominator;

            if(temp1_numerator <= temp2_numerator)
            {
                return true;
            }
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
        int num ,den;
        char c;
        if(is >> num >> den)
        {
            if(den == 0)
            {
                throw runtime_error("invalid input");
            }
            Fraction temp(num,den);
            fraction.numerator = temp.numerator;
            fraction.denominator = temp.denominator;
        }
        else if(is >> num >> c >> den)
        {
            if(c == '/' || c == ',')
            {
                Fraction temp(num,den);
                fraction.numerator = temp.numerator;
                fraction.denominator = temp.denominator;
            }
        }
        else
        {
            throw runtime_error("invalid input");
        }
        return is;
    }
    ostream &operator<<(ostream &os, const Fraction &fraction)
    {
	    return os << fraction.numerator << '/' << fraction.denominator;
    }
}