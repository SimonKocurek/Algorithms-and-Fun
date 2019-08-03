#include <bits/stdc++.h>

using namespace std;

int EditDistance(string& a, string& b) {
  vector<vector<int>> results(a.size() + 1, vector<int>(b.size() + 1));

  for (int i = 0; i <= a.size(); ++i) {
    results[i][0] = i;
  }
  for (int i = 0; i <= b.size(); ++i) {
    results[0][i] = i;
  }

  for (int a_idx = 1; a_idx <= a.size(); ++a_idx) {
    for (int b_idx = 1; b_idx <= b.size(); ++b_idx) {
      auto added_to_a = results[a_idx - 1][b_idx] + 1;
      auto added_to_b = results[a_idx][b_idx - 1] + 1;
      auto compared = results[a_idx - 1][b_idx - 1] + (a[a_idx - 1] != b[b_idx - 1]);

      auto min_distance = min(min(added_to_a, added_to_b), compared);
      results[a_idx][b_idx] = min_distance;
    }
  }

  return results.back().back();
}

int main() {
  string a = "sitting";
  string b = "kitten";

  string c;
  string d = "abc";

  cout << EditDistance(a, b) << "\n";
  cout << EditDistance(c, d) << "\n";

  return 0;
}

