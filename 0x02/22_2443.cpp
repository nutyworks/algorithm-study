#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << ' ';
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}