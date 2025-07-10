#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class FindSumPairs
{
  private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

  public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int x : nums2)
            freq2[x]++;
    }

    void add(int index, int val)
    {
        int oldVal = nums2[index];
        freq2[oldVal]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot)
    {
        int result = 0;
        for (int x : nums1)
        {
            int need = tot - x;
            if (freq2.count(need))
                result += freq2[need];
        }
        return result;
    }
};
int mian()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {6, 7, 8, 9, 10};
    FindSumPairs fsp(nums1, nums2);
    fsp.add(0, 1);                // nums1 becomes [2, 2, 3, 4, 5]
    cout << fsp.count(8) << endl; // returns 3
    fsp.add(1, 2);                // nums1 becomes [2, 4, 3, 4, 5]
    cout << fsp.count(8) << endl; // returns 2
    return 0;
}
