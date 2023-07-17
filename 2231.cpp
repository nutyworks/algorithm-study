#include <iostream>

int main() {
    int n, result = 0;

    std::cin >> n;

    for (int i = 0; i < 1000000; ++i) {
        int sum = i;

        for (int d = i; d; d /= 10) {
            sum += d % 10;
        }

        if (n == sum) {
            result = i;
            break;
        }
    }

    std::cout << result;

    return 0;
}