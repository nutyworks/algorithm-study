#include <bits/stdc++.h>

using namespace std;

int visited[200003];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<pair<int, int> > q;

    int n, k, time = 0;
    cin >> n >> k;

    q.push({n, 0});
    visited[n] = 1;

    while (!q.empty()) {
        int p, t;
        tie(p, t) = q.front();
        q.pop();

        if (p == k) {
            time = t;
            break;
        }

        if (p * 2 < 200003 && !visited[p * 2]) {
            q.push({p * 2, t});
            visited[p * 2] = 1;
        }
        if (p > 0 && !visited[p - 1]) {
            q.push({p - 1, t + 1});
            visited[p - 1] = 1;
        }
        if (p < 200002 && !visited[p + 1]) {
            q.push({p + 1, t + 1});
            visited[p + 1] = 1;
        }
    }

    cout << time;

    return 0;
}