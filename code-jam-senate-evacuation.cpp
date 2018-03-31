#include <bits/stdc++.h>

using namespace std;

vector<int> Load() {
  int parties;
  cin >> parties;

  vector<int> politicians(parties);
  for (auto& count : politicians) {
    cin >> count;
  }

  return politicians;
}

pair<int, int> MaxIndex(vector<int>& parties) {
  pair<int, int> result = {0, 1};

  for (int i = 1; i < parties.size(); ++i) {
    if (parties[result.first] <= parties[i]) {
      result.second = result.first;
      result.first = i;
    } else if (parties[result.second] <= parties[i]) {
      result.second = i;
    }
  }

  return result;
}

void solve() {
  auto parties = Load();
  int on = parties.size();

  while (true) {
    auto max = MaxIndex(parties);

    if (parties[max.first] == 0) {
      return;
    }

    if (parties[max.first] > parties[max.second] + 1) {
      parties[max.first] -= 2;

      char printed = 'A' + max.first;
      cout << printed << printed << " ";

    } else if (parties[max.first] > parties[max.second]) {
      parties[max.first] -= 1;

      if (parties[max.first] == 0) {
        on--;
      }

      char printed = 'A' + max.first;
      cout << printed << " ";

    } else if (parties[max.first] == parties[max.second] && 
        !(parties[max.first] == 1 && on == 3)) {
      parties[max.first] -= 1;
      parties[max.second] -= 1;

      char printed = 'A' + max.first;
      char printed2 = 'A' + max.second;
      cout << printed << printed2 << " ";

      if (parties[max.first] == 0) {
        on--;
      }
      if (parties[max.second] == 0) {
        on--;
      }

    } else {
      parties[max.first] -= 1;

      char printed = 'A' + max.first;
      cout << printed << " ";

      on--;
    }
  }
}

int main() {
  int tests;
  cin >> tests;

  for (int i = 1; i <= tests; ++i) {
    cout << "Case #" << i << ": ";
    solve();
    cout << "\n";
  }

  return 0;
}

