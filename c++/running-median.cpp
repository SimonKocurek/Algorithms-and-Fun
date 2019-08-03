#include <bits/stdc++.h>

using namespace std;

vector<double> RunningMedian(vector<int>& values) {
  vector<double> result;

  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;

  for (auto& value : values) {
    if (left.size() <= right.size()) {
      left.push(value);
    } else {
      right.push(value);
    }

    while (!right.empty() && right.top() < left.top()) {
      right.push(left.top());
      left.pop();

      left.push(right.top());
      right.pop();
    }

    if ((left.size() + right.size()) & 1) {
      result.push_back(left.top());
    } else {
      result.push_back((left.top() + right.top()) / 2.0);
    }
  }

  return result;
}

int main() {
  vector<int> values {2, 1, 5, 7, 2, 0, 5};

  for (auto& value : RunningMedian(values)) {
    cout << value << " ";
  }
  cout << "\n";

  return 0;
}

