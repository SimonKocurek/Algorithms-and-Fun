#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Interval {
  ll start;
  ll end;

  inline bool operator<(const Interval& a) const {
    return (end - start) < (a.end - a.start);
  }
};

void Solve() {
  ll stalls, people;
  cin >> stalls >> people;

  priority_queue<Interval> intervals;
  intervals.push({1, stalls});

  for (ll i = 1; i < people; ++i) {
    auto interval = intervals.top();
    intervals.pop();

    ll middle = (interval.start + interval.end) / 2;

    intervals.push({interval.start, middle - 1});
    intervals.push({middle + 1, interval.end});
  }

  auto interval = intervals.top();
  ll middle = (interval.start + interval.end) / 2;
  cout << (interval.end - middle) << " " << (middle - interval.start);
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

