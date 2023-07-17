#include <bits/stdc++.h>

using namespace std;

vector<int> selected;
int cnt[8], arr[8];

void select(int max, int depth, int nselect) {
    if (nselect == depth) {
        for (int s : selected) cout << arr[s] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < max; i++) {
        if (!cnt[i]) continue;

        selected.push_back(i);
        cnt[i]--;
        select(max, depth + 1, nselect);
        selected.pop_back();
        cnt[i]++;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int cn = arr[0], ci = 0;

    for (int i = 0; i < n; i++) {
        if (cn != arr[i]) ci++;
        cn = arr[i];

        cnt[ci]++;
        arr[ci] = cn;
    }

    select(ci + 1, 0, m);

    return 0;
}