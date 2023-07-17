#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct computer {
  bool infected;
  vector<int> connections;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  vector<computer> network;
  queue<int> infections;
  int n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    computer v;
    v.infected = false;
    network.push_back(v);
  }

  int nedge;
  cin >> nedge;
  while (nedge--) {
    int a, b;
    cin >> a >> b;
    network[a].connections.push_back(b);
    network[b].connections.push_back(a);
  }

  network[1].infected = true;
  infections.push(1);

  while (!infections.empty()) {
    int ic = infections.front();
    infections.pop();

    for (auto c : network[ic].connections) {
      auto ic2 = &network[c];
      if (!ic2->infected) {
        ic2->infected = true;
        infections.push(c);
      }
    }
  }

  int count = 0;
  for (int i = 2; i <= n; i++) {
    count += network[i].infected;
  }

  cout << count;

	return 0;
}
