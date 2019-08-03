#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<bool>> Adjacency;

bool Reachable(Adjacency& matrix, int start, int end) {
  vector<bool> visited(matrix.size(), false);
  queue<int> next;

  visited[start] = true;
  next.push(start);

  while (!next.empty()) {
    auto current = next.front();
    next.pop();

    for (int i = 0; i < matrix.size(); ++i) {
      if (matrix[current][i] && !visited[i]) {
        visited[i] = true;
        next.push(i);

        if (i == end) {
          return true;
        }
      }
    }
  }

  return false;
}

bool PathExists(Adjacency& matrix, int start, int end) {
  return start == end || Reachable(matrix, start, end) || Reachable(matrix, end, start);
}

int main() {
  Adjacency path {
    {false, true, false, true, true},
    {false, false, true, true, false},
    {false, false, false, false, false},
    {false, false, true, false, false},
    {false, false, true, true, false}
  };
  Adjacency path2 {
    {false, false, false},
      {false, false, true},
      {true, false, false}
  };
  Adjacency path3;

  cout << PathExists(path, 1, 4) << "\n";
  cout << PathExists(path2, 0, 1) << "\n";
  cout << PathExists(path3, 1, 2) << "\n";

  return 0;
}

