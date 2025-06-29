#include <iostream>
using namespace std;
struct Node
{
    Node *next;
    int data;
};
struct LinkedList
{
    Node *head, *tail;
};
void deleteDuplicates(LinkedList* listFull)
{
    if (listFull == nullptr || listFull->head == nullptr)
        return;

    Node* temp = listFull->head;

    while (temp)
    {
        while (temp->next && temp->data == temp->next->data)
        {
            Node* dup = temp->next;
            temp->next = temp->next->next;
            delete dup;
        }
        temp = temp->next;
    }

    // Cập nhật lại tail sau khi xóa
    Node* t = listFull->head;
    while (t && t->next)
    {
        t = t->next;
    }
    listFull->tail = t;
}
