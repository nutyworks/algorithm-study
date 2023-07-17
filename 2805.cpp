#include <algorithm>
#include <cstdlib>
#include <iostream>
#define ceildiv(a, b) (((a) / (b)) + !!((a) % (b)))

using namespace std;

struct cmp {
	bool operator() (const long long &a, const long long &b) {
		return a > b;
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	long long nlogs, reqheight, *logs;

	cin >> nlogs >> reqheight;

	logs = (long long *) malloc((nlogs + 1) * sizeof(long long));

	for (long long i = 0; i < nlogs; i++) {
		cin >> logs[i];
	}

	logs[nlogs] = -1;

	cmp c;
	sort(logs, logs + nlogs, c);

	long long total = 0, logi = -1, logsCutting = 0, cutterHeight = logs[0] + 1;

	while (total < reqheight) {

		long long heightDiffToNext = cutterHeight - logs[logi + 1];

		if (total + logsCutting * heightDiffToNext <= reqheight) {
			total += logsCutting * heightDiffToNext;
			cutterHeight -= heightDiffToNext;
		} else {
			cutterHeight -= ceildiv(reqheight - total, logsCutting);
			total += ceildiv(reqheight - total, logsCutting) * logsCutting;
			break;
		}

		while (logs[logi + 1] >= cutterHeight) {
			logsCutting++;
			logi++;
		}
	}

	cout << cutterHeight;

	return 0;
}
