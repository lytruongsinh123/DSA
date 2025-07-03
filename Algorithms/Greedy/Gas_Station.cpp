#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalGas = 0, totalCost = 0, currentGas = 0;
        int startIndex = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            // If current gas is negative, reset the start index
            if (currentGas < 0)
            {
                startIndex = i + 1;
                currentGas = 0;
            }
        }

        // If total gas is less than total cost, return -1
        return (totalGas < totalCost) ? -1 : startIndex;
    }
};
int main()
{
    Solution solution;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = solution.canCompleteCircuit(gas, cost);
    cout << "Starting station index: " << result << endl;

    return 0;
}