// Written by lemonajoc @ 7/23/2023, 6:10:55 PM
#include <bits/stdc++.h>

using namespace std;

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

void print_tiles(int r, int c, int direction) {
  if (direction == DOWN || direction == RIGHT) {
    cout << r << ' ' << c << " 0\n";
    cout << r << ' ' << c << " 1\n";
  } else {
    cout << r << ' ' << c << " 1\n";
    cout << r << ' ' << c << " 0\n";
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int height, width;
  cin >> height >> width;

  if (height % 2 == 1 && width % 2 == 1) {
    cout << height * width * 2 - 1 << '\n';

    print_tiles(1, 1, DOWN);

    for (int c = 1; c <= width - 2; c++) {
      if (c % 2) {
        for (int r = 2; r <= height; r++) {
          print_tiles(r, c, DOWN);
        }
      } else {
        print_tiles(height, c, RIGHT);
        for (int r = height - 1; r >= 2; r--) {
          print_tiles(r, c, UP);
        }
      }
    }

    print_tiles(height, width - 1, RIGHT);
    print_tiles(height, width, UP);

    for (int r = height - 1; r >= 3; r -= 2) {
      print_tiles(r, width, LEFT);
      print_tiles(r, width - 1, UP);
      print_tiles(r - 1, width - 1, RIGHT);
      print_tiles(r - 1, width, UP);
    }

    print_tiles(2, width, RIGHT);
    print_tiles(1, width, UP);
    cout << 1 << ' ' << width - 1 << " 1\n";
    cout << 2 << ' ' << width - 1 << " 0\n";
    cout << 1 << ' ' << width - 1 << " 0\n";

    for (int c = width - 2; c >= 2; c--) {
      print_tiles(1, c, LEFT);
    }

  } else if (height % 2 == 1) {
    cout << height * width * 2 << '\n';

    print_tiles(1, 1, DOWN);

    for (int c = 1; c <= width; c++) {
      if (c % 2) {
        for (int r = 2; r <= height; r++) {
          print_tiles(r, c, DOWN);
        }
      } else {
        print_tiles(height, c, RIGHT);
        for (int r = height - 1; r >= 2; r--) {
          print_tiles(r, c, UP);
        }
      }
    }

    for (int c = width; c >= 2; c--) {
      print_tiles(1, c, LEFT);
    }
  } else if (width % 2 == 1) {
    cout << height * width * 2 << '\n';

    print_tiles(1, 1, UP);

    for (int r = 1; r <= height; r++) {
      if (r % 2) {
        for (int c = 2; c <= width; c++) {
          print_tiles(r, c, RIGHT);
        }
      } else {
        for (int c = width; c >= 3; c--) {
          print_tiles(r, c, LEFT);
        }
        print_tiles(r, 2, DOWN);
      }
    }

    for (int r = height; r >= 2; r--) {
      print_tiles(r, 1, UP);
    }
  } else {
    cout << height * width * 2 << '\n';

    print_tiles(1, 1, UP);

    for (int r = 1; r <= height; r++) {
      if (r % 2) {
        for (int c = 2; c <= width; c++) {
          print_tiles(r, c, RIGHT);
        }
      } else {
        print_tiles(r, width, DOWN);
        for (int c = width - 1; c >= 3; c--) {
          print_tiles(r, c, LEFT);
        }
        print_tiles(r, 2, DOWN);
      }
    }

    for (int r = height; r >= 2; r--) {
      print_tiles(r, 1, UP);
    }
  }

  return 0;
}
