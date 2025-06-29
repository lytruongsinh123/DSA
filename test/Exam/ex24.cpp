#include <iostream>
using namespace std;
class Node {
    int value;
public:
    Node* next;
    Node* prev;
    int getValue() {
        return value;
    }
};
Node* sort(Node* head) {
    if (!head || !head->next) return head; // Danh sách rỗng hoặc chỉ có một phần tử
    for(Node* temp = head->next; temp != nullptr; temp = temp->next)
    {
        Node* key = temp;
        Node* temp2;
        for(temp2 = temp->prev; temp2 != nullptr; temp = temp->prev)
        {
            if(key->getValue() < temp2->getValue())
            {
                temp2->next = temp->next;
                temp->next->prev = temp2;
            }
        }
        key->next = temp2;
        temp2->prev = key;
    }
}
