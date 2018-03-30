#include <bits/stdc++.h>
#define MAX_BITS 1000

using namespace std;

typedef bitset<MAX_BITS> Bitset;
typedef pair<int, Bitset> SizedBitset; 
typedef pair<Bitset, int> DistantBitset;

struct comparator {
  bool operator()(const DistantBitset& a, const DistantBitset& b) {
    return a.second > b.second ||
      a.second == b.second &&
      a.first.count() > b.first.count();
  }
};

int Flip(SizedBitset& pancakes, SizedBitset& flipper) {
  if (pancakes.second.none()) {
    return 0;
  }

  unordered_set<Bitset> seen;
  priority_queue<DistantBitset, vector<DistantBitset>, comparator> next;

  seen.insert(pancakes.second);
  next.push({pancakes.second, 0});

  while (!next.empty()) {
    auto current = next.top();
    next.pop();

    auto next_distance = current.second + 1;
    auto current_pancakes = current.first;

    auto moved_flipper = flipper.second;
    for (int i = 0; i < pancakes.first - flipper.first + 1; ++i) {
      auto flipped = current_pancakes ^ moved_flipper; 
      moved_flipper <<= 1;

      if (flipped.none()) {
        return next_distance;
      }

      if (seen.find(flipped) != seen.end()) {
        continue;
      }

      seen.insert(flipped);
      next.push({flipped, next_distance});
    }
  }

  return -1;
}

void PrintResult(int result, int id) {
  cout << "Case #" << (id + 1) << ": ";

  if (result == -1) {
    cout << "IMPOSSIBLE" << "\n";
  } else {
    cout << result << "\n";
  }
}

SizedBitset LoadPancakes() {
  string in;
  cin >> in;

  int bits = in.length();
  Bitset pancakes(in, 0, bits, '+', '-');

  return {bits, pancakes};
}

SizedBitset LoadFlipper() {
  int bits;
  cin >> bits;

  Bitset flipper;
  for (int i = 0; i < bits; ++i) {
    flipper[i] = true;
  }
  return {bits, flipper};
}

int main() {
  int sets;
  cin >> sets;
  for (int i = 0; i < sets; ++i) {
    auto pancakes = LoadPancakes();
    auto flipper = LoadFlipper();

    auto result = Flip(pancakes, flipper);
    PrintResult(result, i);
  }
  return 0;
}

