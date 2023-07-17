#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> q;
    int n;
    
    cin >> n;
    while (n--) {
        string op;
        cin >> op;

        if (op == "push") {
            int k;
            cin >> k;
            q.push(k);
        } else if (op == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (op == "size") {
            cout << q.size() << '\n';
        } else if (op == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if (op == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
            }
        } else if (op == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}