#include <iostream>
using namespace std;
struct Node {
    const int value; // Hằng thành viên
    Node* next;
    Node(int value) : value(value), next(nullptr) {};
};

class LinkedList {
    Node *head;
public:
    LinkedList() : head(nullptr) {};
    LinkedList(int a[], int n)
    {
        Node* dummy = new Node(0);
        Node* rear = dummy;
        for(int i = 0; i < n; i++)
        {
            Node* newNode = new Node(a[i]);
            rear->next = newNode;
            rear = rear->next;
        }
        head = dummy->next;
    }
    void insertHead(int value)
    {
        if(!head) head = new Node(value);
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void print()
    {
        Node* temp = head;
        while(temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
};