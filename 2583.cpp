#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int board[100][100];

int bfs(int board[100][100], int x0, int y0, int w, int h) {
    int cnt = 0;
    queue<pair<int, int> > q;

    q.push({x0, y0});
    board[y0][x0] = 1;

    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();
        cnt++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = tx + dx[dir], ny = ty + dy[dir];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (board[ny][nx]) continue;

            q.push({nx, ny});
            board[ny][nx] = 1;
        }
    }

    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<pair<int, int> > q;
    vector<int> area;
    int m, n, k, cnt = 0;

    cin >> m >> n >> k;

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                board[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (board[y][x] == 0) {
                area.push_back(bfs(board, x, y, n, m));
                cnt++;
            }
        }
    }

    sort(area.begin(), area.end());

    cout << cnt << '\n';

    for (int a : area) {
        cout << a << ' ';
    }

    return 0;
}