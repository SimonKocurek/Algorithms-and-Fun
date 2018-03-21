#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> input;
    int len;
    cin >> len;
    for (int i = 0; i < len; ++i) {
        int digit;
        cin >> digit;
        input.push_back(digit);
    }
    
    vector<int> result;
    int carry = 1;
    for (int i = len - 1; i >= 0; --i) {
        result.push_back((input[i] + carry) % 10);
        carry = input[i] + carry == 10 ? 1 : 0;
    }
    if (carry == 1) {
        result.push_back(carry);
    }

    reverse(result.begin(), result.end());
    for (auto& digit: result) {
        cout << digit << " ";
    }

    return 0;
}

