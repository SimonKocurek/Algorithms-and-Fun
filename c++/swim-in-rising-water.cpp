#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

struct point {

    int value, x, y;
    bool visited = false;

    point(int value, int x, int y) : value(value), x(x), y(y) {}

    bool operator<(const point &a) const {
        return value > a.value;
    }
};

struct direction {
    int x_change, y_change;
};

bool valid_point(int x, int y, int max_x, int max_y) {
    return x >= 0 && x < max_x &&
        y >= 0 && y < max_y;
}

int steps_to_end(std::vector<std::vector<point>> &grid) {
    const int max_x = grid[0].size();
    const int max_y = grid.size();

    std::priority_queue<point> queue;
    int result = 0;

    const direction directions[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue.push(grid[0][0]);
    while (!queue.empty()) {
        auto current = queue.top();
        queue.pop();

        result = std::max(result, current.value);

        if (current.x + 1 == max_x && current.y + 1 == max_y) {
            return result;
        }

        for (auto &possible_direction : directions) {
            int new_x = current.x + possible_direction.x_change;
            int new_y = current.y + possible_direction.y_change;

            if (!valid_point(new_x, new_y, max_x, max_y)) {
                continue;
            }

            auto &inserted = grid[new_y][new_x];

            if (inserted.visited) {
                continue;
            }

            inserted.value = std::max(inserted.value, result);

            inserted.visited = true;
            queue.push(inserted);
        }
    }

    return -1;
}


int main() {
    std::vector<std::vector<int>> grid2 {
        {5, 4, 15, 18},
        {6, 8, 12, 14},
        {6, 20, 13, 12},
        {20, 21, 20, 0}};

    std::vector<std::vector<int>> grid {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}};

    std::vector<std::vector<point>> compared(grid.size());
    for (int y = 0; y < compared.size(); ++y) {
        auto &current = compared[y];
        for (int x = 0; x < grid[0].size(); ++x) {
            current.push_back(point(grid[y][x], x, y));
        }
    }

    std::cout << steps_to_end(compared);
    return 0;
}

