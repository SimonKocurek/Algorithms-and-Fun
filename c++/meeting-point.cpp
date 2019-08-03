#include <bits/stdc++.h>

using namespace std;

int main() {
    int count;
    cin >> count;

    vector<pair<int, int>> people;
    vector<int> x_cords;
    vector<int> y_cords;
    for (int i = 0; i < count; ++i) {
        int x, y;
        cin >> x >> y;

        people.push_back({x, y});
        x_cords.push_back(x);
        y_cords.push_back(y);
    }

    if (count <= 1) {
        return 0;
    }

    sort(x_cords.begin(), x_cords.end());
    sort(y_cords.begin(), y_cords.end());

    double x, y;
    if (count % 2) {
        x = x_cords[count / 2];
        y = y_cords[count / 2];
    } else {
        x = (x_cords[count / 2] + x_cords[count / 2 - 1]) / 2;
        y = (y_cords[count / 2] + y_cords[count / 2 - 1]) / 2;
    }

    uint64_t result = 0;
    for (auto& person : people) {
        result += abs(person.first - x) + abs(person.second - y);
    }
    cout << result << endl;

    return 0;
}
