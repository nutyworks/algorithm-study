#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tiii;

void add_edge(queue<tiii> edges[10001], int u, int v, int w) {
  edges[u].emplace(w, u, v);
  edges[v].emplace(w, u, v);
}

int mst_prim(queue<tiii> edges_arr[10001], int nv) {
  set<tiii> mst_edges;
  set<int> mst_vertices;
  queue<tiii> tmp_edges;
  priority_queue<tiii, vector<tiii>, greater<tiii>> edges;

  bool in_mst[10001] = {};
  
  in_mst[1] = true;
  mst_vertices.insert(1);

  while (mst_edges.size() < nv - 1) {
    for (int v : mst_vertices) {
      while (!edges_arr[v].empty()) {
        edges.push(edges_arr[v].front());
        edges_arr[v].pop();
      }
    }

    while (!edges.empty()) {
      int w, u, v;
      tie(w, u, v) = edges.top();
      
      bool iu = in_mst[u], iv = in_mst[v];
      edges.pop();

      if (iu ^ iv) {
        in_mst[u] = in_mst[v] = true;
        mst_edges.emplace(w, u, v);
        mst_vertices.insert(u);
        mst_vertices.insert(v);
        // cout << w << ' ' << u << '-' << v << " adding edges to mst\n";
        break;
      } else if (iu && iv) {
        // cout << w << ' ' << u << '-' << v << " already in mst\n";
      } else {
        tmp_edges.emplace(w, u, v);
        // cout << w << ' ' << u << '-' << v << " both vertices not in mst\n";
      }

      while (!tmp_edges.empty()) {
        edges.push(tmp_edges.front());
        tmp_edges.pop();
      }
    }
  }

  int weightsum = 0;

  for (tiii edge : mst_edges) {
    weightsum += get<0>(edge);
  }

  return weightsum;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  queue<tiii> edges[10001];
  int nv, ne;
  cin >> nv >> ne;

  for (int i = 0; i < ne; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    add_edge(edges, a, b, w);
  }

  cout << mst_prim(edges, nv);

  return 0;
}
