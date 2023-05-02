#pragma one
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <string>
using namespace std;
namespace ariel
{
    //Note this will be numerator/denominator
    class Fraction
    {
    private:
        int numerator;
        int denominator;
        bool negative;

    public:
        // constructor
        Fraction(int num, int den);//: numerator(num), denominator(den){};
        Fraction();
        /*
            when a float will apear first this will turn it into a fraction
            then it will send it to the operator of fraction x fraction 
        */
       // float conversion constructor
        Fraction(float num);
        // destructor
        void gcd();
        // overloaded operators
        friend Fraction operator+ (const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator- (const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator* (const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator/ (const Fraction& fraction1, const Fraction& fraction2);

        friend Fraction operator+ (const Fraction& fraction1, float num1);
        friend Fraction operator- (const Fraction& fraction1, float num1);
        friend Fraction operator* (const Fraction& fraction1, float num1);
        friend Fraction operator/ (const Fraction& fraction1, float num1);

        friend bool operator==(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator!=(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator>(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator<(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator>=(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator<=(const Fraction& fraction1, const Fraction& fraction2);

        friend bool operator==(const Fraction& fraction1, float num1);
        friend bool operator!=(const Fraction& fraction1, float num1);
        friend bool operator>(const Fraction& fraction1, float num1);
        friend bool operator<(const Fraction& fraction1, float num1);
        friend bool operator>=(const Fraction& fraction1, float num1);
        friend bool operator<=(const Fraction& fraction1, float num1);

        Fraction& operator++(); // prefix
        Fraction operator++(int); // postfix
        Fraction& operator--(); // prefix
        Fraction operator--(int); // postfix

        friend istream& operator>>(istream& Istream, Fraction& fraction);
        friend ostream& operator<<(ostream& Ostream, const Fraction& fraction);

        // operator float() const {
        //     int num = float(this->numerator)*1000;
        //     int den = float(this->denominator)*1000;
        //     return float(num) / float(den);
        // }
        float fraction_to_float(Fraction& fraction);
        operator string() const {
            return to_string(this->numerator)+"/"+to_string(this->denominator);
        }

        //TEST FUNCTIOMS 
        int getNumerator() const
        {
            return this->numerator;
        }
        int getDenominator() const
        {
            return this->denominator;
        }
    };
}