#include <bits/stdc++.h>

using namespace std;

int BoysUntilGirl() {
    int result = 0;

    while (rand() % 2) {
        result++;
    }

    return result;
}

int main() {
    int girls = 10000000;
    int boys = 0;
    for (int i = 0; i < girls; ++i) {
        boys += BoysUntilGirl();
    }

    cout << "Ratio: " << (double) girls / boys << "\n";

    return 0;
}
