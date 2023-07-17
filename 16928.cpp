#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

char visited[101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int ls, ss, x, y, steps = 0;
  map<int, int> edges;
  queue<int> pos;

  cin >> ls >> ss;

  ls += ss;

  while (ls--) {
    cin >> x >> y;
    edges.insert(pair<int, int>(x, y));
  }

  visited[1] = 1;
  pos.push(1);

  while (!pos.empty()) {
    int size = pos.size();
    while (size--) {
      int p = pos.front();
      pos.pop();

      if (p == 100) {
        cout << steps;
        return 0;
      }
      
      for (int i = 1; i <= 6 && p + i <= 100; i++) {
        if (!visited[p + i]) {
          visited[p + i] = 1;

          map<int, int>::iterator e;

          if ((e = edges.find(p + i)) != edges.end()) {
            if (!visited[e->second]) {
              visited[e->second] = 1;
              pos.push(e->second);
            }
          } else {
            pos.push(p + i);
          }
        }
      }
    }
    steps++;
  }

	return 0;
}
