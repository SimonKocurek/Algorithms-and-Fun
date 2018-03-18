#include <bits/stdc++.h>

using namespace std;

int main() {
    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        int x;
        cin >> x;

        long long result = 0;

        int a = 0;
        int b = 1;
        while (a + b <= x) {
            a += b;
            b++;
            result++;            
        }

        result += min(x - a, 1 + (a + b - x));

        cout << result << "\n";
    }
    return 0;
}