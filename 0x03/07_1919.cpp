#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a[26] = { 0, }, cnt = 0;
    int *chs = a - 'a';

    string s1, s2;
    cin >> s1 >> s2;

    for (char c : s1) chs[c]++;
    for (char c : s2) chs[c]--;

    for (int i = 0; i < 26; i++) cnt += abs(a[i]);

    cout << cnt;

    return 0;
}