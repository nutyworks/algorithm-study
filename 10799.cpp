#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int g = 0, cnt = 0;
    char before = ' ';
    string s;

    cin >> s;

    for (char c : s) {
        if (c == '(') g++;
        else if (c == ')') {
            g--;
            if (before == '(') cnt += g;
            else cnt++;
        }
        before = c;
    }

    cout << cnt;

    return 0;
}