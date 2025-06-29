#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
};
void printLast(Node* head, int k)
{
    int count = 0;
    int size = 0;
    Node* temp = head;
    while(temp)
    {
        size ++;
        temp = temp->next;
    }
    Node* tail = head;
    while(count < size - k)
    {
        tail = tail->next;
        count++;
    }
    
    while(tail)
    {
        cout << tail->value << " ";
        tail = tail->next;
    }
}