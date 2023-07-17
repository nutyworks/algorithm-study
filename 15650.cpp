#include <bits/stdc++.h>

using namespace std;

vector<int> selected;

void select(int max, int depth, int nselect) {
    if (nselect == depth) {
        for (int s : selected) cout << s << ' ';
        cout << '\n';
        return;
    }

    int i = depth ? selected.back() + 1 : 1;

    for (; i <= max - nselect + depth + 1; i++) {
        selected.push_back(i);
        select(max, depth + 1, nselect);
        selected.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    select(n, 0, m);

    return 0;
}