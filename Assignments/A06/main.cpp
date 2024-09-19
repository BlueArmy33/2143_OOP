/*
Andrea Lobo
CMPS 2143
9/18/2024
Program 1
Add, subtract, multiply, divide, or compare fractions
*/

#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Function for calculation GCD
    int gcd(int a, int b) const 
    {
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    // Function for calculating LCM
    int lcm(int a, int b) const 
    {
        return (a * b) / gcd(a, b);
    }

    // Fraction reduction
    void reduce() 
    {
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
public:
    // Default Constructor
    Fraction() : numerator(0), denominator(1) {}

    // COnstructor with parameters
    Fraction(int num, int den) : numerator(num), denominator(den) 
    {
        if (denominator == 0) 
        {
            cerr << "Error: Denominator cannot be zero." << endl;
            denominator = 1;
        }
        reduce();
    }

    //Adding
    Fraction operator+(const Fraction& other) const 
    {
        int common_denominator = lcm(denominator, other.denominator);
        int new_numerator = numerator * (common_denominator / denominator) + other.numerator * (common_denominator / other.denominator);
        return Fraction(new_numerator, common_denominator);
    }

    //Subtract
    Fraction operator-(const Fraction& other) const 
    {
        int common_denominator = lcm(denominator, other.denominator);
        int new_numerator = numerator * (common_denominator / denominator) - other.numerator * (common_denominator / other.denominator);
        return Fraction(new_numerator, common_denominator);
    }

    //Multiplying
    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    //Dividing
    Fraction operator/(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    //See if the compared fractions are the same
    bool operator==(const Fraction& other) const 
    {
        int common_denominator = lcm(denominator, other.denominator);
        int this_numerator = numerator * (common_denominator / denominator);
        int other_numerator = other.numerator * (common_denominator / other.denominator);
        return this_numerator == other_numerator;
    }
    friend ostream& operator<<(ostream& os, const Fraction& frac);
};

//outstream factor
ostream& operator<<(ostream& os, const Fraction& frac) 
{
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

// Function for reading fraction in "a/b"
Fraction readFraction(int num, int den) 
{
    return Fraction(num, den);
}
int main() 
{
    // Manual lecture of txt
    int num1, den1, num2, den2;
    char op, slash;

    // Lines from the fractions
    while (cin >> num1 >> slash >> den1 >> op >> num2 >> slash >> den2) 
    {
        Fraction frac1 = readFraction(num1, den1);
        Fraction frac2 = readFraction(num2, den2);

        switch (op) 
        {
        case '+':
            cout << frac1 << " + " << frac2 << " = " << (frac1 + frac2) << endl;
            break;
        case '-':
            cout << frac1 << " - " << frac2 << " = " << (frac1 - frac2) << endl;
            break;
        case '*':
            cout << frac1 << " * " << frac2 << " = " << (frac1 * frac2) << endl;
            break;
        case '/':
            cout << frac1 << " / " << frac2 << " = " << (frac1 / frac2) << endl;
            break;
        case '=':
            if (frac1 == frac2) {
                cout << frac1 << " == " << frac2 << " -> True" << endl;
            }
            else {
                cout << frac1 << " == " << frac2 << " -> False" << endl;
            }
            break;
        default:
            cerr << "Error: Operator not recognized" << endl;
            break;
        }
    }

    return 0;
}
