#include <bits/stdc++.h>

using namespace std;

void Solve() {
    int ball_count;
    cin >> ball_count;
    
    vector<int> balls(ball_count);
    for (auto& ball : balls) {
        cin >> ball;
    }

    if (balls.front() == 0 || balls.back() == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    vector<int> promised(ball_count);
    
    int b = 0;
    int c = 0;
    int levels = 0;
    for (int wanted = 0; wanted < balls.size(); ++wanted) {
        while (balls[wanted] > 0) {
            levels = max(levels, abs(wanted - c));

            balls[wanted]--;
            promised[c++] = wanted;
        }
    }

    vector<string> result(levels + 1, "");
    for (int i = 0; i < levels; ++i) {
        for (int j = 0; j < promised.size(); ++j) {
            if (promised[j] == j) {
                result[i] += '.';
            } else if (promised[j] > j) {
                result[i] += '\\';
            } else {
                result[i] += '/';
            }
        }
    }

    for (int i = 0; i < promised.size(); ++i) {
        result.back() += '.';
    }

    cout << result.size() << "\n";
    for (auto& res : result) {
        cout << res << "\n";
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; ++i) {
    cout << "Case #" << i << ": ";
    Solve();
  }

  return 0;
}
