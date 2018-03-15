#include <bits/stdc++.h>

using namespace std;

int longest_subsequence(vector<int>& arr) {
    int result = 0;

    

    return result;
}

int main() {
    vector<int> a {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> b {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    vector<int> c {6, 2, 5, 1, 7, 4, 8};
    vector<int> d {};
    vector<int> e {1};

    cout << longest_subsequence(a) << " Expected: 6\n";
    cout << longest_subsequence(b) << " Expected: 6\n";
    cout << longest_subsequence(c) << " Expected: 4\n";
    cout << longest_subsequence(d) << " Expected: 0\n";
    cout << longest_subsequence(e) << " Expected: 1\n";

    return 0;
}

