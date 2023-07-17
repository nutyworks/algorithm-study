#include <iostream>
#include <cstdlib>

using namespace std;

void ac() {
  int reversed = 0, delfront = 0, delback = 0;
  string ops;

  cin >> ops;
  for (char op : ops) {
    if (op == 'R') {
      reversed ^= 1;
    } else if (op == 'D') {
      if (reversed) {
        ++delback;
      } else {
        ++delfront;
      }
    }
  }
  
  int n, num;
  char c;
  cin >> n;
  if (n < delfront + delback) {
    string s;
    cout << "error\n";
    cin >> s;
    return;
  }

  cin >> c;
  
  bool first_print = true;

  cout << '[';
  if (reversed) {
    int *arr = (int *) malloc((n - delfront - delback) * sizeof(int));
    int i = 0, k = 0;
    for (; i < n; i++) {
      cin >> num >> c;
      if (i < delfront || i >= n - delback) continue;
      arr[k++] = num;
    }
    while (k--) {
      if (!first_print) {
        cout << ',';
      }
      cout << arr[k];
      first_print = false;
    }
    free(arr);
  } else {
    for (int i = 0; i < n; i++) {
      cin >> num >> c;
      if (i < delfront || i >= n - delback) continue;
      if (!first_print) {
        cout << ',';
      }
      cout << num;
      first_print = false;
    }
  }
  if (n == 0) {
    cin >> c;
  }
  cout << "]\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n;
  cin >> n;
  while (n--) {
    ac();
  }

	return 0;
}
