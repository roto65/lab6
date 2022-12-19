// C++ program to implement
// the above approach

#include <string.h>
#include <vector>
#include <iostream>

#include "big_int.h"

std::string BigInt::getDigits() const {
    return digits;
}
 
BigInt::BigInt(std::string & s) {
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(unsigned long long nr) {
    do{
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}

BigInt::BigInt(const char *s) {
    digits = "";
    for (int i = strlen(s) - 1; i >= 0;i--)
    {
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(BigInt & a) {
    digits = a.digits;
}
 
bool Null(const BigInt& a) {
    if(a.getDigits().size() == 1 && a.getDigits()[0] == 0)
        return true;
    return false;
}

int Length(const BigInt & a) {
    return a.getDigits().size();
}

int BigInt::operator[](const int index)const{
    if(getDigits().size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}

bool operator==(const BigInt &a, const BigInt &b) {
    return a.getDigits() == b.getDigits();
}

bool operator!=(const BigInt & a,const BigInt &b) {
    return !(a == b);
}

bool operator<(const BigInt&a,const BigInt&b) {
    int n = Length(a), m = Length(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.getDigits()[n] != b.getDigits()[n])
            return a.getDigits()[n] < b.getDigits()[n];
    return false;
}

bool operator>(const BigInt&a,const BigInt&b) {
    return b < a;
}

bool operator>=(const BigInt&a,const BigInt&b) {
    return !(a < b);
}

bool operator<=(const BigInt&a,const BigInt&b) {
    return !(a > b);
}
 
BigInt &BigInt::operator=(const BigInt &a) {
    digits = a.digits;
    return *this;
}
 
BigInt &BigInt::operator++() {
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9;i++)
        digits[i] = 0;
    if(i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}

BigInt BigInt::operator++(int temp) {
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}
 
BigInt &BigInt::operator--() {
    if(digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n;i++)
        digits[i] = 9;
    digits[i]--;
    if(n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}

BigInt BigInt::operator--(int temp) {
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}
 
BigInt &operator+=(BigInt &a,const BigInt& b) {
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if(m > n)
        a.getDigits().append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.getDigits()[i] + b.getDigits()[i]) + t;
        else
            s = a.getDigits()[i] + t;
        t = s / 10;
        a.getDigits()[i] = (s % 10);
    }
    if(t)
        a.getDigits().push_back(t);
    return a;
}

BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}
 
BigInt &operator-=(BigInt&a,const BigInt &b) {
    if(a < b)
        throw("UNDERFLOW");
    int n = Length(a), m = Length(b);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.getDigits()[i] - b.getDigits()[i]+ t;
        else
            s = a.getDigits()[i]+ t;
        if(s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        a.getDigits()[i] = s;
    }
    while(n > 1 && a.getDigits()[n - 1] == 0)
        a.getDigits().pop_back(),
        n--;
    return a;
}

BigInt operator-(const BigInt& a,const BigInt&b) {
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}
 
BigInt &operator*=(BigInt &a, const BigInt &b) {
    if(Null(a) || Null(b)){
        a = BigInt();
        return a;
    }
    int n = a.getDigits().size(), m = b.getDigits().size();
    std::vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            v[i + j] += (a.getDigits()[i] ) * (b.getDigits()[j]);
        }
    n += m;
    a.getDigits().resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.getDigits()[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--)
            a.getDigits().pop_back();
    return a;
}

BigInt operator*(const BigInt&a,const BigInt&b) {
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}
 
BigInt &operator/=(BigInt& a,const BigInt &b) {
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        a = BigInt();
        return a;
    }
    if(a == b){
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    std::vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.getDigits()[i]  < b;i--){
        t *= 10;
        t += a.getDigits()[i] ;
    }
    for (; i >= 0; i--){
        t = t * 10 + a.getDigits()[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.getDigits().resize(cat.size());
    for (i = 0; i < lgcat;i++)
        a.getDigits()[i] = cat[lgcat - i - 1];
    a.getDigits().resize(lgcat);
    return a;
}

BigInt operator/(const BigInt &a,const BigInt &b){
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}
 
BigInt &operator%=(BigInt& a,const BigInt &b) {
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        return a;
    }
    if(a == b){
        a = BigInt();
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    std::vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.getDigits()[i] < b;i--){
        t *= 10;
        t += a.getDigits()[i];
    }
    for (; i >= 0; i--){
        t = t * 10 + a.getDigits()[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}

BigInt operator%(const BigInt &a,const BigInt &b) {
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}
 
BigInt &operator^=(BigInt & a,const BigInt & b) {
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while(!Null(Exponent)){
        if(Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}

BigInt operator^(BigInt & a,BigInt & b) {
    BigInt temp(a);
    temp ^= b;
    return temp;
}
 
void divide_by_2(BigInt & a) {
    int add = 0;
    for (int i = a.getDigits().size() - 1; i >= 0;i--){
        int digit = (a.getDigits()[i] >> 1) + add;
        add = ((a.getDigits()[i] & 1) * 5);
        a.getDigits()[i] = digit;
    }
    while(a.getDigits().size() > 1 && !a.getDigits().back())
        a.getDigits().pop_back();
}

BigInt sqrt(BigInt & a) {
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_2(right);
    while(left <= right){
        mid += left;
        mid += right;
        divide_by_2(mid);
        prod = (mid * mid);
        if(prod <= a){
            v = mid;
            ++mid;
            left = mid;
        }
        else{
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}
 
BigInt NthCatalan(int n) {
    BigInt a(1),b;
    for (int i = 2; i <= n;i++)
        a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n;i++)
        b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}
 
BigInt NthFibonacci(int n) {
    BigInt a(1), b(1), c;
    if(!n)
        return c;
    n--;
    while(n--){
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}
 
BigInt Factorial(int n) {
    BigInt f(1);
    for (int i = 2; i <= n;i++)
        f *= i;
    return f;
}
 
std::istream &operator>>(std::istream &in,BigInt&a) {
    std::string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.getDigits()[n - i - 1] = s[i];
    }
    return in;
}
 
std::ostream &operator<<(std::ostream &out,const BigInt &a) {
    for (int i = a.getDigits().size() - 1; i >= 0;i--)
        std::cout << (short)a.getDigits()[i];
    return std::cout;
}
