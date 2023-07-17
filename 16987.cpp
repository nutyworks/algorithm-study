#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > eggs;
int max_broken = 0;

void boom(int n, int hand_egg) {
    if (hand_egg == n) {
        int broken = 0;
        for (auto e : eggs) broken += e.first <= 0;
        if (max_broken < broken) max_broken = broken;
        return;
    }

    if (eggs[hand_egg].first <= 0) {
        boom(n, hand_egg + 1);
        return;
    }

    bool perform_boom = false;

    for (int target_egg = 0; target_egg < n; target_egg++) {
        if (hand_egg == target_egg) continue;
        if (eggs[target_egg].first <= 0) continue;

        eggs[hand_egg].first -= eggs[target_egg].second;
        eggs[target_egg].first -= eggs[hand_egg].second;

        perform_boom = true;
        boom(n, hand_egg + 1);

        eggs[hand_egg].first += eggs[target_egg].second;
        eggs[target_egg].first += eggs[hand_egg].second;
    }

    if (!perform_boom) boom(n, hand_egg + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        int durability, weight;
        cin >> durability >> weight;
        eggs.emplace_back(durability, weight);
    }

    boom(eggs.size(), 0);
    cout << max_broken;

    return 0;
}