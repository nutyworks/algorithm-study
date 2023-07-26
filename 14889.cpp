// Written by lemonajoc @ 7/18/2023, 3:23:21 PM
#include <bits/stdc++.h>

using namespace std;

int n, scores[20][20], min_diff = 0x7fffffff;

vector<int> selected;

int calculate_diff() {
  vector<int> not_selected;
  int diff = 0;

  for (int i = 0; i < n; i++) {
    bool found = binary_search(selected.begin(), selected.end(), i);
    if (!found) not_selected.push_back(i);
  }

  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      diff += scores[selected[i]][selected[j]] - scores[not_selected[i]][not_selected[j]];
    }
  }

  return abs(diff);
}

void select(int i, int depth) {
  if (depth == n / 2) {
    int diff = calculate_diff();
    min_diff = min(min_diff, diff);
    return;
  }
  for (; i < n; i++) {
    selected.push_back(i);
    select(i + 1, depth + 1);
    selected.pop_back();
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> scores[i][j];
    }
  }

  select(0, 0);

  cout << min_diff;

  return 0;
}
