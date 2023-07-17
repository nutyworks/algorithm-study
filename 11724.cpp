#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex {
  vector<int> connections;
  bool traversed;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  vector<vertex> graphs;
  queue<int> q;
  int nv, ne;
  cin >> nv >> ne;

  for (int i = 0; i <= nv; i++) {
    vertex v;
    v.traversed = false;

    graphs.push_back(v);
  }

  vertex dummy;
  dummy.traversed = false;
  graphs.push_back(dummy);

  int a, b;
  while (ne--) {
    cin >> a >> b;
    graphs[a].connections.push_back(b);
    graphs[b].connections.push_back(a);
  }

  int min_not_traversed = 1;
  int components = 0;

  while (min_not_traversed <= nv) {
    q.push(min_not_traversed);
    graphs[min_not_traversed].traversed = true;

    while (!q.empty()) {
      int iv = q.front();
      q.pop();

      for (auto ic : graphs[iv].connections) {
        if (!graphs[ic].traversed) {
          graphs[ic].traversed = true;
          q.push(ic);
        }
      }
    }

    ++components;

    while (graphs[++min_not_traversed].traversed);
  }

  cout << components;

	return 0;
}
