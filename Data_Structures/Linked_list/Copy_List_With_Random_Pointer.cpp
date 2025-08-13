#include <iostream>
using namespace std;

class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // Bước 1: Chèn node copy vào giữa các node gốc
        Node *curr = head;
        while (curr)
        {
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Bước 2: Gán random cho node copy
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Bước 3: Tách danh sách
        curr = head;
        Node *copyHead = head->next;
        while (curr)
        {
            Node *copy = curr->next;
            curr->next = copy->next;
            if (copy->next)
                copy->next = copy->next->next;
            curr = curr->next;
        }

        return copyHead;
    }
};

// Hàm in danh sách (val + random)
void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << "Node val: " << curr->val;
        if (curr->random)
            cout << ", Random points to: " << curr->random->val;
        else
            cout << ", Random points to: null";
        cout << endl;
        curr = curr->next;
    }
}

int main()
{
    // Tạo các node
    Node *n1 = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(11);
    Node *n4 = new Node(10);
    Node *n5 = new Node(1);

    // Gán next
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Gán random
    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    // Sao chép danh sách
    Solution solution;
    Node *copiedList = solution.copyRandomList(n1);

    cout << "=== Danh sách gốc ===" << endl;
    printList(n1);

    cout << "\n=== Danh sách sao chép ===" << endl;
    printList(copiedList);

    return 0;
}
