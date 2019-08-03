#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int array[]{13, 53, 645, 1, 34, 6, 94};

    for (int i = 0; i < 6; ++i) {
        int& min = *min_element(array + i, array + 7);
        int temp = array[i];
        array[i] = min;
        min = temp;
    }

    for (int i = 0; i < 7; ++i) {
        cout << array[i] << " ";
    }
    return 0;
}

