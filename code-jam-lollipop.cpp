#include <bits/stdc++.h>

using namespace std;

void Solve() {
    int customers;
    cin >> customers;

    vector<bool> sold(customers, false);
    vector<int> chances(customers, 0);

    for (int i = 0; i < customers; ++i) {
        int count;
        cin >> count;

        vector<int> wants(count);
        for (auto& want : wants) {
            cin >> want;
            chances[want]++;
        }

        int optimal = -1;
        int prob = INT_MAX;

        for (auto want : wants) {
            if (sold[want]) {
                continue;
            }

            if (chances[want] < prob) {
                prob = chances[want];
                optimal = want;
            }
        }

        if (optimal > -1) {
            sold[optimal] = true;
        }

        cout << optimal << endl;
    }
}

int main() {
    int tests;
    cin >> tests;

    for (int i = 1; i <= tests; ++i) {
        Solve();
    }

    return 0;
}
