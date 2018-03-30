#include <bits/stdc++.h>
#define MAX_BITS 99

using namespace std;

typedef pair<int, bitset<MAX_BITS>> sizedBitset; 

int flip(sizedBitset& pancakes, int flipper) {
  if (pancakes.second.none()) {
    return 0;
  }

  unordered_set<bitset<MAX_BITS>> seen;
  queue<pair<bitset<MAX_BITS>, int>> next;

  seen.insert(pancakes.second);
  next.push({pancakes.second, 0});

  while (!next.empty()) {
    auto current = next.front();
    next.pop();

  }

  return -1;
}

void printResult(int result) {
  if (result == -1) {
    cout << "IMPOSSIBLE" << "\n";
  } else {
    cout << result << "\n";
  }
}

sizedBitset loadPancakes() {
  string in;
  cin >> in;

  int bits = in.length();
  bitset<MAX_BITS> pancakes(in, 0, bits, '+', '-');

  return {bits, pancakes};
}

int loadFlipper() {
  int flipper;
  cin >> flipper;
  return flipper;
}

int main() {
  int sets;
  cin >> sets;
  for (int i = 0; i < sets; ++i) {
    auto pancakes = loadPancakes();
    auto flipper = loadFlipper();

    auto result = flip(pancakes, flipper);
    printResult(result);
  }
  return 0;
}

