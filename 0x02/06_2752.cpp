#include <iostream>

int main() {
  int a, b, c, t;
  std::cin >> a >> b >> c;
  
  if (a > b) {
    t = a;
    a = b;
    b = t;
  }

  if (b > c) {
    t = b;
    b = c;
    c = t;
  }

  if (a > b) {
    t = a;
    a = b;
    b = t;
  }

  std::cout << a << ' ' << b << ' ' << c;
  
  return 0;
}