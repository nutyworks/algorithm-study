#include <iostream>
#include <queue>

#define TARGET (1 << 8);

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int ntestcases;
  cin >> ntestcases;

  while (ntestcases--) {
    int ndocs, itarget, priorities[10] = {};
    queue<int> printer;
    cin >> ndocs >> itarget;

    for (int idoc = 0; idoc < ndocs; idoc++) {
      int doc;
      cin >> doc;

      ++priorities[doc];
      
      if (idoc == itarget) {
        doc |= TARGET;
      }

      printer.push(doc);
    }

    int i = 0;
    int maxpriority = 9;

    while (!printer.empty()) {
      int doc = printer.front();
      printer.pop();
      int istarget = doc >> 8;
      int docpriority = doc & 0xff;

      while (priorities[maxpriority] == 0) {
        --maxpriority;
      }

      if (docpriority != maxpriority) {
        printer.push(doc);
      } else if (istarget) {
        ++i;
        cout << i << '\n';
        break;
      } else {
        --priorities[maxpriority];
        ++i;
      }
    }
  }

	return 0;
}
