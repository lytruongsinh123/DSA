#include <iostream>
using namespace std;
struct Rectangle {
    int height;
    int length;
    // Hai ham khoi tao
    Rectangle() : height(0), length(0) {};
    Rectangle(int a, int b)
    {
        height = a;
        length = b;
    }
    int getPerimeter() {
        // your code goes here
        int peri = (this->height + this->length) * 2;
        return peri;
    }
    void print()
    {
        for(int i = 0; i < this->height; i++)
        {
            for(int j = 0; j < this->length; j++)
            {
                if(i == 0 || i == this->height - 1)
                {
                    cout << "*";
                }
                else
                {
                    if(j == 0 || j == this->length - 1)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
    }
};
int compare(Rectangle a, Rectangle b) {
    if(a.getPerimeter() < b.getPerimeter()) return -1;
    if(a.getPerimeter() > b.getPerimeter()) return 1;
    return 0;
}