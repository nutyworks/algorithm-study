#include <bits/stdc++.h>

using namespace std;

int a[1000];
int c[1000] = {1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int max_c = 0;
        cin >> a[i];
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && c[j] > max_c) {
                max_c = c[j];
            }
        }
        c[i] = max_c + 1;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] > max) max = c[i];
    }

    cout << max;

    return 0;
}