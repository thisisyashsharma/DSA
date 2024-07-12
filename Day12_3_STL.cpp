#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front ele: " << q.front() << endl;
    cout << "Back ele: " << q.back() << endl;

    q.pop();

    cout << "Front ele after dequeue: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;

    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    q.pop();
    q.pop();

    if (q.empty()) {
        cout << "Queue is empty now" << endl;
    }

    return 0;
}
