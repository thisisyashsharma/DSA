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


bool search(Node *head , int key){
    if(head==NULL) return false;
    
    Node *temp = head;

    while(temp){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    
    return false;
}

void insertAtHead(Node *&head , int x){
    Node *newNode  = new Node(x);
    
    if(!head){
        head->next = newNode;
        return ;
    }

    newNode->next = head;
    head = newNode; 
    return;
}

void display(Node *head){
    Node *x = head;
    while(x){
        cout << " "<<  x->data << " ->";
        x = x->next;
    }
    cout << endl;
}

void deletion(Node *head , int key){
    Node *temp = head;
    while(temp->next->data == key){
        temp = temp->next;
    }
    Node *target = temp->next;
    temp->next = target->next;
    delete target;

}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    bool ans = search(head,3);
    cout << "Result : " << ans << endl;


    display(head);    
    insertAtHead(head,7);
    display(head);    
    deletion(head,3);
    display(head);

}


