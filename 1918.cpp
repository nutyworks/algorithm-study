#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    char c;
    stack<char> op;
    
    while (true) {
        cin >> c;
        if (cin.eof()) break;
        
        switch (c) {
            case '+': case '-': {
                while (!op.empty() && (op.top() == '*' || op.top() == '/' || op.top() == '+' || op.top() == '-')) {
                    cout << op.top();
                    op.pop();
                }
                op.push(c);
                break;
            }
            case '*': case '/': {
                while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                    cout << op.top();
                    op.pop();
                }
                op.push(c);
                break;
            }
            case '(': {
                op.push(c);
                break;
            }
            case ')': {
                while (op.top() != '(') {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
                break;
            }
            default: {
                cout << c;
            }
        }
    }

    while (!op.empty()) {
        cout << op.top();
        op.pop();
    }

    return 0;
}