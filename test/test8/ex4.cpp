#include <iomanip>
#include <iostream>

using namespace std;
struct Time
{
    int h;
    int m;
    int s;
    Time() : h(0), m(0), s(0){};
    Time(int h_, int m_, int s_)
    {
        this->h = h_;
        this->m = m_;
        this->s = s_;
    }
    int second() { return h * 60 * 60 + m * 60 + s; }
    void print() { cout << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << endl; }
};
Time normalize(int h, int m, int s)
{
    // your code goes here
    Time result;
    int thuas = 0;
    while (s >= 60)
    {
        thuas++;
        s -= 60;
    }
    m = thuas + m;
    int thuam = 0;
    while (m >= 60)
    {
        thuam++;
        m -= 60;
    }
    result.s = s;
    result.m = m;
    result.h = (h + thuam >= 24) ? h + thuam - 24 : h + thuam;
    return result;
}