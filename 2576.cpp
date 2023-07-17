#include <iostream>

int main() {
    int n = 7;
    int sum = 0;
    unsigned int min = 0xffffffff;

    while (n--) {
        int t;
        std::cin >> t;
        if ((t & 1) == 1) {
            if (t < min) {
                min = t;
            }
            sum += t;
        }
    }

    if (min != 0xffffffff)
        std::cout << sum << '\n';

    std::cout << (int) min;
}