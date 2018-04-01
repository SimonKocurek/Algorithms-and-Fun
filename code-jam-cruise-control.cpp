#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int distance, horses;
  cin >> distance >> horses;
  horses++;

  vector<pair<int, double>> horse(horses);
  horse[0] = {0, DBL_MAX};

  for (int i = 1; i < horses; ++i) {
    int position, speed;
    cin >> position >> speed;
    horse[i] = {position, speed};
  }

  sort(horse.begin(), horse.end());

  for (int i = horses - 2; i >= 0; --i) {
    auto position1 = horse[i].first;
    auto position2 = horse[i + 1].first;
    auto speed1 = horse[i].second;
    auto speed2 = horse[i + 1].second;

    if (speed1 > speed2) {
      double slower = (distance - position2) / (double) speed2;
      double faster_distance = distance - position1;

      horse[i].second = min(speed1, faster_distance / slower);
    }
  }

  cout << horse[0].second; 
}

int main() {
  int tests;
  cin >> tests;

  cout.precision(15);

  for (int i = 1; i <= tests; ++i) {
    cout << "Case #" << i << ": ";
    Solve();
    cout << "\n";
  }

  return 0;
}

