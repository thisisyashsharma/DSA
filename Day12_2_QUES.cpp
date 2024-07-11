#include <iostream>
using namespace std;

class Queue{
public:

}

void pop(){
    if(front == -1 || front > rear){
        cout << "No elements in queue" << endl;
        return ;
    }
    front++;
};

int main(){
    cout << "alskdjf";
}