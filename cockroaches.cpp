#include <iostream>
#include <vector>

using namespace std;

uint64_t swaps;
vector<int> merging_area;

void merge(int start, int end, vector<int> &values) {
    int middle = (end + start) / 2;

    int i = start;
    int j = middle + 1;
    int k = 0;

    while (i <= middle && j <= end) {
        if (values[i] <= values[j]) {
            merging_area[k++] = values[i++];
        } else {
            swaps += middle - i + 1;
            merging_area[k++] = values[j++];
        }
    }

    while (i <= middle) {
        merging_area[k++] = values[i++];
    }

    while (j <= end) {
        merging_area[k++] = values[j++];
    }

    for (int l = start; l <= end; ++l) {
        values[l] = merging_area[l - start];
    }
}

void merge_sort(int start, int end, vector<int> &values) {
    if (start >= end) {
        return;
    }

    int middle = (end + start) / 2;

    merge_sort(start, middle, values);
    merge_sort(middle + 1, end, values);

    merge(start, end, values);
}

int main() {
    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        uint64_t count;
        cin >> count;

        merging_area.reserve(count);

        vector<int> cockroaches(count);
        for (auto &cockroach : cockroaches) {
            cin >> cockroach;
        }

        swaps = 0;
        merge_sort(0, static_cast<int>(count - 1), cockroaches);

        cout << swaps << '\n';
    }

    return 0;
}
