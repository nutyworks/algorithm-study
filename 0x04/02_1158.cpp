#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    list<int> a;
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }

    auto cursor = a.begin();
    cursor--;

    cout << '<';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cursor++;
            if (cursor == a.end()) cursor = a.begin();
        }

        cout << *cursor;
        cursor = a.erase(cursor);
        cursor--;

        if (i + 1 == n) break;

        cout << ", ";
    }

    cout << '>';

    return 0;
}