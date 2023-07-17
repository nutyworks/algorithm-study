#include <bits/stdc++.h>

using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

char board[1000][1000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int r, c, xj0, yj0, time = 0;
    bool has_escaped = false;
    queue<tuple<bool, int, int>> q;
    cin >> r >> c;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            cin >> board[y][x];

            if (board[y][x] == 'J') xj0 = x, yj0 = y;
            if (board[y][x] == 'F') q.push({true, x, y});
        }
    }

    q.push({false, xj0, yj0});
    
    do {
        time++;

        int nq = q.size();

        while (nq--) {
            bool isfire;
            int tx, ty;
            tie(isfire, tx, ty) = q.front();
            q.pop();

            if (!isfire && (tx == 0 || tx == c - 1 || ty == 0 || ty == r - 1))
                has_escaped = true;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = tx + dx[dir], ny = ty + dy[dir];
                
                if (board[ny][nx] != '.') continue;
                if (!isfire && board[ny][nx] == 'F') continue;
                if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;

                q.push({isfire, nx, ny});
                board[ny][nx] = isfire ? '#' : 'J';

            }
        }
    } while (!q.empty() && !has_escaped);

    if (has_escaped) cout << time;
    else cout << "IMPOSSIBLE";

    return 0;
}