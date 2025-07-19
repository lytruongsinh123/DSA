#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution
{
  public:
    vector<string> removeSubfolders(vector<string> &folder) {
        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> result;

        for (const string &f : folder)
        {
            bool isSubfolder = false;
            for (int i = 1; i < f.size(); ++i)
            {
                if (f[i] == '/' && folderSet.count(f.substr(0, i)) > 0)
                {
                    isSubfolder = true;
                    break;
                }
            }
            if (!isSubfolder)
            {
                result.push_back(f);
            }
        }

        return result;
    }
};
int main()
{
    Solution sol;
    vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}; // Example input
    vector<string> result = sol.removeSubfolders(folder);
    
    cout << "Remaining folders after removing subfolders:" << endl;
    for (const string &f : result)
    {
        cout << f << endl;
    }
    
    return 0;
}