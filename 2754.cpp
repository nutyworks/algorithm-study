#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  string g;
  cin >> g;

  if (g == "A+") cout << "4.3";
  else if (g == "A0") cout << "4.0";
  else if (g == "A-") cout << "3.7";
  else if (g == "B+") cout << "3.3";
  else if (g == "B0") cout << "3.0";
  else if (g == "B-") cout << "2.7";
  else if (g == "C+") cout << "2.3";
  else if (g == "C0") cout << "2.0";
  else if (g == "C-") cout << "1.7";
  else if (g == "D+") cout << "1.3";
  else if (g == "D0") cout << "1.0";
  else if (g == "D-") cout << "0.7";
  else cout << "0.0";

  return 0;
}
