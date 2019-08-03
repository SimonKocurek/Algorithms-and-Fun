#include <bits/stdc++.h>

using namespace std;

int MaxBitsWithFlip(int a) {
    int result = 0;

    int last_zero = 0;
    int current = 0;
    for (int i = 0; i < 32; ++i) {
        current++;

        if ((a & (1 << i)) == 0) {
            current -= last_zero;
            last_zero = current;
        }

        result = max(result, current);
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
