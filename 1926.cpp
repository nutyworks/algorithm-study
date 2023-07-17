#include <bits/stdc++.h>

using namespace std;

const int DX[4] = { -1, 1, 0, 0 };
const int DY[4] = { 0, 0, -1, 1 };

int board[500][500];

int bfs(int board[500][500], int x, int y, int w, int h, int ndrawing) {
    int size = 0;
    queue<pair<int, int> > q;

    q.push({x, y});
    board[y][x] = 0;

    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();
        size++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = tx + DX[dir], ny = ty + DY[dir];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (board[ny][nx] == 0) continue;

            q.push({nx, ny});
            board[ny][nx] = 0;
        }
    }

    return size;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, drawings = 0, max_size = 0;
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> board[y][x];
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (board[y][x] == 1) {
                int size = bfs(board, x, y, m, n, ++drawings);

                if (max_size < size) max_size = size;
            }
        }
    }

    cout << drawings << '\n' << max_size;

    return 0;
}