#include <bits/stdc++.h>

using namespace std;

int main() {
    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        int y,x;
        cin >> y >> x;
        
        int matr[y][x];
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < x; ++k) {
                cin >> matr[j][k];
            }
        }

        bool possible = true;

        if (matr[0][0] == -1) {
            matr[0][0] = 1;
        }

        for (int k = 1; k < x && possible; ++k) {
            if (matr[0][k] == -1) {
               matr[0][k] = matr[0][k - 1]; 
            } else if (matr[0][k] < matr[0][k - 1]) {
                possible = false;
            }
        }

        for (int j = 1; j < y && possible; ++j) {
            if (matr[j][0] == -1) {
                matr[j][0] = matr[j -1][0];
            } else if (matr[j][0] < matr[j - 1][0]) {
                possible = false;
            }

            for (int k = 1; k < x && possible; ++k) {
                if (matr[j][k] == -1) {
                    matr[j][k] = max(matr[j - 1][k], matr[j][k -1]);
                } else if (matr[j][k] < matr[j -1][k] || matr[j][k ] < matr[j][k - 1]) {
                    possible = false;
                }
            }
        }

        if (possible) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < x; ++k) {
                cout << matr[j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        } else {
            cout << -1 << "\n";
        }
 
    }
    return 0;
}