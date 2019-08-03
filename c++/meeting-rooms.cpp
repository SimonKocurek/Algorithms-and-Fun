#include <bits/stdc++.h>

using namespace std;

int main() {
    int count;
    cin >> count;

    vector<pair<int, int>> meetings;
    for (int i = 0; i < count; ++i) {
        int start, end;
        cin >> start >> end;

        meetings.push_back({end, start});
    }

    sort(meetings.begin(), meetings.end());

    int result = 0;

    queue<int> ends;
    for (auto& meeting : meetings) {
        while (!ends.empty() && meeting.second > ends.front()) {
            ends.pop();
        }

        ends.push(meeting.first);
        result = max<int>(result, ends.size());
    }

    cout << result << endl;
    return 0;
}