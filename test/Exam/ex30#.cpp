#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
};

Node* rotate(Node* head, int k)
{
    if(!head || (head && !head->next)) return head;
    if( k == 0) return head;
    Node* temp = head;
    int cnt = 0;
    while(cnt < k - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node* left = head;
    Node* right = temp->next;
    temp->next = nullptr;

    Node* temp2 = right;
    while(temp2->next)
    {
        temp2 = temp2->next;
    }
    temp2->next = left;
    return right;
}