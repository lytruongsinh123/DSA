#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
bool compareLists(Node* headA, Node* headB)
{
    Node* temp1 = headA;
    Node* temp2 = headB;
    while(temp1 && temp2)
    {
        if(temp1->value != temp2->value)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1 && !temp2)
    {
        return false;
    }
    if(!temp1 && temp2)
    {
        return false;
    }
    return true;
}