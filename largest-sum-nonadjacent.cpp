#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int biggest(vector<int>& arr) {
    int result = 0;
    for (auto num : arr) {
        result = max(result, num);
    }
    return result;
}

void swap(ll& a, ll& b, ll& c) {
    ll temp = a;

    a = b;
    b = c;
    c = temp;
}

ll max_sum(vector<int>& arr) {
    if (arr.size() <= 2) {
        return biggest(arr);
    }

    ll first = arr[0];
    ll second = max(arr[0], arr[1]);
    ll last;

    for (int i = 2; i < arr.size(); ++i) {
        last = max(first + arr[i], second);
        swap(first, second, last);
    }

    return second;
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

