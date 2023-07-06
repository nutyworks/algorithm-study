#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--) {
        int cnt = n + 1;

        while (cnt--) cout << '*';

        cout << '\n';
    }

    return 0;
}