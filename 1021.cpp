#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> d;
    int n, m, cnt = 0;
    cin >> n >> m;

    for (int j = 0; j < m; j++) {
        int t;
        cin >> t;
        d.push_back(t - 1);
    }

    for (int j = 0; j < m; j++, n--) {
        int to_take = d[j];
        int left = to_take;
        int right = n - to_take;

        if (left < right) {
            cnt += left;

            for (int i = j; i < m; i++) {
                d[i] = (d[i] + n - left) % n - 1;
            }
        } else {
            cnt += right;

            for (int i = j; i < m; i++) {
                d[i] = (d[i] + right) % n - 1;
            }
        }
    }

    cout << cnt;

    return 0;
}