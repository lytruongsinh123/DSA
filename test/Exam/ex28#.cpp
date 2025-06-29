#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

// Hàm in danh sách
void printList(Node *head)
{
    while (head)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

// Hàm bạn đưa: xóa node cô đơn
Node *deleteSingle(Node *head)
{
    if (!head || (head && !head->next))
    {
        return head;
    }

    // Xóa node đơn ở đầu 
    while (head && head->next && head->value != head->next->value)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp; // tránh rò bộ nhớ
    }

    Node *temp = head;
    while (temp && temp->next)
    {
        // Gặp trùng thì next
        if (temp->next->value == temp->value)
        {
            temp = temp->next;
        }
        // Khác trùng
        else
        {
            // 3 giá trị liên tiếp khác nhau xóa ở giữa
            while (temp->next->next && temp->next->next->value != temp->next->value)
            {
                temp->next = temp->next->next;
            }
            // sau khi xóa xong node cuối và node trước nó khác nhau
            if (!temp->next->next && temp->next->value != temp->value)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
    }
    return head;
}

// Hàm tạo danh sách mẫu: 4 4 7 8 8 8 10 10
Node *createList()
{
    int arr[] = {4, 4, 7, 8, 8, 8, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = new Node{arr[0], nullptr};
    Node *tail = head;

    for (int i = 1; i < n; ++i)
    {
        tail->next = new Node{arr[i], nullptr};
        tail = tail->next;
    }

    return head;
}

// Hàm main
int main()
{
    Node *head = createList();

    cout << "Danh sach ban dau: ";
    printList(head);

    head = deleteSingle(head);

    cout << "Danh sach sau khi xoa node co don: ";
    printList(head);

    return 0;
}
