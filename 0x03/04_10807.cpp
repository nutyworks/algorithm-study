#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, n, v, a[201] = { 0, };
    int *p = a + 100;
    cin >> n;

    while (n--) {
        cin >> t;
        p[t]++;
    }

    cin >> v;

    cout << p[v];

    return 0;
}