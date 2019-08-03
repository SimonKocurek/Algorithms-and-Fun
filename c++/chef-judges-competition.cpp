#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        int races;
        cin >> races;

        ll a_sum = 0;
        ll b_sum = 0;

        int a_max = 0;
        int b_max = 0;

        for (int j = 0; j < races; ++j) {
            int c;
            cin >> c;

            a_sum += c;
            a_max = max(a_max, c);
        }
        for (int j = 0; j < races; ++j) {
            int c;
            cin >> c;

            b_sum += c;
            b_max = max(b_max, c);
        }

        if (a_sum - a_max > b_sum - b_max) {
            cout << "Bob\n";
        } else if (a_sum - a_max == b_sum - b_max) {
            cout << "Draw\n";
        } else {
            cout << "Alice\n";
        }
    }
    return 0;
}