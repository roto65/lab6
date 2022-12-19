#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
#include <string>

class BigInt{
    private:
        std::string digits;
        

    public:
        std::string getDigits() const;
        //Constructors:
        BigInt(unsigned long long n = 0);
        BigInt(std::string &);
        BigInt(const char *);
        BigInt(BigInt &);
    
        //Helper Functions:
        int operator[](const int)const;

        /* * * * Operator Overloading * * * */
    
        //Direct assignment
        BigInt &operator=(const BigInt &);
    
        //Post/Pre - Incrementation
        BigInt &operator++();
        BigInt operator++(int temp);
        BigInt &operator--();
        BigInt operator--(int temp);
    
};
    //Addition and Subtraction
    BigInt &operator+=(BigInt &, const BigInt &);
    BigInt operator+(const BigInt &, const BigInt &);
    BigInt operator-(const BigInt &, const BigInt &);
    BigInt &operator-=(BigInt &, const BigInt &);

    //Comparison operators
    bool operator==(const BigInt &, const BigInt &);
    bool operator!=(const BigInt &, const BigInt &);

    bool operator>(const BigInt &, const BigInt &);
    bool operator>=(const BigInt &, const BigInt &);
    bool operator<(const BigInt &, const BigInt &);
    bool operator<=(const BigInt &, const BigInt &);

    //Multiplication and Division
    BigInt &operator*=(BigInt &, const BigInt &);
    BigInt operator*(const BigInt &, const BigInt &);
    BigInt &operator/=(BigInt &, const BigInt &);
    BigInt operator/(const BigInt &, const BigInt &);

    //Modulo
    BigInt operator%(const BigInt &, const BigInt &);
    BigInt &operator%=(BigInt &, const BigInt &);

    //Power Function
    BigInt &operator^=(BigInt &,const BigInt &);
    BigInt operator^(BigInt &, const BigInt &);
    
    //Square Root Function
    BigInt sqrt(BigInt &a);

    //Read and Write
    std::ostream &operator<<(std::ostream &,const BigInt &);
    std::istream &operator>>(std::istream &, BigInt &);

    //Helper Functions:
    void divide_by_2(BigInt &a);
    bool Null(const BigInt &);
    int Length(const BigInt &);    

    //Others
    BigInt NthCatalan(int n);
    BigInt NthFibonacci(int n);
    BigInt Factorial(int n);

#endif // BIG_INT_H