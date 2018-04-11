#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Line;
typedef vector<Line> Matrix;
typedef pair<int, int> Point;
typedef pair<Point, Point> Submatrix;

Submatrix LargestSubmatrix(const Matrix& matrix) {
  Submatrix result = {{-1, -1}, {-1, -1}};
  auto max = INT_MIN;

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = i; j < matrix.size(); ++j) {

    }
  }

  return result;
}

int main() {
  Matrix a {
  };

  Matrix b {
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

