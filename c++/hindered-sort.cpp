#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int count;
    cin >> count;

    int input[count];
    bool wrong[count]{0};
    for (int i = 0; i < count; ++i) {
        cin >> input[i];
    }

    int wrong_max = -1;

    for (int current = 1, previous = 0; current < count; ++current) {
        if (input[previous] > input[current]) {
            wrong[current] = true;
            wrong_max = max(wrong_max, input[current]);
            continue;
        }

        while(wrong[++previous]);
    }
    
    int result = 0;

    for (int i = 0; i < count; ++i) {
        if (wrong[i] || input[i] < wrong_max) {
            result++;
        }
    }

    cout << result;

    return 0;
}

