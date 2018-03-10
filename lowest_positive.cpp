#include <bits/stdc++.h>

using namespace std;

int first_in_modified(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    return arr.size() + 1;
}

bool valid(vector<int> &arr, int number) {
    return number > 0 && number <= arr.size();
}

int first_missing_int(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        auto value = arr[i];

        if (valid(arr, value)) {
            if (value - 1 > i) {
                swap(arr[value - 1], arr[i]);
                i--;
            } else {
                arr[value - 1] = value;
            }
        }
    }

    return first_in_modified(arr);
}

int main() {
    vector<int> a {3, 4, -1, 1};
    vector<int> b {1, 2, 0};
    vector<int> c {2, -1, 4, 0, 5, 1};
    vector<int> d {-5, -4, 0, -2};
    vector<int> e {8, 7, 20, 3};

    cout << first_missing_int(a) << "\n";
    cout << first_missing_int(b) << "\n";
    cout << first_missing_int(c) << "\n";
    cout << first_missing_int(d) << "\n";
    cout << first_missing_int(e) << "\n";

    return 0;
}

