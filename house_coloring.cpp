/*
   This problem was asked by Facebook.

   A builder is looking to build a row
   of N houses that can be of K different
   colors. He has a goal of minimizing cost
   while ensuring that no two neighboring
   houses are of the same color.

   Given an N by K matrix where the nth
   row and kth column represents the
   cost to build the nth house with kth
   color, return the minimum cost which
   achieves this goal.
 */

#include <bits/stdc++.h>

using namespace std;

int min_index(vector<int>& costs, int excluded) {
    if (costs.size() == 1) {
        return 0;
    }

    int result = excluded == 0 ? 1 : 0;

    for (int i = 0; i < costs.size(); ++i) {
        if (i != excluded && costs[result] > costs[i]) {
            result = i;
        }
    }

    return result;
}

int min_index(vector<int>& costs) {
    return min_index(costs, -1);
}

int minimal_cost(vector<vector<int>>& costs) {
    if (costs.empty()) {
        return 0;
    }

    if (costs.size() > 1 && costs[0].size() < 2) {
        throw;
    }

    vector<vector<int>> results(costs.size(), vector<int>(costs[0].size()));
    results[0] = costs[0];

    for (int i = 1; i < costs.size(); ++i) {
        auto first_idx = min_index(results[i - 1]);
        auto second_idx = min_index(results[i - 1], first_idx);

        for (int j = 0; j < costs[0].size(); ++j) {
            results[i][j] = costs[i][j] + results[i - 1][first_idx];
        }

        results[i][first_idx] = costs[i][first_idx] + results[i - 1][second_idx]; 
    }

    return *min_element(results.back().begin(), results.back().end());
}

int main() {
    vector<vector<int>> costs_a {
        {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12}
    };

    vector<vector<int>> costs_b {
        {3, 5, 1, 8},
            {12, 74, 1, 7},
            {0, 2, 2, 9}
    };

    vector<vector<int>> costs_c;

    vector<vector<int>> costs_d {
        {1, 2},
            {2, 3},
            {3, 4}
    };

    vector<vector<int>> costs_e {
        {1}
    };

    cout << minimal_cost(costs_a) << " Expected: 24" << "\n";
    cout << minimal_cost(costs_b) << " Expected: 4" << "\n";
    cout << minimal_cost(costs_c) << " Expected: 0" << "\n";
    cout << minimal_cost(costs_d) << " Expected: 7" << "\n";
    cout << minimal_cost(costs_e) << " Expected: 1" << "\n";

    return 0;
}

