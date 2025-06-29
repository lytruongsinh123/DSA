#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
};
Node* convert(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head1 = head;
    Node* head2 = slow->next;
    slow->next = nullptr;

    Node* p1 = head1;
    Node* p2 = head2;
    while(p2 && p1)
    {
        Node* tmp1 = p1->next;
        Node* tmp2 = p2->next;
        p1->next = p2;
        if(tmp1) p2->next = tmp1;
        p1 = tmp1;
        p2 = tmp2;
    }
    return head1;
}