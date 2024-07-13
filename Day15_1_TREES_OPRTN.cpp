#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* l;
    Node* r;
    Node(int data) {
        this->data = data;
        this->l = NULL;
        this->r = NULL;
    }
};

void rightView(Node* R) {
    if (!R) return;

    queue<Node*> q;
    q.push(R);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            Node* x = q.front();
            q.pop();

            if (i == n - 1) {
                cout << x->data << " ";
            }

            if (x->l) {
                q.push(x->l);
            }
            if (x->r) {
                q.push(x->r);
            }
        }
    }
}

int main() {
    Node* R = new Node(1);
    R->l = new Node(2);
    R->r = new Node(3);
    R->l->l = new Node(4);
    R->l->r = new Node(5);
    R->r->l = new Node(6);
    R->r->r = new Node(7);

    rightView(R);
    return 0;
}
