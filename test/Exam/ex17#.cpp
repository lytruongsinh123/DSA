#include <iostream>
using namespace std;
struct Node {
    int value;
    Node *next;
};
Node* insert(Node* head, int value)
{
    if(!head) return new Node{value, nullptr};
    bool increase = false;
    if(!head->next) increase = true;
    else
    {
        increase = (head->value < head->next->value) ? true : false;
    }
    Node* dummy = new Node {0, head};
    Node* temp = dummy;
    while(temp->next)
    {
        if(temp->next->value > value && increase)
        {
            break;
        }
        if(temp->next->value < value && !increase)
        {
            break;
        }
        temp = temp->next;
    }
    Node* insert = new Node{value, nullptr};
    insert->next = temp->next;
    temp->next = insert;
    return dummy->next;
}
