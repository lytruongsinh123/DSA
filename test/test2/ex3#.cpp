#include <iostream>
using namespace std;
#include <numeric>
class Fraction {
    int a, b;
public:
    Fraction(int a = 1, int b = 1);
    friend ostream& operator<<(ostream& os, const Fraction& f);
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    void simplify();
    bool operator>(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
};
Fraction::Fraction(int a, int b)
{
    this->a = a;
    this->b = b;
}
ostream& operator<<(ostream& os, const Fraction& f)
{
    if(f.b == 0)
    {
        cout << "invalid";
        return os;
    }
    cout << f.a << "/" << f.b << endl;
    return os;
}
void Fraction::simplify()
{
    int ucln = gcd(this->a, this->b);
    this->a = this->a / ucln;
    this->b = this->b / ucln;
}
Fraction Fraction::operator+(const Fraction& f) const
{
    Fraction result;
    result.a = this->a * f.b + this->b * f.a;
    result.b = this->b * f.b;
    result.simplify();
    return result;
}
Fraction Fraction::operator-(const Fraction& f) const
{
    Fraction result;
    result.a = this->a * f.b - this->b * f.a;
    result.b = this->b * f.b;
    result.simplify();
    return result;
}
Fraction Fraction::operator*(const Fraction& f) const
{
    Fraction result;
    result.a = this->a * f.a;
    result.b = this->b * f.b;
    result.simplify();
    return result;
}
Fraction Fraction::operator/(const Fraction& f) const
{
    Fraction result;
    result.a = this->a * f.b;
    result.b = this->b * f.a;
    result.simplify();
    return result;
}
bool Fraction::operator>(const Fraction& f) const
{
    Fraction temp = *this - f;
    if(temp.a*temp.b > 0)
    {
        return true;
    }
    return false;
}
bool Fraction::operator<(const Fraction& f) const
{
    Fraction temp = *this - f;
    if(temp.a*temp.b < 0)
    {
        return true;
    }
    return false;
}