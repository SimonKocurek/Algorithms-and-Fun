#include <bits/stdc++.h>

using namespace std;

struct Festival {
    int start, end, price;

    const bool operator<(const Festival& a) const {
        return end < a.end;
    }
};

vector<Festival> LoadFestivals(const int festival_count) {
    vector<Festival> festivals(festival_count);

    for (auto& festival : festivals) {
        int start, end, price;
        cin >> start >> end >> price;

        festival = {start, end + 1, price};
    }
    
    return festivals;
}

void Solve(vector<Festival>& festivals, const int limit) {
    const auto days = festivals.back().end + 1;
    vector<vector<int>> max_possible(limit + 1, vector<int>(days));

    for (int i = 0; i <= limit; ++i) {
        int j = 0;
        int max = 0;

        for (auto& festival : festivals) {
            for (; j < festival.end; ++j) {
                max_possible[i][j] = max;
            }

            if (i - festival.price >= 0) {
                max = std::max(max, max_possible[i - festival.price][festival.start] + 1);
            }

            max_possible[i][j] = max;            
        }
    }

    cout << max_possible.back().back() << "\n";
}

int main() {
    int festival_count, limit;
    cin >> festival_count >> limit;

    auto festivals = LoadFestivals(festival_count);
    sort(festivals.begin(), festivals.end());
    Solve(festivals, limit);

    return 0;
}
