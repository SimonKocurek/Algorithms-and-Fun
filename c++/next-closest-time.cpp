#include <bits/stdc++.h>

using namespace std;

vector<int> sort_time_digits(vector<int>& time) {
    vector<int> result(time);
    sort(result.begin(), result.end());
    return result;
}

vector<int> transform_to_closest_time(vector<int>& time) {
    vector<int> result(time);
    vector<int> limits {2, result[0] == 2 ? 3 : 9, 5, 9};
    auto sorted = sort_time_digits(time);

    // Time unit
    for (int i = 3; i >= 0; --i) {

        // Replaced by digit (lowest to highest)
        for (auto digit : sorted) {
            // Replace
            if (result[i] < digit && digit <= limits[i]) {
                result[i] = digit;

                for (int j = i + 1; j < 4; ++j) {
                    result[j] = sorted[0];
                }

                return result;
            }
        }
    }

    // Overflow
    for (auto& digit : result) {
        digit = sorted[0];
    }
    return result;
}

int main() {
    string time_formatted;
    cin >> time_formatted;
    vector<int> time {time_formatted[0] - '0', time_formatted[1] - '0', time_formatted[3] - '0', time_formatted[4] - '0'};

    auto next_time = transform_to_closest_time(time);

    cout << next_time[0] << next_time[1] << ":" << next_time[2] << next_time[3] << endl;
    return 0;
}

// Minutes:
// 21:00 -> 0012 -> 21:01
// 21:21 -> 1122 -> 21:22
// 12:50 -> 0125 -> 12:51
// 19:34 -> 1349 -> 19:39

// 12:34 -> 1234 -> 12:41
// 01:34 -> 0134 -> 01:40
// 12:09 -> 0129 -> 12:10

// Hours:
// 13:59 -> 1359 -> 15:11
// 22:33 -> 2233 -> 23:22

// 12:22 -> 1222 -> 21:11

// Overflow:
// 23:59 -> 2359 -> 22:22
