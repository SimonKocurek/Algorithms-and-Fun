#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Matrix;

inline bool Same(char a, char b) {
  return a == b || b == '.';
}

inline bool IsStarred(string& pattern, int i) {
  return i + 1 < pattern.size() && pattern[i + 1] == '*';
}

bool Matches(Matrix& matrix, string& searched, string& pattern, int i, int j) {
  if (matrix[i][j] == -1) {

    // at end
    if (j == pattern.size()) {
      matrix[i][j] = i == searched.size();

    // recurse
    } else {
      bool matches = i < searched.size() && Same(searched[i], pattern[j]);

      if (IsStarred(pattern, j)) {
        matrix[i][j] = Matches(matrix, searched, pattern, i, j + 2) ||
          matches && Matches(matrix, searched, pattern, i + 1, j);
      } else {
        matrix[i][j] = matches && Matches(matrix, searched, pattern, i + 1, j + 1); 
      }

    }
  }

  return matrix[i][j];
}

bool Matches(string searched, string pattern) {
  Matrix matrix(searched.size() + 1, vector<int>(pattern.size() + 1, -1));
  return Matches(matrix, searched, pattern, 0, 0);
}

int main() {
  cout << Matches("aa","a") << " False" << "\n";
  cout << Matches("aa","aa") << " True" << "\n";
  cout << Matches("aaa","aa") << " False" << "\n";
  cout << Matches("aa","a*") << " True" << "\n";
  cout << Matches("aa",".*") << " True" << "\n";
  cout << Matches("ab",".*") << " True" << "\n";
  cout << Matches("aab","c*a*b") << " True" << "\n";

  return 0;
}

