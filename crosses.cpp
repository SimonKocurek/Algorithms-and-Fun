#include <iostream>

using namespace std;

void print_layout(int y, int x) {
    if (x == 1) {

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

