#include <bits/stdc++.h>

using namespace std;

long possible_steps(int stairs) {
    if (stairs <= 1) {
        return max(0, stairs);
    }
    
    long a = 1;
    long b = 1;
    long c;

    for (int i = 1; i < stairs; ++i) {
        c = a + b;

        a = b;
        b = c;
    }

    return c;
}

int main() {
    cout << possible_steps(0) << "\n";
    cout << possible_steps(1) << "\n";
    cout << possible_steps(2) << "\n";
    cout << possible_steps(3) << "\n";
    cout << possible_steps(4) << "\n";

    return 0;
}
