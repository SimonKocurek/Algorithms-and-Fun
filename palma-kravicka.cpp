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

bool valid(const Board& board, const int x, const int y) {
    return x >= 0 && x < board.front().size() &&
           y >= 0 && y < board.size() &&
           board[y][x] != -1;
}

void Fill(Board& board, Point start, Direction direction) {
    int x = start.first;
    int y = start.second;

    board[y][x] = -4;
    x += direction.first;
    y += direction.second;
    
    while (valid(board, x, y)) {
        if (board[y][x] == INT_MIN) {
            board[y][x] = -2;
        } else {
            board[y][x] = 0;
        }

        x += direction.first;
        y += direction.second;
    }
}

Board LoadSetup(int x, int y) {
    Board board(y, vector<int>(x, INT_MAX));
    Point start;

    string s;
    getline(cin, s);

    Direction direction;
    for (int i = 0; i < y; ++i) {
        getline(cin, s);

        for (int j = 0; j < x; ++j) {
            switch (s[j]) {
                case 'X': board[i][j] = -1; break;
                case 'C': board[i][j] = INT_MIN; break;
                case 'H': start = {j, i}; direction = directions[3]; break;
                case 'P': start = {j, i}; direction = directions[0]; break;
                case 'D': start = {j, i}; direction = directions[1]; break;
                case 'L': start = {j, i}; direction = directions[2]; break;
            }
        }
    }

    Fill(board, start, direction);
    return board;
}

void Solve(Board& board) {
    queue<Point> next;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.front().size(); ++j) {
            switch (board[i][j]) {
                case 0: next.push({j, i}); break;
                case -2: cout << 0 << "\n"; return;
            }
        }
    }

    while (!next.empty()) {
        auto current = next.front();
        auto value = board[current.second][current.first] + 1;
        next.pop();

        for (auto& direction : directions) {
            auto x = current.first;
            auto y = current.second;

            while (valid(board, x, y)) {
                if (board[y][x] > value) {
                    board[y][x] = value;
                    next.push({x, y});
                }

                if (board[y][x] == INT_MIN) {
                    cout << value << "\n";
                    return;
                }

                x += direction.first;
                y += direction.second;
            }
        }
    }

    cout << -1 << "\n";
}

int main() {
    int y, x;
    cin >> y >> x;

    auto board = LoadSetup(x, y);
    Solve(board);

    return 0;
}
