#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
Node *insertHead(Node *head, int value)
{
    if (!head)
        return new Node{value, nullptr};
    Node *newNode = new Node{value, nullptr};
    newNode->next = head;
    head = newNode;
    return head;
}
Node *insertTail(Node *head, int value)
{
    if (!head)
        return new Node{value, nullptr};
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *newNode = new Node{value, nullptr};
    temp->next = newNode;
    return head;
}
Node *deleteNode(Node *head, int pos)
{
    if (pos == 0)
    {
        head = head->next;
        return head;
    }
    Node *temp = head;
    int cnt;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *todet = temp->next;
    temp->next = temp->next->next;
    delete todet;
    return head;
}
int getValue(Node *head, int pos)
{
    Node *temp = head;
    int cnt = 0;
    while (cnt < pos)
    {
        temp = temp->next;
        cnt++;
    }
    return temp->value; // Change this line
}