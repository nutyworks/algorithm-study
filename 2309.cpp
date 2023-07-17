#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> hs;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        int t;
        std::cin >> t;
        hs.push_back(t);
        sum += t;
    }

    int remaining = sum - 100;

    std::sort(hs.begin(), hs.end());

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j) continue;
            if (hs[i] + hs[j] == remaining) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) continue;

                    std::cout << hs[k] << '\n';
                }

                return 0;
            }
        }
    }

    return 0;
}