// Written by lemonajoc @ 7/17/2023, 7:55:53 PM
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  deque<pair<int, int>> bridge;
  queue<pair<int, int>> land;
  int trucks, bridgelen, max_weight, time = 0, weightsum = 0;
  cin >> trucks >> bridgelen >> max_weight;

  for (int i = 0; i < trucks; i++) {
    int weight;
    cin >> weight;
    land.emplace(0, weight);
  }

  while (!bridge.empty() || !land.empty()) {
    if (!bridge.empty() && bridge.front().first == bridgelen) {
      weightsum -= bridge.front().second;
      bridge.pop_front();
    }

    if (!land.empty() && weightsum + land.front().second <= max_weight) {
      weightsum += land.front().second;
      bridge.push_back(land.front());
      land.pop();
    }

    for (auto &truck : bridge) {
      truck.first++;
    }

    time++;
  }

  cout << time;

  return 0;
}
