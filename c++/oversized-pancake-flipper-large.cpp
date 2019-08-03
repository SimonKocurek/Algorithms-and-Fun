#include <bits/stdc++.h>

using namespace std;

int Flip(vector<bool>& pancakes, int flipper) {
  int flips = 0;

  for (int i = 0; i < pancakes.size() - flipper + 1; ++i) {
    if (!pancakes[i]) {
      flips++;

      for (int j = 0; j < flipper; ++j) {
        pancakes[i + j] = !pancakes[i + j];
      }
    }
  }

  for (int i = pancakes.size() - flipper + 1; i < pancakes.size(); ++i) {
    if (!pancakes[i]) {
      return -1;
    }
  }

  return flips;
}

void PrintResult(int result, int id) {
  cout << "Case #" << id << ": ";

  if (result == -1) {
    cout << "IMPOSSIBLE";
  } else {
    cout << result;
  }

  cout << "\n";
}

vector<bool> LoadPancakes() {
  string in;
  cin >> in;

  vector<bool> pancakes;
  pancakes.reserve(in.length());

  for (auto c : in) {
    pancakes.push_back(c == '+');
  }
  return pancakes;
}

int LoadFlipper() {
  int flipper;
  cin >> flipper;
  return flipper;
}

int main() {
  int sets;
  cin >> sets;

  for (int i = 1; i <= sets; ++i) {
    auto pancakes = LoadPancakes();
    auto flipper = LoadFlipper();

    auto result = Flip(pancakes, flipper);
    PrintResult(result, i);
  }

  return 0;
}

