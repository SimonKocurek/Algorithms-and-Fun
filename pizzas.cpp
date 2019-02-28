#include <bits/stdc++.h>

using namespace std;

int64_t highest_price(vector<vector<int64_t>>& price, vector<int>& bottles, int start, int end, int year) {
    if (start == end) {
        return bottles[start] * year;
    }

    if (price[start + 1][end] == -1) {
        price[start + 1][end] = highest_price(price, bottles, start + 1, end, year + 1);
    }

    if (price[start][end - 1] == -1) {
        price[start][end - 1] = highest_price(price, bottles, start, end - 1, year + 1);
    }

    return max(
        price[start + 1][end] + year * bottles[start],
        price[start][end - 1] + year * bottles[end]
    );
}

int64_t highest_price(vector<int>& bottles) {
    vector<vector<int64_t>> price(bottles.size(), vector<int64_t>(bottles.size(), -1));
    return highest_price(price, bottles, 0, price.size() - 1, 1);
}

int main() {
    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        int bottle_count;
        cin >> bottle_count;

        vector<int> bottles(bottle_count);
        for (auto& bottle : bottles) {
            cin >> bottle;
        }

        cout << highest_price(bottles) << endl;
    }

    return 0;
}
