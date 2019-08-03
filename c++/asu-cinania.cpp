#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    vector<int> size(301, 0);
    for (int i = 0; i < count; ++i) {
        int height;
        cin >> height;

        size[height]++;
    }

    int got = 0;
    for (int i = 0; i < size.size(); ++i) {
        got += size[i];

        if (got >= (count / 2) + 1) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
