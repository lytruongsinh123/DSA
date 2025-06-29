#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
bool find(Node* head, int x)
{
    Node* temp = head;
    while(temp)
    {
        if(temp->value == x)
        {
            return true;
            break;
        }
        temp = temp->next;
    }
    return false;
}
Node* deleteDuplicates(Node* head)
{
    if(!head || (head && !head->next)) return head;
    Node* result = new Node{head->value, nullptr};
    Node* rear = result;
    Node* temp = head->next;
    while(temp)
    {
        if(!find(result, temp->value))
        {
            rear->next = new Node{temp->value, nullptr};
            rear = rear->next;
        }
        temp = temp->next;
    }
    return result;
}
