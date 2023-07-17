#include <bits/stdc++.h>

using namespace std;

static int finished[100001], visited[100001], next_node[100001];
static int cnt = 0;

void dfs(int node) {
    visited[node] = 1;

    int next = next_node[node];
    if (!visited[next]) dfs(next);
    else if (!finished[next]) {
        for (int i = next; i != node; i = next_node[i]) cnt++;
        cnt++;
    }
    finished[node] = 1;
}

int solve(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    return n - cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> next_node[i];
        }

        cout << solve(n) << '\n';

        memset(finished, 0, sizeof(finished));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }

    return 0;
}