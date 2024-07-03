//Date - 02 JULY 2024

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insertAtTail(Node *head, int key) {
    Node *newNode = new Node(key);

    if (!head) {
        head = newNode;  
        return;
    }

    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void printReverse(Node *head) {
    if (!head) return;

    Node *temp = head;
    while (temp->next) temp = temp->next;

    while (temp) {
        cout << temp->data << " <- ";
        temp = temp->prev;
    }
    cout << endl;
}





int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    
    insertAtTail(head, 3);
    printReverse(head);

    return 0;
}
