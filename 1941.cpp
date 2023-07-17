#include <bits/stdc++.h>

using namespace std;

char sts[5][5], conn[7][7];
vector<pair<int, int> > selected;
int cnt = 0;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool is_connected() {
    for (auto s : selected) {
        int x, y;
        tie(x, y) = s;
        conn[y + 1][x + 1] = 1;
    }

    queue<pair<int, int> > q;
    int tx, ty, conns = 0;
    tie(tx, ty) = selected.front();

    q.emplace(tx + 1, ty + 1);
    conn[ty + 1][tx + 1] = 2;

    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();
        conns++;

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];
            
            if (conn[ny][nx] != 1) continue;

            q.emplace(nx, ny);
            conn[ny][nx] = 2;
        }
    }

    for (auto s : selected) {
        int x, y;
        tie(x, y) = s;
        conn[y + 1][x + 1] = 0;
    }

    return conns == 7;
}

void select(int depth, int i, int ns) {
    if (ns < depth - 3) return;
    if (depth == 7 && is_connected()) {
        cnt++;
        return;
    }

    for (; i < 25; i++) {
        int y = i / 5, x = i % 5;
        int iss = sts[y][x] == 'S';
        selected.emplace_back(x, y);
        select(depth + 1, i + 1, ns + iss);
        selected.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> sts[i][j];
        }
    }

    select(0, 0, 0);
    cout << cnt;

    return 0;
}