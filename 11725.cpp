#include <bits/stdc++.h>

using namespace std;
using vertex = vector<pair<bool, int>>;
using edge_map = map<int, vertex>;

static int parent[100001];

#define TRAVERSED first
#define OTHER_VERTEX second

edge_map edges;

void dfs(int vertex) {
    for (auto edge : edges[vertex]) {
        if (edge.TRAVERSED) {
            continue;
        }

        for (auto &e : edges[edge.OTHER_VERTEX]) {
            if (e.OTHER_VERTEX == vertex) {
                e.TRAVERSED = true;
            }
        }

        parent[edge.OTHER_VERTEX] = vertex;

        dfs(edge.OTHER_VERTEX);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        edge_map::iterator e;

        if ((e = edges.find(a)) == edges.end()) {
            edges.insert_or_assign(a, vertex(1, {false, b}));
        } else {
            edges[a].push_back({false, b});
        }

        if ((e = edges.find(b)) == edges.end()) {
            edges.insert_or_assign(b, vertex(1, {false, a}));
        } else {
            edges[b].push_back({false, a});
        }
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}