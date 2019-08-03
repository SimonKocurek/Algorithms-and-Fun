#include <iostream>

using namespace std;

int main() {
    int tasks;
    cin >> tasks;

    short difficulties[3][tasks];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < tasks; ++j) {
            cin >> difficulties[i][j];
        }
    }

    int start_subintervals[3][tasks];
    int end_subintervals[3][tasks];
    for (int j = 0; j < 3; ++j) {
        start_subintervals[j][0] = difficulties[j][0];
        end_subintervals[j][tasks - 1] = difficulties[j][tasks - 1];

        for (int l = 1; l < tasks; ++l) {
            start_subintervals[j][l] = start_subintervals[j][l - 1] + difficulties[j][l];
            end_subintervals[j][tasks - 1 - l] = end_subintervals[j][tasks - l] + difficulties[j][tasks - 1 - l];
        }
    }

    const int options[6][3] = {{0, 1, 2},
                               {0, 2, 1},
                               {1, 0, 2},
                               {1, 2, 0},
                               {2, 0, 1},
                               {2, 1, 0}};
    int result = INT32_MAX;
    for (auto &option : options) {
        for (int i = 0; i < tasks - 2; ++i) {
            for (int j = i + 1; j < tasks - 1; ++j) {
                int count = 0;
                for (int k = i + 1; k <= j; ++k) {
                    count += difficulties[option[1]][k];
                }

                result = min(result, start_subintervals[option[0]][i] + count + end_subintervals[option[2]][j + 1]);
            }
        }
    }

    cout << result;

    return 0;
}
