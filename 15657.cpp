#include <bits/stdc++.h>

using namespace std;

vector<int> selected;
int arr[8];

void select(int max, int depth, int nselect, int i) {
    if (nselect == depth) {
        for (int s : selected) cout << s << ' ';
        cout << '\n';
        return;
    }

    for (; i < max; i++) {
        selected.push_back(arr[i]);
        select(max, depth + 1, nselect, i);
        selected.pop_back();
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
    select(n, 0, m, 0);

    return 0;
}