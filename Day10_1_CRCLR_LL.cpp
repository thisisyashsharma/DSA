#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};


void insertInTail(Node *head, int key){
   Node *temp = head;

   while(temp->next != head){
        temp = temp->next;
   }
   
}

void insertAtBeginning(Node *head , int key){
    Node *temp = head;

    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new Node(key);
    head = temp->next->next;
}

void display(Node *head){
    Node *temp = head;
    
    while(true){
        cout << temp->data << " -> " ; 
        temp = temp->next;
        if(temp == head) break;
    }
    cout << endl;
}

void deletionAtPosition(Node *head , int pos){
    Node *temp = head;
    int count  = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }  
    Node *del = temp->next;
    temp->next = temp->next->next;
    delete(del);
}

void deleteHead(Node *head ){
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    
    Node *target = temp->next;
    temp->next = head->next;
    delete(target);
}




int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    display(head);
    deletionAtPosition(head,2);
    display(head);
    deleteHead(head);
    display(head);
}