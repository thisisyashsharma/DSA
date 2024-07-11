#include <iostream>
using namespace std;

class MyStack{
   public:
   int *a;
   int top;
   int size;

   MyStack(int size){
    this->size = size;
    a = new int[size];
    top = -1;
   }

   void push(int val);
   int peek();
};

void MyStack::push(int val){
    if(top == size - 1){
        cout << "Stack overflow" << endl;
        return;
    }
    a[++top] = val;
}

int MyStack::peek(){
    if(top == -1){
        cout << "Stack is empty" << endl;
        return -1; 
    }
    return a[top];
}

int main(){
    MyStack stack(5);
    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.peek() << endl; 
    return 0;
}
