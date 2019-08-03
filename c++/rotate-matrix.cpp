#include <iostream>
#include <vector>

using namespace std;

void quarter_swap(vector<vector<int>> &matrix, int layer, int index) {
    int end = matrix.size() - 1;

    auto &first_field = matrix[layer][layer + index];
    auto &second_field = matrix[layer + index][end - layer];
    auto &third_field = matrix[end - layer][end - layer - index];
    auto &fourth_field = matrix[end - layer - index][layer];

    int first = first_field;
    int second = second_field;
    int third = third_field;
    int fourth = fourth_field;

    first_field = fourth;
    second_field = first;
    third_field = second;
    fourth_field = third;
}

void rotate_layer(vector<vector<int>> &matrix, int layer) {
    for (int i = layer; i < matrix.size() - layer - 1; ++i) {
        quarter_swap(matrix, layer, i);
    }
}

void rotate_matrix(vector<vector<int>> &matrix) {
    for (int i = 0; i * 2 < matrix.size(); ++i) {
        rotate_layer(matrix, i);
    }
}

int main() {
    vector<vector<int>> matrix = 
    {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    matrix = 
    {{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    rotate_matrix(matrix);

    for (auto line : matrix) {
        for (auto num : line) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}

