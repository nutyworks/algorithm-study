// Written by lemonajoc @ 7/18/2023, 3:03:14 PM
#include <bits/stdc++.h>

using namespace std;

int numbers[11];
vector<char> selected;
int ops[4];
int n, maxv = 0x80000000, minv = 0x7fffffff;

int calculate() {
  int value = numbers[0];

  for (int i = 0; i < n - 1; i++) {
    switch (selected[i]) {
      case 0: value += numbers[i + 1]; break;
      case 1: value -= numbers[i + 1]; break;
      case 2: value *= numbers[i + 1]; break;
      case 3: value /= numbers[i + 1]; break;
    }
  }

  return value;
}

void bruteforce(int depth) {
  if (depth == n - 1) {
    int val = calculate();
    maxv = max(maxv, val);
    minv = min(minv, val);
  }
  for (int i = 0; i < 4; i++) {
    if (!ops[i]) continue;

    selected.push_back(i);
    ops[i]--;
    bruteforce(depth + 1);
    selected.pop_back();
    ops[i]++;
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  cin >> ops[0] >> ops[1] >> ops[2] >> ops[3];

  bruteforce(0);

  cout << maxv << '\n' << minv;

  return 0;
}
