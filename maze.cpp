#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<bool>> maze;
typedef pair<int, int> point;

int minimum_steps(maze& board, point& start, point& end) {
}

int main() {
    maze board {
        {false, false, false, false},
            {true, true, false, true},
            {false, false, false, false},
            {false, false, false, false}
    };

    cout << minimum_steps(board, {3, 0}, {0, 0}) << " Expected: 7\n";

    return 0;
}

