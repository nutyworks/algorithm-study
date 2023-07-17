#include <bits/stdc++.h>

using namespace std;
map<int, int> memo;

int fib(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 3;

    auto m = memo.find(n);
    if (m != memo.end()) return m->second;

    if (n % 2) {
        long long a = fib(n / 2 + 1) % 1000000007;
        long long b = fib(n / 2) % 1000000007;

        int result = (a * a + b * b) % 1000000007;
        memo.insert_or_assign(n, result);
        return result;
    } else {
        long long a = fib(n + 1) % 1000000007;
        long long b = fib(n - 1) % 1000000007;

        int result = (a - b + 1000000007) % 1000000007;
        memo.insert_or_assign(n, result);
        return result;
    }

    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n;
    cin >> n;
    cout << fib(n % 2000000016);

    return 0;
}