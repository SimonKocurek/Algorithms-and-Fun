#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    if (size == 1) {
        cout << 1 << '\n';
        return 0;
    }

    int last_start = 1;
    int current;
    int next;
    cin >> current >> next;
    int difference = current - next;

    for (int i = 2; i < size; ++i) {
        current = next;
        cin >> next;

        if (current - next != difference) {
            last_start = i;
            difference = current - next;
        }
    }

    cout << last_start << '\n';

    return 0;
}
