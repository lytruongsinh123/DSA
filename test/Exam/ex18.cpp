#include <iostream>
using namespace std;
struct Node 
{
    int value;
    Node *nextNode;
};
Node* moveFirst2Last(Node* head)
{
    if(!head) return nullptr;
    if(head && !head->nextNode) return head;
    Node* tail = head;
    while(tail->nextNode)
    {
        tail = tail->nextNode;
    }
    Node* first = head;
    head = head->nextNode;
    first->nextNode = nullptr;
    tail->nextNode = first;
    return head;
}