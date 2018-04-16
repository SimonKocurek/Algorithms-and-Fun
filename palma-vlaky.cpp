#include <bits/stdc++.h>

using namespace std;

int Solve(const int supervisors, const vector<int>& cars) {
    vector<vector<int>> solutions (supervisors, vector<int>(cars.size()));

    solutions[0][0] = cars[0];
    for (int i = 1; i < cars.size(); ++i) {
        solutions[0][i] = solutions[0][i - 1] + cars[i];
    }

    for (int i = 1; i < supervisors; ++i) {
        for (int j = i; j < cars.size(); ++j) {
            int solution = max(cars[j], solutions[i - 1][j - 1]);

            int count = cars[j];
            for (int k = j - 1; k >= i && count < solutions[i - 1][k - 1]; --k) {
                count += cars[k];
                solution = min(solution, max(count, solutions[i - 1][k - 1]));
            }

            solutions[i][j] = solution;
        }
    }

    return solutions.back().back();
}

int main() {
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; ++i) {
        int supervisors, car_count;
        cin >> supervisors >> car_count;

        vector<int> cars(car_count);
        for (auto& car : cars) {
            cin >> car;
        }

        cout << Solve(supervisors, cars) << "\n";
    }

    return 0;
}
