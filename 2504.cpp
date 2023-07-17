#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> stk;
    char c;
    bool fail = false;

    while (true) {
        cin >> c;

        if (cin.eof()) break;

        if (c == '(') {
            stk.push_back(0);
        } else if (c == '[') {
            stk.push_back(1);
        } else if (c == ')') {
            if (stk.empty()) { fail = true; break; }

            int sum = 0;

            while (!stk.empty() && stk.back() >= 2) {
                sum += stk.back();
                stk.pop_back();
            }

            if (stk.empty()) { fail = true; break; }
            if (stk.back() == 1) { fail = true; break; }

            if (!stk.empty()) {
                stk.pop_back();
                stk.push_back(sum ? 2 * sum : 2);
            } else {
                stk.push_back(sum);
            }
        } else if (c == ']') {
            if (stk.empty()) { fail = true; break; }

            int sum = 0;

            while (!stk.empty() && stk.back() >= 2) {
                sum += stk.back();
                stk.pop_back();
            }

            if (stk.empty()) { fail = true; break; }
            if (stk.back() == 0) { fail = true; break; }

            if (!stk.empty()) {
                stk.pop_back();
                stk.push_back(sum ? 3 * sum : 3);
            } else {
                stk.push_back(sum);
            }
        }
    }

    int result = 0;
    while (!stk.empty()) {
        if (stk.back() < 2) fail = true;
        result += stk.back();
        stk.pop_back();
    }

    cout << (fail ? 0 : result);

    return 0;
}