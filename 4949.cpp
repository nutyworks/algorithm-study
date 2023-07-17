#include <cstdio>
#include <stack>

using namespace std;

int main() {
  stack<char> brackets;
  char c;

  while (true) {
    int len = 0;
    int isvalid = 1;

    while (!brackets.empty()) {
      brackets.pop();
    }

    while (true) {
      scanf("%c", &c);

      if (c == 10) { continue; }
      if (c == '.' && len == 0) { return 0; }
      if (c == '.') { break; }
      len++;

      if (c == '(' || c == '[') {
        brackets.push(c);
      }

      if (c == ')') {
        if (!brackets.empty() && brackets.top() == '(') {
          brackets.pop();
        } else {
          isvalid = 0;
        }
      }

      if (c == ']') {
        if (!brackets.empty() && brackets.top() == '[') {
          brackets.pop();
        } else {
          isvalid = 0;
        }
      }
    }

    if (!brackets.empty()) isvalid = 0;

    printf("%s\n", isvalid ? "yes" : "no");
  }

	return 0;
}
