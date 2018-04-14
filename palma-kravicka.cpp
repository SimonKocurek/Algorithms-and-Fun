#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;
typedef vector<vector<int>> Board;
typedef pair<int, int> Direction;

const vector<Direction> directions {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0 , -1}
};

struct Setup {
    Board board;
    Direction direction;
    Point start;
    Point end;
};

Setup& LoadSetup(int x, int y) {
    Board board(y, vector<int>(x));
    Point start;
    Point end;

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {

        }
    }
}

void Solve(Setup& setup) {
    priority_queue<Point> next;
    next.push(setup.start);
    for() {

    }

    while (!next.empty()) {

    }

    cout << -1 << "\n";
}

int main() {
    int y, x;
    cin >> y >> x;

    auto& setup = LoadSetup(x, y);
    Solve(setup);

    return 0;
}
