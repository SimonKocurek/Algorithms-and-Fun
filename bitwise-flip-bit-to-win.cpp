#include <bits/stdc++.h>

using namespace std;

int MaxBitsWithFlip(int a) {
    vector<int> right(32);
    int current = 0;
    for (int i = 0; i < 32; ++i) {
        if (a & (1 << i)) {
            current++;
        } else {
            current = 0;
        }

        right[31 - i] = current;
    }

    vector<int> left(32);
    current = 0;
    for (int i = 31; i >= 0; --i) {
        if (a & (1 << i)) {
            current++;
        } else {
            current = 0;
        }

        left[31 - i] = current;
    }

    int result = 0;
    if (left.front() == 0) {
        result = 1 + left[1];
    }
    if (right.back() == 0) {
        result = max(result, 1 + right[right.size() - 2]);
    }
    for (int i = 1; i < 31; ++i) {
        if (left[i] == 0) {
            result = max(result, left[i - 1] + 1 + right[i + 1]);
        }
    }
    return result;
}

int main() {
    int a = 0b11011101111;
    int b = 0b01;
    int c = 0b100111101;

    cout << MaxBitsWithFlip(a) << "\n";
    cout << MaxBitsWithFlip(b) << "\n";
    cout << MaxBitsWithFlip(c) << "\n";

    return 0;
}
