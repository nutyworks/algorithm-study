#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    deque<int> length;
    stack<int> multiplier;

    string s;
    int wowlen = 0;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        char first = s[i], second = i + 1 == s.size() ? -1 : s[i + 1];

        if (second == '(') {
            multiplier.push(first - '0');
            length.push_back(0);
        } else if (first != '(' && first != ')') {
            length.push_back(1);
        }

        if (first == ')') {
            int l = 0;
            while (length.back() != 0) {
                l += length.back();
                length.pop_back();
            }
            length.pop_back();
            int value = multiplier.top() * l;
            if (value) length.push_back(value);
            multiplier.pop();
        }
    }

    while (!length.empty()) {
        wowlen += length.back();
        length.pop_back();
    }
    
    cout << wowlen;
    
    return 0;
}