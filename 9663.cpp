#include <bits/stdc++.h>

using namespace std;

vector<int> pos;
int cnt = 0;

bool check(int r, int c) {
    for (int i = 0; i < r; i++) {
        if (c == pos[i]) return false;
        if (c + r - i == pos[i]) return false;
        if (c - r + i == pos[i]) return false;
    }

    return true;
}

void queen(int n, int depth) {
    if (n == depth) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!check(depth, i)) continue;
        pos.push_back(i);
        queen(n, depth + 1);
        pos.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    queen(n, 0);
    cout << cnt;

    return 0;
}