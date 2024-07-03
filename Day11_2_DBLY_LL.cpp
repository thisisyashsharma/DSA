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


void insertAtTail(Node *head , int key){
    Node *newNode = new Node(key);
    
    if(!head){
        head = newNode ;
        return ;
    }
    
    Node *temp = head;
    while(temp){
        temp = temp->next;
    }
    temp ->next = newNode ;
    newNode->prev = temp;
}

void printReverse(Node *head){
   Node *temp = head;
   while(temp){
    temp=temp->next;
   }
    
   while(temp){
    cout << temp->data << "<-";
    temp=temp->prev;
   }


}



int main(){
     Node *head = new Node(1);
     head->next = new Node(2);
     head->next->prev = head->next;
       

}