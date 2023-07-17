#include <iostream>
#include <cstdlib>

using namespace std;

int canihazflat(int *heightmap, int size, int reqheight, int inventory) {
  int todig = 0;
  int toplace = 0;

  for (int i = 0; i < size; i++) {
    int iheight = heightmap[i];
    if (iheight > reqheight) {
      todig += iheight - reqheight;
    }
    if (iheight < reqheight) {
      toplace += reqheight - iheight;
    }
  }
  
  if (toplace <= todig + inventory) {
    return toplace + todig * 2;
  } else {
    return 0x7fffffff;
  }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, m, b, *dobby, dobbyworks = 0x7fffffff, dobbyheight = 0;
  cin >> n >> m >> b;

  dobby = (int *) malloc(n * m * sizeof(int));

  for (int i = 0; i < n * m; i++) {
    int a;
    cin >> a;
    dobby[i] = a;
  }

  for (int h = 0; h <= 256; h++) {
    int hey = canihazflat(dobby, n * m, h, b);
    if (dobbyworks >= hey) {
      dobbyworks = hey;
      dobbyheight = h;
    }
  }

  cout << dobbyworks << ' ' << dobbyheight;

  free(dobby);

	return 0;
}
