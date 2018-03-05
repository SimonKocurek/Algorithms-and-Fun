#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool have_sum(vector<int> &arr, int sum) {
    unordered_set<int> seen;

    for (auto num : arr) {
        if (seen.find(sum - num) != seen.end()) {
            return true;
        }

        seen.insert(num);
    }

    return false;
}

int main() {
    vector<int> a {1, 4, 4, 6, 8, 53, 1};
    cout << have_sum(a, 8) << endl;
    cout << have_sum(a, 5) << endl;
    cout << have_sum(a, 53) << endl;

    return 0;
}

