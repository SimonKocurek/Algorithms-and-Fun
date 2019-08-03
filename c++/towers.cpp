#include <iostream>
#include <algorithm>

using namespace std;

bool can_jump_outside(const int tower[], int current, int end) {
    if (current >= end) {
        return true;
    }

    int optimal = -1;
    int last_reachable = current + tower[current];
    for (int i = current + 1; i <= last_reachable; ++i) {
        if (optimal == -1 || (optimal + tower[optimal] < i + tower[i])) {
            optimal = i;
        }
    }

    if (optimal == -1) {
        return false;
    }

    can_jump_outside(tower, optimal, end);
}

int main() {
    int tower_count;
    cin >> tower_count;
    
    int tower[tower_count];
    for (int i = 0; i < tower_count; ++i) {
        cin >> tower[i];
    }

    if (can_jump_outside(tower, 0, tower_count)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    return 0;
}

