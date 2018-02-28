#include <iostream>

using namespace std;

void print_rotated_layout(int y, int x) {
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            auto vertical = i % 2 == 0;
            auto horizontal = j % 4 < 2;

            if (vertical) {
                cout << (horizontal ? 'o' : 'x');
            } else {
                cout << (horizontal ? 'x' : 'o');
            }
        }

        if (i + 1 < y) {
            cout << "\n";
        }
    }
}

void print_regular_layout(int y, int x) {
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            auto vertical = i % 4 < 2;
            auto horizontal = j % 2 == 0;

            if (vertical) {
                cout << (horizontal ? 'o' : 'x');
            } else {
                cout << (horizontal ? 'x' : 'o');
            }
        }

        if (i + 1 < y) {
            cout << "\n";
        }
    }
}

void print_layout(int y, int x) {
    if ((x == 1) || (x % 2 == 1 && y % 4 == 2)) {
        print_rotated_layout(y, x);
    } else {
        print_regular_layout(y, x);
    }
}

int main() {
    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        int y, x;
        cin >> y >> x;

        print_layout(y, x);
    }

    return 0;
}

