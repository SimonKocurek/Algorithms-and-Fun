#include <bits/stdc++.h>

using namespace std;

double pi_estimate() {
    double in = 0;
    double all = 0;
    double result = 0;

    while (true) {
        double x = ((double) rand() / RAND_MAX) * 2 - 1;
        double y = ((double) rand() / RAND_MAX) * 2 - 1;

        if (x * x + y * y <= 1) {
            in++;
        }
        all++;

        double new_result = in * 4 / all;
        if (in > 10 && all - in >= 10 && abs(result - new_result) <= 0.00001) {
            return new_result;
        } else {
            result = new_result;
        }
    }
}

int main() {
    cout << setprecision(3) << fixed;
    cout << pi_estimate() << "\n";
    cout << pi_estimate() << "\n";
    cout << pi_estimate() << "\n";

    return 0;
}
