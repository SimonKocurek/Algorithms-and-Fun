#include <iostream>

using namespace std;

void merge(int *array, int start, int end) {
    int i = start;
    int j = (start + end) / 2 + 1;

    int i_end = (start + end) / 2;
    int j_end = end;
    while (i <
}

void merge_sort(int *array, int start, int end) {
    if (end - start <= 1) {
        return;
    }

    merge_sort(array, start, start + (start + end) / 2);
    merge_sort(array, (start + end) / 2 + 1, end);

    merge(array, start, end);
}

int main() {
    int array[]{3, 41, 52, 26, 38, 57, 9, 49};

    merge_sort(array, 0, 8);

    for (auto& elem: array) {
        cout << elem << " ";
    }
    return 0;
}

