#include <bits/stdc++.h>

using namespace std;

void DrawLine(vector<uint8_t>& arr, const int width, const int x1, const int x2, const int y) {
    if (x2 < x1) {
        DrawLine(arr, width, x2, x1, y);
    }

    const int bytes_in_line = width / 8;
    const int height = arr.size() / bytes_in_line;
    if (y >= height) {
        throw 1;
    }

    const int line = y * bytes_in_line;
    for (int i = line * 8 + x1; i <= line * 8 + x2; ++i) {
        const int element = i / 8;
        const int bit = (8 - 1) - (i % 8);

        arr[element] |= (1 << bit);
    }
}

void Print(const vector<uint8_t>& arr, const int width) {
    const int bytes_in_line = width / 8;
    const int height = arr.size() / bytes_in_line;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width / 8; ++j) {
            for (int k = 7; k >= 0; --k) {
                cout << ((arr[i * bytes_in_line + j] & (1 << k)) != 0);
            }
            cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<uint8_t> arr {
        {0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0}
    };
    const int width = 5 * 8;

    DrawLine(arr, width, 1, 34, 0);
    DrawLine(arr, width, 32, 12, 1);
    DrawLine(arr, width, 12, 0, 2);
    DrawLine(arr, width, 39, 39, 3);

    Print(arr, width);

    return 0;
}
