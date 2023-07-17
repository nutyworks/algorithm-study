#include <queue>
#include <iostream>
#include <utility>
#include <tuple>

const int DH[4] = { -1, 1, 0, 0 };
const int DW[4] = { 0, 0, -1, 1 };

int main() {
  int height, width;
  int map[1000][1000];
  int sh, sw;

  std::queue<std::pair<int, int> > to_traverse;

  std::cin >> height >> width;

  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      int t;
      std::cin >> t;

      switch (t) {
        case 0: { map[h][w] = 0; break; }
        case 1: { map[h][w] = -1; break; }
        case 2: { map[h][w] = 0; sh = h; sw = w; break; }
      }
    }
  }

  to_traverse.push(std::make_pair(sh, sw));

  while (!to_traverse.empty()) {
    int h, w, dist;
    std::tie(h, w) = to_traverse.front();
    to_traverse.pop();

    dist = map[h][w] + 1;

    for (int i = 0; i < 4; i++) {
      int th = h + DH[i], tw = w + DW[i];
      if (th >= 0 && th < height && tw >= 0 && tw < width && map[th][tw] == -1) {
        map[th][tw] = dist;
        to_traverse.push(std::make_pair(th, tw));
      }
    }
  }

  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      std::cout << map[h][w] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}