#include <bits/stdc++.h>

using namespace std;

string binary(double in) {
    if (in < 0 || in > 1) {
        return "ERROR";
    }

    if (in == 0) {
        return "0.0";
    }

    if (in == 1) {
        return "1.0";
    }

    string result = "0.";
    double divider = 1 / 2.0;
    while (in && result.size() < 32) {

        if (in - divider >= 0) {
            in -= divider;
            result += '1';
        } else {
            result += '0';
        }

        divider /= 2.0;
    }

    return result;
}

int main() {
    double a = 1;
    double b = 0;
    double c = 0.72;
    double d = 0.234444;
    double e = 4;
    double f = 0.125;

    cout << binary(a) << "\n";
    cout << binary(b) << "\n";
    cout << binary(c) << "\n";
    cout << binary(d) << "\n";
    cout << binary(e) << "\n";
    cout << binary(f) << "\n";

    return 0;
}
