#include <bits/stdc++.h>

using namespace std;

int64_t lowest_multiplications(vector<int>& sizes, vector<vector<int64_t>>& multiplications) {
    for (int len = 2; len < multiplications.size(); ++len) {
        for (int start = 0; start < multiplications.size() - len; ++start) {
            int end = start + len;
            multiplications[start][end] = LLONG_MAX;

            for (int cut = start + 1; cut < end; ++cut) {
                multiplications[start][end] = min(
                    multiplications[start][cut] + (sizes[start] * sizes[cut] * sizes[end]) + multiplications[cut][end],
                    multiplications[start][end]
                );
            }
        }
    }

    return multiplications.front().back() % 99991;
}

int64_t lowest_multiplications(vector<int>& sizes) {
    vector<vector<int64_t>> multiplications(sizes.size(), vector<int64_t>(sizes.size(), 0));
    return lowest_multiplications(sizes, multiplications);
}

int main() {
    int matrixes;
    cin >> matrixes;

    vector<int> sizes(matrixes + 1);
    for (auto& size : sizes) {
        cin >> size;
    }

    cout << lowest_multiplications(sizes) << endl;

    return 0;
}
