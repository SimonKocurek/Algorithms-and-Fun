#include <bits/stdc++.h>

using namespace std;

int Sum(string& instructions) {
  int result = 0;
  int size = 1;

  for (auto& c : instructions) {
    if (c == 'C') {
      size *= 2;
    } else {
      result += size;
    }
  }

  return result;
}

void Swap(string& instructions) {
  for (int i = instructions.size() - 1; i > 0; --i) {
    if (instructions[i] == 'S' && instructions[i - 1] == 'C') {
      instructions[i] = 'C';
      instructions[i - 1] = 'S';

      return;
    }
  }
}

void Solve() {
  int damage;
  string instructions;

  cin >> damage >> instructions;

  int shots = 0;
  for (auto& instruction : instructions) {
    if (instruction == 'S') {
      shots++;
    }
  }

  if (shots > damage) {
    cout << "IMPOSSIBLE";
    return;
  }

  int swaps = 0;
  while (Sum(instructions) > damage) {
    Swap(instructions);
    swaps++;
  }

  cout << swaps;
}

int main() {
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; ++i) {
    cout << "Case #" << i << ": ";
    Solve();
    cout << "\n";
  }

  return 0;
}

