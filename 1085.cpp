#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int hmin, vmin, a = w - x, b = h - y;

	hmin = x < w - x ? x : w - x;
	vmin = y < h - y ? y : h - y;

	cout << (hmin < vmin ? hmin : vmin);

	return 0;
}
