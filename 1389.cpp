#include <bits/stdc++.h>

using namespace std;

int bacons[101];
vector<int> friendship[101];

int get_bacon(int n) {
    int visited[101] = {};

    int step = 0, sum = 0;
    queue<int> q;
    visited[n] = 1;
    q.push(n);

    while (!q.empty()) {
        int nq = q.size();

        while (nq--) {
            int nf = q.front();
            q.pop();

            for (int t : friendship[nf]) {
                if (visited[t]) continue;

                visited[t] = step + 1;
                q.push(t);
            }
        }

        step++;
    }

    for (int i = 1; i <= 100; i++) {
        sum += visited[i];
    }

    return sum - 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, r, mv = 10000, mi = -1;
    cin >> n >> r;

    while (r--) {
        int a, b;
        cin >> a >> b;

        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        int b = get_bacon(i);
        if (b < mv) {
            mv = b;
            mi = i;
        }
    }

    cout << mi;

    return 0;
}