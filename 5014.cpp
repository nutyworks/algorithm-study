#include <bits/stdc++.h>

using namespace std;

int v[1000000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> q;
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    q.push(s);
    v[s] = 1;

    while (!q.empty()) {
        int tf = q.front();
        q.pop();

        if (tf == g) break;

        if (tf - d >= 1 && v[tf - d] == 0) {
            q.push(tf - d);
            v[tf - d] = v[tf] + 1;
        }
        if (tf + u <= f && v[tf + u] == 0) {
            q.push(tf + u);
            v[tf + u] = v[tf] + 1;
        }
    }

    if (v[g]) cout << v[g] - 1;
    else cout << "use the stairs";

    return 0;
}