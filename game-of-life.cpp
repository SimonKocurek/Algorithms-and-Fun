/*
   Conway’s Game of Life takes place on an infinite two-dimensional 
   board of square cells. Each cell is either dead or alive, and at 
   each tick, the following rules apply:

   Any live cell with less than two live neighbours dies.
   Any live cell with two or three live neighbours remains living.
   Any live cell with more than three live neighbours dies.
   Any dead cell with exactly three live neighbours becomes a live cell.
   A cell neighbours another cell if it is horizontally, vertically,
   or diagonally adjacent.

   Implement Conway’s Game of Life. It should be able to be initialized
   with a starting list of live cell coordinates and the number of
   steps it should run for. Once initialized, it should print out
   the board state at each step. Since it’s an infinite board, print 
   out only the relevant coordinates, i.e. from the top-leftmost live
   cell to bottom-rightmost live cell.

   You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
 */

#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
};

bool exists(set<set<int>>& points, int x, int y) {
    return points.find(y) != points.end() && 
           points[y].find(x) != points[y].end();
}

point find_dimensions(vector<point>& points) {
    auto& min = points[0];
    auto& max = points[0];

    for (auto& point : points) {

    }

    return {max.x - min.x, max.y - min.y}; 
}

void print(vector<point>& points) {
    cout << "====================\n";

    if (points.empty()) {
        return;       
    }

    auto bounds = find_dimensions(points);
    for (int y = 0; y < bounds.y; ++y) {
        for (int x = 0; x < bounds.x; ++x) {

        }
    }
}

vector<point> step(vector<point> points) {
    vector<point> result;

    return result; 
}

void visualize(vector<point> points, int steps) {
    print(points);
    for (int i = 0; i < steps; ++i) {
        points = step(points);
        print(points);
    }
}

int main() {
    vector<point> points{};

    return 0;
}
