#include <iostream>
#include <vector>

using namespace std;

struct point {
    int x, y;
};

auto get_zero_points(vector<vector<int>> &matrix) {
    vector<point> result;

    for (int y = 0; y < matrix.size(); ++y) {
        auto &line = matrix[y];
        for (int x = 0; x < line.size(); ++x) {
            if (line[x] == 0) {
                result.push_back({x, y});
            }
        }
    }

    return result;
}

void zero_matrix(vector<vector<int>> &matrix) {
    auto zero_points = get_zero_points(matrix);

    for (auto &zero_point : zero_points) {
        for (int x = 0; x < matrix[0].size(); ++x) {
            matrix[zero_point.y][x] = 0;
        }
        for (int y = 0; y < matrix.size(); ++y) {
            matrix[y][zero_point.x] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 0},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 0, 13, 14},
        {15, 16, 17, 18}};

    zero_matrix(matrix);

    for (auto &line : matrix) {
        for (auto value : line) {
            cout << value << " ";
        }
        cout << "\n";
    }

    return 0;
}

