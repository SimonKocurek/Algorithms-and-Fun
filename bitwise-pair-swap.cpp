#include <bits/stdc++.h>

using namespace std;

int Swap(const int a) {
    const int odd_mask = 0b01010101010101010101010101010101;
    const int even_mask = 0b10101010101010101010101010101010;

    return ((a & odd_mask) << 1) | ((a & even_mask) >> 1);
}

int PrintBits(const int a) {
    for (int i = 31; i >= 0; --i) {
        cout << ((a & (1 << i)) != 0);
    }
    cout << "\n";
}

int main() {
    PrintBits(Swap(0b001101));
    PrintBits(Swap(0b111000));
    PrintBits(Swap(0b10110));

    return 0;
}
