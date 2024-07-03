//Date - 02 JULY 2024

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertInTail(Node *&head, int key);
void insertAtBeginning(Node *&head, int key);
void display(Node *head);
void deletionAtPosition(Node *&head, int pos);
void deleteHead(Node *&head);

void insertInTail(Node *&head, int key) {
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    Node *newNode = new Node(key);
    temp->next = newNode;
    newNode->next = head;
}

void insertAtBeginning(Node *&head, int key) {
    Node *newNode = new Node(key);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void display(Node *head) {
    if (head == NULL) return;
    Node *temp = head;
    while (true) {
        cout << temp->data << " -> ";
        temp = temp->next;
        if (temp == head) break;
    }
    cout << "head" << endl;
}

void deletionAtPosition(Node *&head, int pos) {
    if (head == NULL) return;
    Node *temp = head;
    if (pos == 1) {
        deleteHead(head);
        return;
    }
    int count = 1;
    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }
    Node *del = temp->next;
    temp->next = del->next;
    delete del;
}

void deleteHead(Node *&head) {
    if (head == NULL) return;
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    Node *target = head;
    if (head->next == head) { 
        head = NULL;
    } else {
        temp->next = head->next;
        head = head->next;
    }
    delete target;
}

int main() {
    Node *head = new Node(1);
    head->next = head; 
    
    insertInTail(head, 2);
    insertInTail(head, 3);
    insertInTail(head, 4);

    display(head);

    deletionAtPosition(head, 2);
    display(head);

    deleteHead(head);
    display(head);

    return 0;
}
