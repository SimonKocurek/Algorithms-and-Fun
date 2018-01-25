#include <iostream>

using namespace std;

struct subarray {
    int start;
    int end;
    int max;
};

subarray max_cross_subarray(int *array, int start, int middle, int end) {
    int max;

    subarray left = {0, 0, 0};
    max = 0;
    for (int i = middle; i >= start; --i) {
        max += array[i];
        if (max > left.max) {
            left.max = max;
            left.start = i;
        }
    }

    subarray right = {0, 0, 0};
    max = 0;
    for (int i = middle + 1; i <= end; ++i) {
        max += array[i];
        if (max > right.max) {
            right.max = max;
            right.end = i;
        }
    }

    return {left.start, right.end, left.max + right.max};
}

subarray max_subarray(int *array, int start, int end) {
    if (start > end) {
        throw;
    }

    if (start == end) {
        return {start, end, array[start]};
    }

    auto middle = (start + end) / 2;

    auto left = max_subarray(array, start, middle);
    auto right = max_subarray(array, middle+ 1, end);
    auto cross = max_cross_subarray(array, start, middle, end);

    if (left.max >= right.max && left.max >= cross.max) {
        return left;
    }

    if (right.max >= left.max && right.max >= cross.max) {
        return right;
    }

    return cross;
}

int main() {
    int count;
    cin >> count;

    int array[count];
    for (auto &number : array) {
        cin >> number;
    }

    subarray result = max_subarray(array, 0, count - 1);

    cout << "Start: " << result.start << ". End: " << result.end << ". Max: " << result.max << '\n';
    return 0;
}

