#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 6> input = {31, 41, 59, 26, 41, 58};

    for (int i = 1; i < input.size(); i++) {
        auto key = input[i];
        int j = i - 1;
        while (j >= 0 && input[j] > key) {
            input[j + 1] = input[j];
            j--;
        }

        input[j + 1] = key;
    }

    for (auto res: input) {
        cout << res << " ";
    }
    cout << '\n';

    return 0;
}

