#include <iostream>
#include <stack>
using namespace std;
class MinStack
{
  private:
    stack<int> mainStack;
    stack<int> minStack;

  public:
    MinStack()
    {
        // Constructor initializes empty stacks
    }

    void push(int val)
    {
        mainStack.push(val);
        // Push the smaller value between val and current min
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }

    void pop()
    {
        if (!mainStack.empty())
        {
            mainStack.pop();
            minStack.pop();
        }
    }

    int top() { return mainStack.top(); }

    int getMin() { return minStack.top(); }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
}