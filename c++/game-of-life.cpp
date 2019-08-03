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

    inline bool operator<(const point& a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
};

const point directions[8] = {
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1}
};

class board {
    private:
        set<point> points;

        void add(int x, int y) {
            points.insert({x, y});
        }

        void remove(int x, int y) {
            points.erase({x, y});
        }

        int neighbours(int x, int y) {
            int count = 0;

            for (auto& direction : directions) {
                auto new_x = x + direction.x;
                auto new_y = y + direction.y;

                if (points.find({new_x, new_y}) != points.end()) {
                    count++;
                }
            }

            return count;
        }

        void tick() {
            set<point> new_points;

            for (auto& p : points) {
                auto neighbour_count = neighbours(p.x, p.y);
                if (neighbour_count == 2 || neighbour_count == 3) {
                    new_points.insert(p);
                }
            }

            for (auto& p : points) {
                for (auto& direction : directions) {
                    auto neighbour_count = neighbours(p.x + direction.x, p.y + direction.y);
                    if (neighbour_count == 3) {
                        new_points.insert({p.x + direction.x, p.y + direction.y});
                    }
                }
            }

            points = new_points;
        }

        void print() {
            auto min = minimal();
            auto max = maximal();

            for (int y = min.y; y <= max.y; ++y) {
                for (int x = min.x; x <= max.x; ++x) {
                    if (points.find({x, y}) != points.end()) {
                        cout << "* ";
                    } else {
                        cout << ". ";
                    }
                }
                cout << "\n";
            }

            cout << "==========================\n\n";
        }

        point minimal() {
            point min = {INT_MAX, INT_MAX};

            for (auto& p : points) {
                min.x = std::min(min.x, p.x);
                min.y = std::min(min.y, p.y);
            }

            return min;
        }

        point maximal() {
            point max = {INT_MIN, INT_MIN};

            for (auto& p : points) {
                max.x = std::max(max.x, p.x);
                max.y = std::max(max.y, p.y);
            }

            return max;
        }

    public:
        board(vector<point>& data, int ticks) {
            for (auto& inserted_point : data) {
                add(inserted_point.x, inserted_point.y);
            }

            print();
            for (int i = 0; i < ticks; ++i) {
                tick();
                print();
            }
        }
};

int main() {
    vector<point> points {{1,1}, {1,0}, {1, -1}, {0, -1}, {-1, 0}};
    board test(points, 15);

    return 0;
}

