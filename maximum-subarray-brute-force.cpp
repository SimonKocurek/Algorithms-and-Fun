#include <iostream>

using namespace std;

int main() {
    int count;
    cin >> count;

    int array[count];
    for (int &number : array) {
        cin >> number;
    }

    int start = 0;
    int end = 0;
    int max = 0;

    for (int i = 0; i < count; ++i) {
        int current_max = 0;
        for (int j = i; j < count; ++j) {
            current_max += array[j];

            if (current_max > max) {
                max = current_max;
                start = i;
                end = j;
            }
        }
    }

    cout << start << "  " << end << '\n' << "Max: " << max;
    return 0;
}

