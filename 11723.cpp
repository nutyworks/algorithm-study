#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    bool set[21] = {};
    int n;

    cin >> n;

    while (n--) {
        string op;

        cin >> op;

        if (op == "add") {
            int t;
            cin >> t;
            set[t] = true;
        } else if (op == "remove") {
            int t;
            cin >> t;
            set[t] = false;
        } else if (op == "check") {
            int t;
            cin >> t;
            cout << (set[t] ? 1 : 0) << '\n';
        } else if (op == "toggle") {
            int t;
            cin >> t;
            set[t] = !set[t];
        } else if (op == "all") {
            for (int i = 1; i <= 20; i++) set[i] = true;
        } else if (op == "empty") {
            for (int i = 1; i <= 20; i++) set[i] = false;
        }
    }

    return 0;
}