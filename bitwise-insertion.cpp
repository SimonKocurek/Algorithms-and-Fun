#include <bits/stdc++.h>

using namespace std;

int stuff(int original, int stuffed, int start, int end) {
  auto start_mask = (1 << (start + 1)) - 1;
  auto end_mask = (1 << end) - 1;
  auto mask = ~(start_mask & ~end_mask);

  auto cleared = original & mask;
  return cleared | (stuffed << end);
}

int main() {
  auto n = 0b10000000000;
  auto m = 0b10011;

  auto result = stuff(n, m, 6, 2);
  for (int i = 31; i >= 0; --i) {
    auto bit = result & (1 << i);
    auto printed = bit != 0;

    cout << printed;
  }
  cout << "\n";

  return 0;
}

