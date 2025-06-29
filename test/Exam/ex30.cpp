#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node *deleteNode(Node *head, int pos) 
{
    if(pos == 0) return head = head->next;
    Node* temp = head;
    int cnt = 0;
    while(cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node* todel = temp->next;
    temp->next = todel->next;
    delete todel;
    return head;
}