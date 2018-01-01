#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int start;
    int end;
} interval;

inline bool operator<(const interval &a, const interval &b) {
    return a.end < b.end;
}

int main() {
    int sets;
    cin >> sets;
    for (int i = 0; i < sets; ++i) {
        int people;
        cin >> people;

        if (people == 0) {
            cout << "0\n";
            continue;
        }

        interval times[people];
        for (int j = 0; j < people; ++j) {
            int start, end;
            cin >> start >> end;
            times[j] = {start, end};
        }

        sort(times, times + people);

        int result = 1;
        int end = times[0].end;

        for (int k = 1; k < people; ++k) {
            if (times[k].start >= end) {
                result++;
                end = times[k].end;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
