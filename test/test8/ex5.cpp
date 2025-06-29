#include <iostream>
#include <stdexcept>
using namespace std;

class MyVector
{
  private:
    int *arr;   // Con trỏ đến mảng động
    size_t sz;  // Số phần tử hiện có
    size_t cap; // Dung lượng hiện tại

  public:
    MyVector() : arr(nullptr), sz(0), cap(0) {}
    ~MyVector() { delete[] arr; }
    size_t size() const { return sz; }
    size_t capacity() const { return cap; }
    int &operator[](size_t index) { return arr[index]; }
    const int &operator[](size_t index) const { return arr[index]; }
    void push_back(const int &value)
    {
        int *new_arr = new int[cap + 1];

        if (arr == nullptr)
        {
            new_arr[0] = value;
        }
        else
        {
            for (size_t i = 0; i < sz; ++i)
            {
                new_arr[i] = arr[i];
            }
            new_arr[sz] = value;
            delete[] arr;
        }

        arr = new_arr;
        ++cap;
        ++sz;
    }

    void pop_back()
    {
        if (sz == 0)
            return;

        int *new_arr = nullptr;
        if (sz > 1)
        {
            new_arr = new int[cap - 1];
            for (size_t i = 0; i < sz - 1; ++i)
            {
                new_arr[i] = arr[i];
            }
        }

        delete[] arr;
        arr = new_arr;
        --sz;
        --cap;
    }

    void clear()
    {
        delete[] arr;
        arr = nullptr;
        sz = 0;
        cap = 0;
    }
    int *begin() { return arr; }
    int *end() { return arr + sz; }
    const int *begin() const { return arr; }
    const int *end() const { return arr + sz; }
};
