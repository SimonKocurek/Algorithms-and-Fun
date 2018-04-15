#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> LoadValues(const int y, const int x) {
    vector<vector<int>> values(y, vector<int>(x));
    
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            char c;
            cin >> c;

            if (c >= '1' && c <= '9') {
                values[i][j] = c - '0';
            }

            else if (c == '#') {
                values[i][j] = -1;
            }

            else {
                values[i][j] = 0;
            }
        }
    }

    return values;
}

void FillLine(vector<vector<vector<int>>>& possibilities, const vector<vector<int>>& values) {
    for (int i = 1; i < values.front().size(); ++i) {
        if (values[0][i] == -1) {
            break;
        }

        for (int k = 0; k < possibilities.size(); ++k) {
            possibilities[k][0][i] = possibilities[k][0][i - 1];
        }

        int added = values[0][i];
        if (added > 0) {
            for (int k = added; k < possibilities.size(); ++k) {
                possibilities[k][0][i] += possibilities[k - added][0][i - 1];
            }   
        }
    }
}

void FillColumn(vector<vector<vector<int>>>& possibilities, const vector<vector<int>>& values) {
    for (int i = 1; i < values.size(); ++i) {
        if (values[i][0] == -1) {
            break;
        }

        for (int k = 0; k < possibilities.size(); ++k) {
            possibilities[k][i][0] = possibilities[k][i - 1][0];
        }

        int added = values[i][0];
        if (added > 0) {
            for (int k = added; k < possibilities.size(); ++k) {
                possibilities[k][i][0] += possibilities[k - added][i - 1][0];
            }
        }
    }
}

void FillRest(vector<vector<vector<int>>>& possibilities, const vector<vector<int>>& values) {
    for (int i = 1; i < values.size(); ++i) {
        for (int j = 1; j < values.front().size(); ++j) {
            if (values[i][j] == -1) {
                continue;
            }
        
            for (int k = 0; k < possibilities.size(); ++k) {
                possibilities[k][i][j] = (possibilities[k][i - 1][j] + possibilities[k][i][j - 1]) % 999983;
            }

            int added = values[i][j];
            if (added > 0) {
                for (int k = added; k < possibilities.size(); ++k) {
                    possibilities[k][i][j] += (possibilities[k - added][i - 1][j] + possibilities[k - added][i][j - 1]) % 999983;
                }
            }
        }
    }
}

int Solve(const int y, const int x, const int target) {
    auto values = LoadValues(y, x);
    vector<vector<vector<int>>> possibilities(
        target + 1,
        vector<vector<int>>(y, vector<int>(x, 0)));
    
    possibilities[0][0][0] = 1;
    FillLine(possibilities, values);
    FillColumn(possibilities, values);
    FillRest(possibilities, values);

    return possibilities.back().back().back();
}

int main() {
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; ++i) {
        int y, x, target;
        cin >> y >> x >> target;
        cout << Solve(y, x, target) << "\n";
    }

    return 0;
}
