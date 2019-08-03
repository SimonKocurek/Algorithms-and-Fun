#include <bits/stdc++.h>

using namespace std;

struct element {
    int position;
    int value;

    inline bool operator>(const element& a) const {
        return value > a.value;
    }
};

int max_sum(vector<int>& arr) {
    if (arr.size() < 3) {
        throw;
    }

    priority_queue<element, vector<element>, greater<element>> heap;
    for (int i = 0; i < 3; ++i) {
        heap.push({i, arr[i]});
    }

    for (uint32_t i = 3; i < arr.size(); ++i) {
        if (arr[i] > heap.top().value) {
            heap.pop();
            heap.push({i, arr[i]});
        }
    }

    vector<element> highest(3);
    for (int i = 0; i < 3; ++i) {
        highest[i] = heap.top();
        heap.pop();
    }

    if (abs(highest[2].position - highest[1].position) > 1) {
        return highest[2].value + highest[1].value;
    } else {
        return highest[2].value + highest[0].value;
    }
}

int main() {
    vector<int> a {2, 4, 6, 8};
    vector<int> b {5, 1, 1, 5};
    vector<int> c {8, 7, 6, 8};
    vector<int> d {100, 10, 10, 20, 20};

    cout << max_sum(a) << "\n";
    cout << max_sum(b) << "\n";
    cout << max_sum(c) << "\n";
    cout << max_sum(d) << "\n";

    return 0;
}

