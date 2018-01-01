#include <iostream>

using namespace std;

struct point {
    int x;
    int y;
};

int main() {
    int y, x;
    cin >> y >> x;
    
    int matrice[y][x];
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            cin >> matrice[i][j];
        }
    }

    point current{x - 1, 0};
    int result = 0;
    
    while (current.x >= 0 && current.y < y) {
        if (matrice[current.y][current.x] >= 0) {
            current.x--;
        } else {
            current.y++;
            result += current.x + 1;
        }
    }

    cout << result;

    return 0;
}

