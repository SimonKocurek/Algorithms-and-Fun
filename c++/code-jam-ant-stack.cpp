#include <bits/stdc++.h>

using namespace std;

void Solve() {
    int ant_count;
    cin >> ant_count;

    vector<int> ants(ant_count);
    for (auto& ant : ants) {
        cin >> ant;
    }

    vector<vector<int>> dp(ant_count, vector<int>(ant_count));
    int result = 1;

    for (int i = ant_count - 1; i >= 0; --i) {

        int got = ants[i] * 6;
        for (int k = i; k >= 0; --k) {
            dp[0][k] = got;
        }

        for (int j = 1; j <= i; ++j) {
            bool possible = false;
            got = min(ants[i - j] * 6, dp[j - 1][i - j + 1] - ants[i - j]);

            for (int k = i - j; k >= 0; --k) {
                auto current = min(dp[j - 1][k + 1] - ants[k], ants[k] * 6);
                got = max(current, got);
                dp[j][k] = got;
                if (got >= 0) {
                    possible = true;
                }
            }

            if (possible) {
                result = max(result, j + 1);                
            } else {
                break;
            }
        }
    }

    cout << result;
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
