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
  
  if (a == b && b == c) {
    std::cout << 10000 + a * 1000;
  } else if (a == b) {
    std::cout << 1000 + a * 100;
  } else if (b == c) {
    std::cout << 1000 + b * 100;
  } else {
    std::cout << c * 100;
  }
  
  return 0;
}
