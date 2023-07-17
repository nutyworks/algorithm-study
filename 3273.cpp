#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x, cnt = 0;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    cin >> x;

    sort(v.begin(), v.end());

    for (int e : v) {
        if (binary_search(v.begin(), v.end(), x - e)) cnt++;
    }

    cout << cnt / 2;

    return 0;
}