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

    public:
        // constructor
        Fraction(int num, int den);//: numerator(num), denominator(den){};
        /*
            when a float will apear first this will turn it into a fraction
            then it will send it to the operator of fraction x fraction 
        */
       // float conversion constructor
        Fraction(float num);
        // destructor
        ~Fraction();
        void gcd();
        // overloaded operators
        friend Fraction operator+ (const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator- (const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator* (const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator/ (const Fraction& fraction1, const Fraction& fraction2);

        friend Fraction operator+ (const Fraction& fraction1, const float num1);
        friend Fraction operator- (const Fraction& fraction1, const float num1);
        friend Fraction operator* (const Fraction& fraction1, const float num1);
        friend Fraction operator/ (const Fraction& fraction1, const float num1);

        friend bool operator==(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator!=(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator>(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator<(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator>=(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator<=(const Fraction& fraction1, const Fraction& fraction2);

        friend bool operator==(const Fraction& fraction1, const float num1);
        friend bool operator!=(const Fraction& fraction1, const float num1);
        friend bool operator>(const Fraction& fraction1, const float num1);
        friend bool operator<(const Fraction& fraction1, const float num1);
        friend bool operator>=(const Fraction& fraction1, const float num1);
        friend bool operator<=(const Fraction& fraction1, const float num1);

        Fraction& operator++(); // prefix
        Fraction operator++(int); // postfix
        Fraction& operator--(); // prefix
        Fraction operator--(int); // postfix

        friend istream& operator>>(istream& is, Fraction& fraction);
        friend ostream& operator<<(ostream& os, const Fraction& fraction);//good

        // operator double() const {
        //     // cout << "converting Fraction to double" << endl;
        //     return double(this->numerator) / double(this->denominator);
        // }
        
        operator string() const {
            return to_string(this->numerator)+"/"+to_string(this->denominator);
        }

    };
}