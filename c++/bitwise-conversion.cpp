#include <bits/stdc++.h>

using namespace std;

int NeededFlips(const int a, const int b) {
    return __builtin_popcount(a ^ b);
}

int main() {
    cout << NeededFlips(0b0, 0b0) << endl;
    cout << NeededFlips(0b0, 0b1) << endl;
    cout << NeededFlips(0b0, 0b11) << endl;
    cout << NeededFlips(0b0, 0b01) << endl;
    cout << NeededFlips(0b0110, 0b1010) << endl;
    cout << NeededFlips(0b000000, 0b0111111) << endl;
    cout << NeededFlips(0b111110101010100, 0b0) << endl;
    cout << NeededFlips(0b11101, 0b01111) << endl;
}
