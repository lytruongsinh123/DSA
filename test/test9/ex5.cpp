#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
vector<int> linkedListToVector(Node *head)
{
    vector<int> result;
    Node *temp = head;
    while (temp)
    {
        result.push_back(temp->value);
        temp = temp->next;
    }
    return result;
}

Node *vectorToLinkedList(vector<int> values)
{
    Node *front = new Node{0, nullptr};
    Node *rear = front;
    for (unsigned int i = 0; i < values.size(); i++)
    {
        Node *insert = new Node{values[i], nullptr};
        rear->next = insert;
        rear = rear->next;
    }
    return front->next;
}