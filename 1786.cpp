// Written by lemonajoc @ 7/23/2023, 4:05:13 PM
#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string str, string find) {
  vector<int> idx;
  vector<int> fail;
  fail.push_back(-1);

  // write fail func
  // int j = -1;
  // for (int i = 0; i < find.size(); i++) {
  //   if (find[i] == find[j + 1]) {
  //     if (j == -1) {
  //       j = 0;
  //     } else {
  //       j++;
  //     }
  //   } else {
  //     j = -1;
  //   }
  //   fail.push_back(j);
  // }
  //
  int pos = 1, cnd = 0;
  while (pos < find.size()) {
    if (find[pos] == find[cnd]) {
      fail[pos] = fail[cnd];
    } else {
      fail[pos] = cnd;
      while (cnd >= 0 && find[pos] != find[cnd]) {
        cnd = fail[cnd];
      }
    }
    pos++;
    cnd++;
  }
  fail.push_back(cnd);

  for (int i = 0; i <= find.size(); i++) {
    cout << fail[i] << ' ';
  }

  return idx;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  string t, p;
  getline(cin, t);
  getline(cin, p);

  vector<int> result = kmp(t, p);

  cout << result.size() << '\n';
  if (!result.empty()) {
    for (int idx : result) {
      cout << idx << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}
