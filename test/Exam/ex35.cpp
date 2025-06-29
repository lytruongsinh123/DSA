#include <iostream>
#include <cmath>
using namespace std;
struct Point
{
    double x, y;
    Point();
    Point(double, double);
    Point(const Point &);
};

class Triangle
{
    Point p1, p2, p3;

  public:
    Triangle(const Point &, const Point &, const Point &);
    double getPerimeter() const;
    double getArea() const;
};
// Point
Point::Point() : x(0), y(0){};
Point::Point(const Point &A)
{
    x = A.x;
    y = A.y;
}
Point::Point(double a, double b)
{
    x = a;
    y = b;
}

// Triangle::
Triangle::Triangle(const Point &a, const Point &b, const Point &c) 
{
    p1 = a;
    p2 = b;
    p3 = c;
}
double Triangle::getPerimeter() const
{
    double AB = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
    double AC = sqrt(pow(p2.x - p3.x,2) + pow(p2.y - p3.y,2));
    double BC = sqrt(pow(p1.x - p3.x,2) + pow(p1.y - p3.y,2));
    return AB + AC + BC;
}
double Triangle::getArea() const
{
    double p = this->getPerimeter() / 2.0;
    double AB = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
    double AC = sqrt(pow(p2.x - p3.x,2) + pow(p2.y - p3.y,2));
    double BC = sqrt(pow(p1.x - p3.x,2) + pow(p1.y - p3.y,2));
    return sqrt(p*(p - AB)*(p - AC)*(p - BC));
}