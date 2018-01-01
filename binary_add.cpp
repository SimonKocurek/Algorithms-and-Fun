#include <iostream>

using namespace std;

int main() {
    int digit_a[]{1, 1, 0, 1};
    int digit_b[]{1, 0, 0, 0};
    int result[5]{0};

    int carry = 0;
    for (int i = 3; i >= 0; --i) {
        result[i + 1] = (digit_a[i] + digit_b[i] + carry) % 2;
        carry = digit_a[i] + digit_b[i] + carry > 1 ? 1 : 0;
    }
    result[0] = carry;

    for (int i = 0; i < 5; ++i) {
        cout << result[i];
    }

    return 0;
}

