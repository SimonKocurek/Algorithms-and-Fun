#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int numbers;
    cin >> numbers;
    
    vector<int> unsorted(numbers);
    for (auto &unsorted_number : unsorted) {
        cin >> unsorted_number;
    }

    int start = *min_element(unsorted.begin(), unsorted.end());
    int end = *max_element(unsorted.begin(), unsorted.end());

    vector<int> counts(end - start + 1);
    for (auto &unsorted_number : unsorted) {
        counts[unsorted_number - start]++;
    }

    vector<int> sorted(numbers);
    int i = 0;
    for (int k = 0; k <= end - start; ++k) {
        for (int j = 0; j < counts[k]; ++j, ++i) {
            sorted[i] = k + start;
        }
    }
    
    for (auto &sorted_number : sorted) {
        cout << sorted_number << " ";
    }

    return 0;
}

