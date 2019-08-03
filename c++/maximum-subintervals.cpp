/*
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each
subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results.
You can simply print them out as you compute them.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> maxes(vector<int>& values, int k) {
    vector<int> result;
    deque<int> max;

    for (int i = 0; i < values.size(); ++i) {
        max.push_back(i);

        if (max.front() <= i - k) {
            max.pop_front();
        }

        while (values[max.front()] < values[i]) {
            max.pop_front();
        }

        if (i >= k - 1) {
            result.push_back(values[max.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> a {10, 5, 2, 7, 8, 7};
    vector<int> b {1, 2};

    for (auto& num : maxes(a, 3)) {
        cout << num << " ";
    }
    cout << "\n";

    for (auto& num : maxes(b, 2)) {
        cout << num << " ";
    }
    cout << "\n";

    for (auto& num : maxes(a, 2)) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}

