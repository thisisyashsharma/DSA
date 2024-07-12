#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prefixNotation(string x) {
    stack<int> s;
    for (int i = x.length() - 1; i >= 0; i--) { // Iterate from the end of the string
        if (isdigit(x[i])) {
            s.push(x[i] - '0');
        } else {
            int o1 = s.top();
            s.pop();
            int o2 = s.top();
            s.pop();
            switch (x[i]) {
                case '+':
                    s.push(o1 + o2);
                    break;
                case '-':
                    s.push(o1 - o2);
                    break;
                case '*':
                    s.push(o1 * o2);
                    break;
                case '/':
                    s.push(o1 / o2);
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    string expression = "*+23+12";
    cout << "The result of the prefix expression " << expression << " is: " << prefixNotation(expression) << endl;
    return 0;
}
