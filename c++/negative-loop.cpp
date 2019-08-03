#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<double>> Matrix;

bool HasNegativeLoop(Matrix matrix) {
  for (auto& line : matrix) {
    for (auto& value : line) {
      value = -log(value);
    }
  }
  
  vector<double> distance(matrix.size(), DBL_MAX);
  distance[0] = 0;

  bool finished;
  for (int i = 0; i < matrix.size(); ++i) {
    finished = true;

    for (int from = 0; from < matrix.size(); ++from) {
      for (int to = 0; to < matrix.size(); ++to) {

        auto new_distance = distance[from] + matrix[from][to];
        if (new_distance < distance[to]) {
          finished = false;
          distance[to] = new_distance;
        }
      }
    }

    if (finished) {
      break;
    }
  }

  return !finished;
}

int main() {
  Matrix good {
    {1, 2, 3, 4, 5},
    {1/3, 1, 4, 5, 5},
    {1/4, 1/6, 1, 3, 4},
    {1/5, 1/100, 1/213, 1, 4},
    {1/6, 1/23, 1/12, 1/435, 1}
  };

  Matrix bad {
    {1, 2, 3},
    {1, 1, 1},
    {1, 1, 1}
  };

  cout << HasNegativeLoop(good) << "\n";
  cout << HasNegativeLoop(bad) << "\n";

  return 0;
}

