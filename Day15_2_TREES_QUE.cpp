#include <iostream>
using namespace std;

//BST
class Node{
public:
    int data;
    Node *l;
    Node *r;
    Node(int data){
        this->data = data;
        l=NULL;
        r=NULL;
    }
};


Node* insert(Node* R , int x){
    if(!R) return new Node(x);

    if(x > R->data){
        R->r = insert(R->r ,x);
    }else if( x < R->data){
        R->l = insert(R->l ,x);
    }
};

void inOrder(Node *R){
    if(!R) return;
    inOrder(R->l);
    cout << R->data << " ";
    inOrder(R->r);
}


int main(){
    Node *R = new Node(1);
    R = insert(R,7);
    R = insert(R,2); 
    R = insert(R,4);
    R = insert(R,3);
    R = insert(R,5);
    R = insert(R,6);

    inOrder(R);
    cout << endl;
     
    
}