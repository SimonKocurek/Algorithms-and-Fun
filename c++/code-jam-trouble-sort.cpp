#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int count;
  cin >> count;

  priority_queue<int, vector<int>, greater<int>> left;
  priority_queue<int, vector<int>, greater<int>> right;

  for (int i = 0; i < count; ++i) {
    int next;
    cin >> next;

    if (i & 1) {
      right.push(next);
    } else {
      left.push(next);
    }
  }

  auto current = left.top();
  left.pop();
  for (int i = 1; i < count; ++i) {
    int next;
    if (i & 1) {
      next = right.top();
      right.pop();
    } else {
      next = left.top();
      left.pop();
    }

    if (next < current) {
      cout << i - 1;
      return;
    }

    current = next;
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
