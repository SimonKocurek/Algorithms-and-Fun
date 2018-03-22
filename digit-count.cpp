#include <iostream>

using namespace std;

int main() {
    const int DIGITS = 9;
    int digit_count[DIGITS] = {0};

    int numbers;
    cin >> numbers;
    for (int i = 0; i < numbers; ++i) {
        int number;
        cin >> number;

        int digit = -1;
        while (number > 0) {
            digit = number % 10;
            number /= 10;
        }

        digit_count[digit - 1]++;
    }

    bool finished = false;
    for (int j = 1; j < DIGITS; ++j) {
        if (digit_count[j - 1] < digit_count[j]) {
            finished = true;
            cout << j << " " << digit_count[j - 1] << " " << digit_count[j];
            break;
        }
    }

    if (!finished) {
        cout << 0;
    }

    cout << '\n';

    return 0;
}
