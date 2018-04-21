#include <bits/stdc++.h>

using namespace std;

unsigned int NextSmaller(const unsigned int a) {
    auto lowest_bit = a & (~(a - 1));
    
    if (lowest_bit == 0) {
        throw;

    } else if (lowest_bit == 1) {
        auto result = 0;
        for (int i = 0; i < __builtin_popcount(a); ++i) {
            result |= (1 << i);
        }

        while ((result << 1) < a) {
            result <<= 1;
        }

        if (result >= a) {
            throw;
        }
        
        return result;

    } else {
        return (a ^ lowest_bit) | (lowest_bit >> 1);
    }
}

unsigned int NextBigger(const unsigned int a) {
    if (a == UINT_MAX) {
        throw;
    }

    auto lowest_bit = a & (~(a - 1));
    auto result = a + lowest_bit;
    
    auto added = 0;
    for (int i = __builtin_popcount(result); i < __builtin_popcount(a); ++i) {
        added <<= 1;
        added |= 1;
    }

    return result | added;
}

void PrintBits(const unsigned int a) {
    for (int i = 31; i >= 0; --i) {
        cout << ((a & (1 << i)) != 0);
    }
    cout << "\n";
}

int main() {
    PrintBits(36);
    PrintBits(NextSmaller(36));
    PrintBits(NextBigger(36));
    cout << "\n";

    PrintBits(10);
    PrintBits(NextSmaller(10));
    PrintBits(NextBigger(10));
    cout << "\n";

    PrintBits(23);
    PrintBits(NextSmaller(23));
    PrintBits(NextBigger(23));
    cout << "\n";

    PrintBits(0b1001111);
    PrintBits(NextSmaller(0b1001111));
    PrintBits(NextBigger(0b1001111));
    cout << "\n";
    
    PrintBits(0b1000);
    PrintBits(NextSmaller(0b1000));
    PrintBits(NextBigger(0b1000));
    cout << "\n";

    PrintBits(0b100010);
    PrintBits(NextSmaller(0b100010));
    PrintBits(NextBigger(0b100010));
    cout << "\n";

    PrintBits(0b01001100);
    PrintBits(NextSmaller(0b01001100));
    PrintBits(NextBigger(0b01001100));
    cout << "\n";

    PrintBits(0b111);
    PrintBits(NextSmaller(0b111));
    PrintBits(NextBigger(0b111));
    cout << "\n";

    return 0;
}
