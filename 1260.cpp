#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct vertex {
  int number;
  bool traversed;
  vector<int> connections;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int nvertex, nedge, start;
  cin >> nvertex >> nedge >> start;

  vector<vertex> graph;
  stack<int> s;
  queue<int> q;

  for (int i = 0; i <= nvertex; i++) {
    vertex v;
    v.number = i;
    v.traversed = false;
    graph.push_back(v);
  }

  while (nedge--) {
    int l, r;
    cin >> l >> r;
    graph[l].connections.push_back(r);
    graph[r].connections.push_back(l);
  }

  for (auto &vertex : graph) {
    sort(vertex.connections.begin(), vertex.connections.end());
  }

  s.push(start);
  graph[start].traversed = true;
  cout << start << ' ';

  while (!s.empty()) {
    int v = s.top();
    bool end = 1;

    for (auto connection : graph[v].connections) {
      if (!graph[connection].traversed) {
        s.push(connection);
        graph[s.top()].traversed = true;

        cout << s.top() << ' ';
        end = 0;
        break;
      }
    }
    if (end) { s.pop(); }
  }
  cout << '\n';

  for (auto &vertex : graph) {
    vertex.traversed = false;
  }

  q.push(start);
  graph[start].traversed = true;

  while (!q.empty()) {
    for (auto connection : graph[q.front()].connections) {
      if (!graph[connection].traversed) {
        graph[connection].traversed = true;
        q.push(connection);
      }
    }
    cout << q.front() << ' ';
    q.pop();
  }

	return 0;
}
