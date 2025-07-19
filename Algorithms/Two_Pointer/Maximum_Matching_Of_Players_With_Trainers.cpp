#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, match = 0;

        while (i < players.size() && j < trainers.size())
        {
            if (players[i] <= trainers[j])
            {
                match++;
                i++;
                j++;
            }
            else
            {
                j++; // Trainer quá yếu, thử trainer tiếp theo
            }
        }

        return match;
    }
};
int main()
{
    Solution sol;
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};
    int result = sol.matchPlayersAndTrainers(players, trainers);
    cout << "Maximum matching of players with trainers: " << result << endl;
    return 0;
}