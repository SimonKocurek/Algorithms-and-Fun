#include <bits/stdc++.h>

using namespace std;

int random(vector<int>::iterator begin, vector<int>::iterator end) {
    int count = 1;
    int chosen;

    while (begin < end) {
        if (rand() % count == 0) {
            chosen = *begin;
        }

        begin++;
        count++;
    }

    return chosen;
}

int main() {
    vector<int> a {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    vector<int> b {6};

    int counts[18] = {};
    for (int i = 0; i < 100000; ++i) {
        counts[random(a.begin(), a.end())]++;
    }

    for (auto& num : counts) {
        cout << num << "\n";
    }
    cout << random(b.begin(), b.end()) << "\n";

    return 0;
}

