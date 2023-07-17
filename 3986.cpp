#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<char> stk;

    int tc, cnt = 0;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;

        if (s.size() & 1) continue;

        for (char c : s) {
            if (!stk.empty() && stk.back() == c) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }

        if (stk.empty()) cnt++;
        stk.clear();
    }

    cout << cnt;

    return 0;
}