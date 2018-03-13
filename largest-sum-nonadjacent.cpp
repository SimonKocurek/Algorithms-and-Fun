#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll max_sum(vector<int>& arr) {
    ll result = 0;

    int last_taken = INT_MIN;
    for (int i = 0; i < arr.size(); ++i) {
        if (last_taken + 1 == i) {
            if (arr[i] > arr[last_taken]) {
                result -= arr[last_taken];
                result += arr[i];
                last_taken = i;
            }
            continue;
        }

        result += arr[i];
        last_taken = i;
    }

    return result;
}

int main() {
    vector<int> a {2, 4, 6, 8};
    vector<int> b {5, 1, 1, 5};
    vector<int> c {8, 7, 6, 8};
    vector<int> d {100, 10, 10, 20, 20};
    vector<int> e {5, 5, 10, 100, 10, 5};

    cout << max_sum(a) << "\n";
    cout << max_sum(b) << "\n";
    cout << max_sum(c) << "\n";
    cout << max_sum(d) << "\n";
    cout << max_sum(e) << "\n";

    return 0;
}

