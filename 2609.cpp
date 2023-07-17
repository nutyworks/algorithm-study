#include <iostream>
#include <numeric>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << '\n' << lcm(a, b);

	return 0;
}
