#include <iostream>
#include <map>

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios_base::sync_with_stdio(false);
	
  std::map<int, int> iimap;
  std::map<int, int>::iterator entry;

  int n, a;
  std::cin >> n;
  while (n--) {
    std::cin >> a;
    
    if ((entry = iimap.find(a)) == iimap.end()) {
      iimap.insert(std::make_pair(a, 1));
    } else {
      (entry->second)++;
    }
  }

  std::cin >> n;

  while (n--) {
    std::cin >> a;

    if ((entry = iimap.find(a)) == iimap.end()) {
      std::cout << "0 ";
    } else {
      std::cout << entry->second << ' ';
    }
  }

	return 0;
}
