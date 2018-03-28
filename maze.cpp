#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<bool>> maze;
typedef vector<vector<int>> maze_distances;
typedef pair<int, int> point;

const point directions[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool valid(int x, int y, int max_x, int max_y) {
    return x >= 0 && x < max_x &&
        y >= 0 && y < max_y;
}

int minimum_steps(maze& board, point start, point end) {
    if (start == end) {
        return 0;
    }

    maze visited(board.size(), vector<bool>(board[0].size(), false));
    maze_distances distance(board.size(), vector<int>(board[0].size()));

    visited[start.first][start.second] = true;
    distance[start.first][start.second] = 0;

    queue<point> points;
    points.push(start);

    while (!points.empty()) {
        auto current = points.front();
        points.pop();

        auto new_distance = distance[current.first][current.second] + 1;
        for (auto& direction : directions) {
            auto new_y = current.first + direction.first;
            auto new_x = current.second + direction.second;

            if (valid(new_x, new_y, board[0].size(), board.size()) && 
                    !visited[new_y][new_x] && 
                    !board[new_y][new_x]) {
                point new_point = {new_y, new_x};

                if (new_point == end) {
                    return new_distance;
                }

                visited[new_y][new_x] = true;
                distance[new_y][new_x] = new_distance;
                points.push(new_point);
            }
        }
    }

    return -1;
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

