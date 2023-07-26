// Written by lemonajoc @ 7/22/2023, 6:47:51 PM
#include <bits/stdc++.h>

using namespace std;

struct node {
  int value;
  node *left, *right;
};

struct tree {
  node *top;
};

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, inorder[100000], postorder[100000];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> inorder[i];
  for (int i = 0; i < n; i++) cin >> postorder[i];

  return 0;
}
