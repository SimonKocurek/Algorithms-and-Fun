#include <bits/stdc++.h>

using namespace std;

void Sort(vector<int>& values) {
  bool done = false;
  while (!done) {
    done = true;

    for (int i = 0; i < values.size() - 2; ++i) {
      if (values[i] > values[i + 2]) {
        done = false;
        swap(values[i], values[i + 2]);
      }
    }
  }

}

void Solve() {
  int count;
  cin >> count;

  vector<int> integers(count);
  for (auto& integer : integers) {
    cin >> integer;
  }

  Sort(integers);

  for (int i = 0; i < integers.size() - 1; ++i) {
    if (integers[i] > integers[i + 1]) {
      cout << i;
      return;
    }
  }

  cout << "OK";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; ++i) {
    cout << "Case #" << i << ": ";
    Solve();
    cout << "\n";
  }

  return 0;
}

