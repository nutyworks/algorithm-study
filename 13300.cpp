#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k, students[12] = { 0, }, rooms = 0;

    cin >> n >> k;

    while (n--) {
        int grade, sex;
        cin >> sex >> grade;

        students[(grade - 1) * 2 + sex]++;
    }

    for (int i = 0; i < 12; i++) {
        rooms += (students[i] + k - 1) / k;
    }

    cout << rooms;

    return 0;
}