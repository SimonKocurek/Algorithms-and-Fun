/*
   This problem was asked by Snapchat.

   Given an array of time intervals (start, end)
   for classroom lectures (possibly overlapping),
   find the minimum number of rooms required.

   For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
 */
#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair

using namespace std;

bool compare(const pii& a, const pii& b) {
    return a.second < b.second;
}

int needed_rooms(vector<pii>& classes) {
    if (classes.size() < 2) {
        return classes.size();
    }

    sort(classes.begin(), classes.end(), compare);

    int max = 0;
    int used = 0;
    int begin = 0;
    for (int i = 0; i < classes.size(); ++i) {
        while (classes[begin].second < classes[i].first) {
            used--;
            begin++;
        }

        used++;
        max = std::max(max, used);
    }

    return max;
}

int main() {
    vector<pii> test {mp(30, 75), mp(0, 50), mp(60, 150)};
    vector<pii> test2 {mp(30, 75)};
    vector<pii> test3;

    cout << needed_rooms(test) << " Expected 2\n";
    cout << needed_rooms(test2) << " Expected 1\n";
    cout << needed_rooms(test3) << " Expected 0\n";

    return 0;
}

