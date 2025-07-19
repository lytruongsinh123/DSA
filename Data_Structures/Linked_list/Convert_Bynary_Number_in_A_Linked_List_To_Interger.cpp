#include <iostream>
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
    int getDecimalValue(ListNode *head)
    {
        int result = 0;
        while (head != nullptr)
        {
            result = (result << 1) | head->val; // Shift left and add current value
            head = head->next;
        }
        return result;
    }
};
int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    Solution sol;
    int decimalValue = sol.getDecimalValue(head);
    cout << "Decimal value of the binary number in linked list: " << decimalValue << endl;

    // Clean up memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}