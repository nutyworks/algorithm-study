#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int heightmap[100][100];
char visited[100][100];

void bfs(int x, int y, int n, int h) {
    queue<pair<int, int> > q;

    q.push({x, y});
    visited[y][x] = 1;
    
    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[ny][nx]) continue;
            if (heightmap[ny][nx] <= h) continue;

            q.push({nx, ny});
            visited[ny][nx] = 1;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, max = 0;
    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> heightmap[y][x];
        }
    }

    for (int h = 0; h < 100; h++) {
        int cnt = 0;
        for (int i = 0; i < 100; i++) fill(visited[i], visited[i] + 100, 0);

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (!visited[y][x] && heightmap[y][x] > h) {
                    bfs(x, y, n, h);
                    cnt++;
                }
            }
        }

        if (cnt > max) {
            max = cnt;
        }
    }

    cout << max;

    return 0;
}