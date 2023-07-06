#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int sum = 0;
    std::vector<int> v;

    for (int i = 0; i < 5; i++) {
        int t;
        std::cin >> t;
        v.push_back(t);
        sum += t;
    }

    std::sort(v.begin(), v.end());

    std::cout << sum / 5 << '\n' << v[2];

    return 0;
}