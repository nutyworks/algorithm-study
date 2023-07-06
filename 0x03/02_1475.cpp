#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, cnt[10] = { 0, }, max = 0;
    cin >> n;

    do cnt[n % 10]++; while (n /= 10);

    cnt[6] += cnt[9];
    cnt[6] = (cnt[6] + 1) / 2;

    for (int i = 0; i < 9; i++) {
        if (max < cnt[i]) max = cnt[i];
    }

    cout << max;

    return 0;
}