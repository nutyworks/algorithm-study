// Written by lemonajoc @ 7/22/2023, 10:42:29 PM
#include <bits/stdc++.h>

using namespace std;

int done[9][9], rownote[9][10], colnote[9][10], boxnote[9][10];

inline bool is_available(int row, int col, int num) {
  return !rownote[row][num] && !colnote[col][num] && !boxnote[row / 3 * 3 + col / 3][num];
}

inline void set_number(int row, int col, int num) {
  rownote[row][num] = colnote[col][num] = boxnote[row / 3 * 3 + col / 3][num] = true;
  done[row][col] = num;
}

inline void reset_number(int row, int col, int num) {
  rownote[row][num] = colnote[col][num] = boxnote[row / 3 * 3 + col / 3][num] = false;
  done[row][col] = 0;
}

bool guess_number(int pos) {
  if (pos == 81) return true;

  int r = pos / 9, c = pos % 9;

  if (done[r][c]) return guess_number(pos + 1);

  for (int i = 1; i <= 9; i++) {
    if (is_available(r, c, i)) {
      set_number(r, c, i); bool success = guess_number(pos + 1);
      if (success) return true;
      reset_number(r, c, i);
    }
  }

  return false;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int num;
      cin >> num;

      if (num != 0) set_number(i, j, num);
    }
  }
  
  guess_number(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << done[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
