// Viết chương trình sử dụng chiến lược đệ quy để vẽ ma trận Hadamard như hình dưới. Một ma trận Hadamard kích thước
// 2N×2N
//  có đặc điểm sau: ba góc phần tư là ma trận Hadamard kích thước N×N
// , góc phần tư phải dưới là đảo lại của ma trận Hadamard kích thước N×N
// . Dùng các kí tự ".
// " và "o
// " để in ma trận ra màn hình.

// Đầu vào: số nguyên dương n
//  (n≤5
// ).

// Đầu ra: ma trận Hadamard kích thước N×N
//  (N=2n
// ).
#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr){};
    Node(int data) : val(data), next(nullptr){};
    Node(int data, Node *next) : val(data), next(next){};
};
Node *reverse(Node *head)
{
    if (!head->next)
        return head;
    // Find middle
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slit
    Node *left = head;
    Node *right = slow->next;
    slow->next = nullptr;

    // Merge
    Node *lefreverse = reverse(left);
    Node *rightrever = reverse(right);
    Node *temp = rightrever;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = lefreverse;

    return rightrever;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
Node *removeduplicate(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        while (temp->next && temp->next->val == temp->val)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    return head;
}
Node *insert(Node *head, int x)
{
    Node *dummy = new Node(0, head);
    Node *temp = dummy;
    Node *insert = new Node(x);
    while (temp->next)
    {
        if (temp->next->val >= x)
        {
            break;
        }
        temp = temp->next;
    }
    insert->next = temp->next;
    temp->next = insert;
    return dummy->next;
}
int main()
{
    Node *head = new Node();
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next->next->next = new Node(6);
    print(head);
    cout << endl;
    // Node *reversehead = reverse(head);
    // print(reversehead);
    // cout << endl;
    Node *afterremovedup = removeduplicate(head);
    print(afterremovedup);
    cout << endl;
    Node* afterinsert = insert(head,5);
    print(afterinsert);
}