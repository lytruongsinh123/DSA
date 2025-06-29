#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double MAX_DISTANT = 1.0; 

class Point {
    double x, y;
  public:
    Point (double _x, double _y) {
        x = _x; y = _y;
    }
    
    // Viết phương thức isClosed ở đây
    bool isClosed(Point p)
    {
        double distance = sqrt( pow((this->x - p.x), 2) + pow((this->y - p.y), 2) );
        return distance <= 1.0;
    }
};

int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

    Point p1(x1, y1), p2(x2, y2);
    cout << boolalpha << (p1.isClosed(p2));

	return 0;
}