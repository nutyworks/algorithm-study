#include <bits/stdc++.h>

using namespace std;

char board[12][6];
bool visited[12][6];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y, bool remove) {
    queue<pair<int, int>> q;
    int cnt = 0;
    int p0 = board[y][x];

    q.push({x, y});
    visited[y][x] = true;

    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();

        if (remove) board[ty][tx] = '.';
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];

            if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12) continue;
            if (board[ny][nx] != p0) continue;
            if (visited[ny][nx]) continue;

            q.push({nx, ny});
            visited[ny][nx] = true;
        }
    }

    return cnt;
}

bool puyo() {
    bool has_puyo = false;

    for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) {
        visited[i][j] = false;
    }

    for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) {
        if (board[i][j] != '.') {
            int size = bfs(j, i, false);
            if (size >= 4) {
                for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) {
                    visited[i][j] = false;
                }
                has_puyo = true;
                bfs(j, i, true);
            }
        }
    }

    for (int r = 0; r < 11; r++) {
        for (int i = 11; i > 0; i--) for (int j = 0; j < 6; j++) {
            if (board[i][j] == '.') {
                board[i][j] = board[i - 1][j];
                board[i - 1][j] = '.';
            }
        }
    }

    return has_puyo;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt = 0;

    for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) {
        cin >> board[i][j];
    }

    while (puyo()) cnt++;

    cout << cnt;

    return 0;
}