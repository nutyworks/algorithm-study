#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int board[100][100];
int time_taken[100][100];

void bfs_number(int area, int n, int x, int y) {
    queue<pair<int, int> > q;

    q.push({x, y});
    board[y][x] = area;

    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[ny][nx] != 1) continue;

            q.push({nx, ny});
            board[ny][nx] = area;
        }
    }
}

int bfs_bridge(int area, int n) {
    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++) fill(time_taken[i], time_taken[i] + n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == area)
                q.push({j, i});
        }
    }

    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[ny][nx] == area) continue;
            if (time_taken[ny][nx] > -1) continue;

            q.push({nx, ny});
            time_taken[ny][nx] = time_taken[ty][tx] + 1;
        }
    }

    int min = 1002;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || time_taken[i][j] == -1) continue;
            if (time_taken[i][j] < min) min = time_taken[i][j];
        }
    }

    return min;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, areas = 0, min = 1002;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                bfs_number(--areas, n, j, i);
            }
        }
    }

    for (int i = -1; i >= areas; i--) {
        int result = bfs_bridge(i, n);
        if (result < min) min = result;
    }

    cout << min;

    return 0;
}