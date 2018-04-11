#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Line;
typedef vector<Line> Matrix;
typedef pair<int, int> Point;
typedef pair<Point, Point> Submatrix;

struct KadaneInfo {
  int start;
  int end;
  int sum;
};

KadaneInfo Kadane(const Matrix& matrix, Line& sum, const int row) {
  KadaneInfo result = {0, 0, INT_MIN};

  int current_max = 0;
  int start = 0;
  for (int i = 0; i < matrix[0].size(); ++i) {
    sum[i] += matrix[row][i];

    current_max += sum[i];
    if (current_max < sum[i]) {
      current_max = sum[i];
      start = i;
    }

    if (current_max > result.sum) {
      result = {start, i, current_max};
    }
  }

  return result;
}

Submatrix LargestSubmatrix(const Matrix& matrix) {
  Submatrix result = {{-1, -1}, {-1, -1}};
  int max = -1;

  for (int i = 0; i < matrix.size(); ++i) {
    Line sum(matrix[0].size(), 0);

    for (int j = i; j < matrix.size(); ++j) {
      auto kadane = Kadane(matrix, sum, j);
      if (kadane.sum > max) {
        result = {{kadane.start, i}, {kadane.end, j}};
        max = kadane.sum;
      }
    }

  }

  return result;
}

int main() {
  Matrix a {
    {2, 4, 5, -2},
    {0, 1, 3, 8},
    {-3, -2, 1, 0},
    {2, 5, 4, 3},
    {2, 0, 0, 1}
  };

  Matrix b {
    {-1, -3, -4},
    {1, -3, -4},
    {0, 0, 0}
  };

  Matrix c;

  auto largest_a = LargestSubmatrix(a);
  auto largest_b = LargestSubmatrix(b);
  auto largest_c = LargestSubmatrix(c);

  cout << largest_a.first.first << ":" << largest_a.first.second << "   " <<
    largest_a.second.first << ":" << largest_a.second.second << "\n";

  cout << largest_b.first.first << ":" << largest_b.first.second << "   " <<
    largest_b.second.first << ":" << largest_b.second.second << "\n";

  cout << largest_c.first.first << ":" << largest_c.first.second << "   " <<
    largest_c.second.first << ":" << largest_c.second.second << "\n";

  return 0;
}

