// Written by lemonajoc @ 7/23/2023, 7:53:41 AM
#include <bits/stdc++.h>

using namespace std;

int stair[100], digits[10];
long long cnt = 0;

void stair_number(int depth, int prev, int n) {
  if (depth == n) {
    for (int i = 0; i < 10; i++) {
      if (digits[i] == 0) return;
    }

    for (int i = 0; i < n; i++) {
      cout << stair[i];
    }
    cout << '\n';

    cnt++;
    return;
  }

  if (prev == 0) {
    stair[depth] = 1;
    digits[1]++;
    stair_number(depth + 1, stair[depth], n);
    digits[1]--;
  } else if (prev == 9) {
    stair[depth] = 8;
    digits[8]++;
    stair_number(depth + 1, stair[depth], n);
    digits[8]--; } else {
    stair[depth] = prev + 1;
    digits[stair[depth]]++;
    stair_number(depth + 1, stair[depth], n);
    digits[stair[depth]]--;
    stair[depth] = prev - 1;
    digits[stair[depth]]++;
    stair_number(depth + 1, stair[depth], n);
    digits[stair[depth]]--;
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n;
  cin >> n;
  for (int i = 1; i <= 9; i++) {
    stair[0] = i;
    digits[i]++;
    stair_number(1, i, n);
    digits[i]--;
  }
  cout << cnt << ",\n";

  return 0;
}
