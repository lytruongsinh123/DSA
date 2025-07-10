#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1) current->next = l1;
        if (l2) current->next = l2;

        return dummy->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        ListNode* mergedList = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            mergedList = mergeTwoLists(mergedList, lists[i]);
        }
        return mergedList;
    }
};
int main()
{
    Solution s;
    vector<ListNode *> lists;
    // Example usage: Create some linked lists and add them to the vector
    ListNode *list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *list3 = new ListNode(2, new ListNode(6));
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    // Call the mergeKLists function
    ListNode *mergedList = s.mergeKLists(lists);

    // Print the merged list (for demonstration purposes)
    while (mergedList)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    return 0;
}