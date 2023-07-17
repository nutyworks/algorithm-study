#include <iostream>
#include <cstdlib>

using namespace std;

int calc_highscore(int *steps, int size) {
  if (size == 1) {
    return steps[0];
  }
  if (size == 2) {
    return steps[0] + steps[1];
  }

  int *highscores[3];

  highscores[0] = (int *) malloc(size * sizeof(int)); // ? O O
  highscores[1] = (int *) malloc(size * sizeof(int)); // ? O X
  highscores[2] = (int *) malloc(size * sizeof(int)); // ? X O

  highscores[0][0] = steps[0]; highscores[0][1] = steps[0] + steps[1];
  highscores[1][0] = steps[0]; highscores[1][1] = steps[0];
  highscores[2][0] = steps[0]; highscores[2][1] = steps[1];

  for (int i = 2; i < size; i++) {
    highscores[0][i] = highscores[2][i-1] + steps[i];
    highscores[1][i] = max(highscores[0][i-1], highscores[2][i-1]);
    highscores[2][i] = highscores[1][i-1] + steps[i];
  }

  int ret = max(highscores[0][size - 1], highscores[2][size - 1]);

  free(highscores[0]);
  free(highscores[1]);
  free(highscores[2]);

  return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, s, *steps;
  cin >> n;

  steps = (int *) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    cin >> s;
    steps[i] = s;
  }

  cout << calc_highscore(steps, n);

  free(steps);

	return 0;
}
