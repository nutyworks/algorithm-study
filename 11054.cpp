#include <bits/stdc++.h>

using namespace std;

int a[1000];
int ca[1000] = {1};
int cb[1000] = {1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int max_ca = 0, max_cb = 0;
        cin >> a[i];
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                max_ca = max(ca[j], max_ca);
            }
            if (a[j] > a[i]) {
                max_cb = max({ca[j], cb[j], max_cb});
            }
        }
        ca[i] = max_ca + 1;
        cb[i] = max_cb + 1;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (ca[i] > max) max = ca[i];
        if (cb[i] > max) max = cb[i];
    }

    cout << max;

    return 0;
}