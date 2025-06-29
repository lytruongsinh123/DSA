#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node
{
    string data;
    Node *next;
    Node() : data(""), next(nullptr) {}
    Node(string s) : data(s), next(nullptr) {}
};

struct Node
{
    string data;
    Node *next;
    Node() : data(""), next(nullptr) {}
    Node(string s) : data(s), next(nullptr) {}
};

class Solution
{
  public:
    string Hash(string s)
    {
        sort(s.begin(), s.end(), greater<char>()); // sắp xếp giảm dần
        return s;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, Node *> a;

        // Khởi tạo danh sách liên kết cho từng nhóm hoán vị
        for (int i = 0; i < strs.size(); i++)
        {
            if (!a[Hash(strs[i])])
            {
                a[Hash(strs[i])] = new Node();
            }
        }

        // Thêm từng từ vào danh sách liên kết tương ứng
        for (int j = 0; j < strs.size(); j++)
        {
            Node *temp = new Node(strs[j]);
            temp->next = a[Hash(strs[j])]->next;
            a[Hash(strs[j])]->next = temp;
        }

        // Duyệt map để thu thập kết quả
        vector<vector<string>> result;
        for (auto &entry : a)
        {
            vector<string> group;
            Node *cur = entry.second->next; // bỏ qua nút đầu "ảo"
            while (cur)
            {
                group.push_back(cur->data);
                cur = cur->next;
            }
            result.push_back(group);
        }

        return result;
    }
};
int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped = sol.groupAnagrams(strs);

    for (const auto &group : grouped)
    {
        for (const string &s : group)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
