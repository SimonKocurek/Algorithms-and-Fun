#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Line;
typedef vector<Line> Matrix;
typedef pair<int, int> Point;

Matrix Left(const Matrix& matrix) {
  Matrix result(matrix.size(), Line(matrix[0].size()));

  for (int i = 0; i < matrix.size(); ++i) {
    result[i][0] = matrix[i][0];
  }
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 1; j < matrix[0].size(); ++j) {
      result[i][j] = (result[i][j - 1] + 1) * matrix[i][j];
    }
  }

  return result;
}

Matrix Up(const Matrix& matrix) {
  Matrix result(matrix.size(), Line(matrix[0].size()));

  for (int i = 0; i < matrix[0].size(); ++i) {
    result[0][i] = matrix[0][i];
  }
  for (int i = 1; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      result[i][j] = (result[i - 1][j] + 1) * matrix[i][j];
    }
  }

  return result;
}

pair<Point, Point> LargestArea(const Matrix& matrix) {
  if (matrix.empty()) {
    return {{-1, -1}, {-1, -1}};
  }

  auto left = Left(matrix);
  auto up = Up(matrix);

  auto max = 0;
  pair<Point, Point> result = {{-1, -1}, {-1, -1}};
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      if (left[i][j] * up[i][j] > max) {
        max = left[i][j] * up[i][j];
        result = {{j - left[i][j] + 1, i - up[i][j] + 1}, {j, i}};
      }
    }
  }

  return result;
}

int main() {
  Matrix a {
    {1, 1, 0, 0, 1},
      {1, 1, 1, 1, 0},
      {0, 1, 1, 1, 1},
      {0, 0, 1, 1, 1}
  };

  Matrix b {
    {0, 0, 0},
      {0, 0, 0}
  };

  Matrix c;

  auto res_a = LargestArea(a);
  auto res_b = LargestArea(b);
  auto res_c = LargestArea(c);

  cout << res_a.first.first << ":" << res_a.first.second << "  " 
    << res_a.second.first << ":" << res_a.second.second << "\n";

  cout << res_b.first.first << ":" << res_b.first.second << "  " 
    << res_b.second.first << ":" << res_b.second.second << "\n";

  cout << res_c.first.first << ":" << res_c.first.second << "  " 
    << res_c.second.first << ":" << res_c.second.second << "\n";

  return 0;
}

