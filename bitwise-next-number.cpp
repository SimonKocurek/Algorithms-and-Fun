#include <bits/stdc++.h>

using namespace std;

int NextSmaller(const int a) {
    (a ^ (a - 1))
    const int smallest_bit = a & (((a - 1) << 1) + 1);
    return (a & (a - 1)) + smallest_bit;
}

int NextBigger(const int a) {
    const int smallest_bit = a & (((a - 1) << 1) + 1);
    const int added = a + smallest_bit;
    return __builtin_popcount(added) < __builtin_popcount(a) ? added + 1 : added;
}

int main() {
    cout << NextSmaller(36) << "\n";
    cout << NextSmaller(10) << "\n";
    cout << NextSmaller(23) << "\n";

    cout << NextBigger(36) << "\n";
    cout << NextBigger(10) << "\n";
    cout << NextBigger(23) << "\n";

    return 0;
}
