#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
  private:
    bool visited[10000] = {false};

  public:
    vector<int> Square(int n)
    {
        vector<int> result;
        for (int i = 1; i * i <= n; i++) // fix: tạo số chính phương ≤ n
        {
            result.push_back(i * i);
        }
        return result;
    }

    int numSquares(int n)
    {
        vector<int> square = Square(n);
        vector<bool> visited(n + 1, false);
        vector<int> distance(n + 1, 0);

        queue<int> Q;
        Q.push(n);
        visited[n] = true;

        while (!Q.empty())
        {
            int top = Q.front();
            Q.pop();

            for (int i = 0; i < square.size(); i++)
            {
                int v = top - square[i];
                if (v < 0)
                    continue;

                if (v == 0)
                    return distance[top] + 1;

                if (!visited[v])
                {
                    Q.push(v);
                    visited[v] = true;
                    distance[v] = distance[top] + 1;
                }
            }
        }

        return -1;
    }
};
int main()
{
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = sol.numSquares(n);
    cout << "The least number of perfect squares that sum to " << n << " is: " << result << endl;
    return 0;
}
