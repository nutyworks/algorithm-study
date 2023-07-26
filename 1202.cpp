// Written by lemonajoc @ 7/22/2023, 10:46:18 AM
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> jewel; // value, weight

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  priority_queue<jewel> jewels;
  multiset<int> bags;
  int n, k;
  long long totalv = 0;

  cin >> n >> k;
  
  for (int i = 0; i < n; i++) {
    int m, v;
    cin >> m >> v;
    jewels.emplace(v, m);
  }

  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    bags.insert(c);
  }

  while (!jewels.empty() && !bags.empty()) {
    int v, m;
    tie(v, m) = jewels.top();
    jewels.pop();

    auto lb = bags.lower_bound(m);

    if (lb == bags.end()) continue;

    bags.erase(lb);
    totalv += v;
  }

  cout << totalv;

  return 0;
}
